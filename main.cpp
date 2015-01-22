#include <iostream>
#include <cmath>
#include <GL/glut.h>
#include "World.h"
using namespace std;
int main(int argc, char **argv) {
    World mine(1024,700);
    mine.add_board();
//    mine.add_coin();
//    mine.debug_objects();
    mine.start(argc, argv);
    return 0;
}
