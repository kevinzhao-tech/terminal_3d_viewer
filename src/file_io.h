#ifndef __FILE_IO_H__
#define __FILE_IO_H__
#endif

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Facet
{
    float normal[3];
    float vertex_one[3];
    float vertex_two[3];
    float vertex_three[3];
};

class STL {
    public:
        STL(char*);
        ~STL();
        std::vector<Facet> facets;
    private:
        ifstream file;
        char* filename;
        int facet_count;
        void _readSTL();
};

