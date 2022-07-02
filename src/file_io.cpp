#include "file_io.h"

STL::STL(char* file) {
    STL::filename_ = file;
    STL::_readSTL();
}

STL::STL(const STL& other) {
    this->filename_ = other.filename_;
    this->facet_count_ = other.facet_count_;
    this->facets = vector<Facet>(other.facets);
}

STL::~STL() {}


void STL::_readSTL() {
    ifstream file_;
    file_.open(filename_, ios::in | ios::binary);
    if (file_.is_open()) {
        // traverse 80 byte header
        file_.seekg(80, ios::beg);
        // get facet count
        file_.read((char *) (&facet_count_), 4);

        // read facets
        for (size_t i = 0; i < facet_count_; ++i) {
            Facet curr_facet;
            // normal
            file_.read((char *) &curr_facet.normal, 3 * sizeof(_Float32));
            // vertex one
            file_.read((char *) &curr_facet.vertex_one, 3 * sizeof(_Float32));
            // vertex two
            file_.read((char *) &curr_facet.vertex_two, 3 * sizeof(_Float32));
            // vertex three
            file_.read((char *) &curr_facet.vertex_three, 3 * sizeof(_Float32));
            // ignore attribute byte
            file_.seekg(2, ios::cur);
            facets.push_back(curr_facet);
        }
        file_.close();
    }
}
