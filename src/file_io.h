#ifndef __FILE_IO_H__
#define __FILE_IO_H__

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


struct Vertex
{
    float x;
    float y;
    float z;
};

struct Vertex_hash {
    size_t operator()(const Vertex& other) const {
            return hash<float>()(other.x) ^ hash<float>()(other.y) ^ hash<float>()(other.z);
    }
};

struct Facet
{
    float normal[3];
    Vertex vertex_one;
    Vertex vertex_two;
    Vertex vertex_three;
};

class STL {
    public:
        STL();
        STL(char*);
        STL(const STL& other);
        ~STL();
        std::vector<Facet> facets;
    private:
        string filename_;
        unsigned int facet_count_;
        void _readSTL();
};

#endif