#include "file_io.h"

STL::STL(char* file) {
    STL::filename = file;
    STL::_readSTL();
}

STL::~STL() {
    
}

void STL::_readSTL() {
    file.open(filename, ios::in | ios::binary);
    if (file.is_open()) {
        // traverse 80 byte header
        file.seekg(80, ios::beg);
        // get facet count
        file.read((char *) (&facet_count), 4);

        // read facets
        for (size_t i = 0; i < facet_count; ++i) {
            Facet curr_facet;
            // normal
            file.read((char *) &curr_facet.normal, 3 * sizeof(_Float32));
            // vertex one
            file.read((char *) &curr_facet.vertex_one, 3 * sizeof(_Float32));
            // vertex two
            file.read((char *) &curr_facet.vertex_two, 3 * sizeof(_Float32));
            // vertex three
            file.read((char *) &curr_facet.vertex_three, 3 * sizeof(_Float32));
            // ignore attribute byte
            file.seekg(2, ios::cur);
            facets.push_back(curr_facet);
        }

        STL::file.close();
    }
}

int main(int argc, char *argv[]) {
    STL test(argv[1]);
}