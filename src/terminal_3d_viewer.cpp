#include "ascii.h"
#include "bitmap.h"
#include "file_io.h"
#include "scene.h"

using namespace std;

int main(int argc, char *argv[]) {
    STL sphericon(argv[1]);
    Solid sphericon_solid(sphericon);
    sphericon_solid.translate(10, 10, 10);
    cout << "x: " << sphericon_solid.get_centre().x << endl;
    cout << "y: " << sphericon_solid.get_centre().y << endl;
    cout << "z: " << sphericon_solid.get_centre().z << endl;
}