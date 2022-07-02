#ifndef __BITMAP_H__
#define __BITMAP_H__

using namespace std;

class Pixel {
    public:
        /**
         * @brief Construct a new Pixel object with maximum brightness
         * 
         */
        Pixel();
        /**
         * @brief Construct a new Pixel object with a greyscale value
         * 
         * @param brightness greyscale value between 0-255, inclusive
         */
        Pixel(unsigned int brightness);
        Pixel & operator=(Pixel const & other);
        unsigned int greyscale_;
};

class Image {
    public:
        /**
         * @brief Construct an new empty Image object
         * 
         */
        Image();
        /**
         * @brief Construct a new Image object with given width and height
         * 
         * @param width Width of the new image
         * @param height Height of the new image
         */
        Image(unsigned int width, unsigned int height);
        Image(Image const & other);

        void _copy(Image const & other);

        ~Image();
        /**
         * @brief Get the pointer to a Pixel object at given coordinates
         * 
         * @param x x position
         * @param y y position
         */
        Pixel* get_pixel(unsigned int x, unsigned int y);

    private:
        unsigned int width_;
        unsigned int height_;
        // 2D array of pixels
        Pixel *imageData_;
};

#endif