#ifndef __SCENE_H__
#define __SCENE_H__

#include "file_io.h"
#include <vector>
#include <unordered_set>

using namespace std;

class Object {
    public:
        Object();
        Object(float x, float y, float z);
        float x;
        float y;
        float z;

        /**
         * @brief Returns the centre position of the Object
         * 
         * @retruns Vertex of the centre point
         * 
         */
        Vertex get_centre();

        /**
         * @brief translate the solid
         * 
         * @param dx delta x
         * @param dy delta y
         * @param dz delta z
         */
        void virtual translate(float dx, float dy, float dz);
};

class Solid : Object {
    public:
        Solid();
        Solid(STL stl);
        Solid(vector<Facet> facets);

        Vertex get_centre();

        void translate(float dx, float dy, float dz) override;

        /**
         * @brief Calculates, sets and returns the vertices of the solid
         * 
         * @return unordered_set<Vertex, Vertex_hash> 
         */
        unordered_set<Vertex, Vertex_hash> get_vertices();
        vector<Facet> facets;
        unordered_set<Vertex, Vertex_hash> vertices;
};

class Light : Object {
    using Object::Object;
};

class Camera : Object {
    using Object::Object;
};

class Scene {
    public:
        Scene();
        Light light;
        Camera camera;
        vector<Solid> solids;
        void set_camera(Camera);
        void set_light(Light);
        void add_solid(Solid);
};

#endif