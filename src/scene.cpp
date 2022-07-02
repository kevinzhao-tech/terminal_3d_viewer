#include "scene.h"
using namespace std;

Object::Object() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Object::Object(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vertex Object::get_centre() {
    return Vertex{this->x, this->y, this->z};
}

void Object::translate(float dx, float dy, float dz) {
    this->x += dx;
    this->y += dy;
    this->z += dz;
}

Solid::Solid(STL stl) {
    this->facets = stl.facets;
    get_centre();
}

Solid::Solid(vector<Facet> facets) {
    this->facets = facets;
    get_centre();
}

Vertex Solid::get_centre() {
    return Object::get_centre();
}

void Solid::translate(float dx, float dy, float dz) {
    this->x += dx;
    this->y += dy;
    this->z += dz;
    float delta[] = {dx, dy, dz};
    for (size_t i = 0; i < facets.size(); ++i) {
        Facet& curr_facet = this->facets[i];
        for (size_t i = 0; i < 3; ++i) {
            curr_facet.normal[i] += delta[i];
        }
        curr_facet.vertex_one.x += dx;
        curr_facet.vertex_one.y += dy;
        curr_facet.vertex_one.z += dz;
        
        curr_facet.vertex_two.x += dx;
        curr_facet.vertex_two.y += dy;
        curr_facet.vertex_two.z += dz;

        curr_facet.vertex_three.x += dx;
        curr_facet.vertex_three.y += dy;
        curr_facet.vertex_three.z += dz;
    }
    // this->get_vertices();
}

// unordered_set<Vertex, Vertex_hash> Solid::get_vertices() {
//     this->vertices.clear();
//     for (size_t i = 0; i < facets.size(); ++i) {
//         Facet curr_facet = facets[i];
//         vertices.insert(curr_facet.vertex_one);
//         vertices.insert(curr_facet.vertex_two);
//         vertices.insert(curr_facet.vertex_three);
//     }
//     return vertices;
// }



Scene::Scene() {
    this->camera = Camera(-10, 0, 0);
    this->light = Light(-15, 10, 0);
}

void Scene::set_camera(Camera camera) {
    this->camera = camera;
}

void Scene::set_light(Light light) {
    this->light = light;
}

void Scene::add_solid(Solid solid) {
    this->solids.push_back(solid);
}