#include "bitmap.h"
#include <cassert>
#include <iostream>
using namespace std;

Pixel::Pixel() {
    greyscale_ = 255;
}



Pixel::Pixel(unsigned int brightness) {
    if (brightness > 255) {
        cerr << "ERROR: Call to Pixel::Pixel(" << brightness << ") is outside of brightness range of 255, truncating to 255" << endl;
        brightness = 255;
    }
    greyscale_ = brightness;
}

Pixel & Pixel::operator=(Pixel const & other) {
    this->greyscale_ = other.greyscale_;
    return *this;
}

Image::Image() {
    width_ = 0;
    height_ = 0;
    imageData_ = new Pixel;
}

Image::Image(unsigned int width, unsigned int height) {
    width_ = width;
    height_ = height;
    imageData_ = new Pixel[width * height];
}

Image::Image(const Image & other) {
    imageData_ = nullptr;
    _copy(other);
}

Image::~Image() {
    delete[] imageData_;
}

void Image::_copy(const Image & other) {
    // Clear self
    delete[] imageData_;

    // copy
    width_ = other.width_;
    height_ = other.height_;
    imageData_ = new Pixel[width_ * height_];
    for (unsigned i = 0; i < width_ * height_; ++i) {
        imageData_[i] = other.imageData_[i];
    }
}

Pixel* Image::get_pixel(unsigned int x, unsigned int y) {
    assert(x < width_);
    assert(y < height_);
    unsigned index = x + (y * width_);
    return imageData_ + index;
}
