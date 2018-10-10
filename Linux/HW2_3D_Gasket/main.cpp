#include <iostream>
#include <string>
#include <GL/glut.h>

#include "display.hpp"
#include "cube.hpp"

using std::cout;
using std::endl;
using std::string;

static const int WINDOW_WIDTH = 500;
static const int WINDOW_HEIGHT = 500;
static const string WINDOW_TITLE = "3D Gasket";
Cube* cube;

void draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.1, 0.1, 0.1, 1.0);
    cube->Draw();
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glEnable(GL_DEPTH_TEST);
    Display display(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    cube = new Cube();
    
    cube->vertices().push_back(new GLfloat[3] {-1.0, 1.0, -1.0});
    cube->vertices().push_back(new GLfloat[3] {1.0, 1.0, -1.0});
    cube->vertices().push_back(new GLfloat[3] {-1.0, 1.0, 1.0});
    cube->vertices().push_back(new GLfloat[3] {1.0, 1.0, 1.0});
    cube->vertices().push_back(new GLfloat[3] {-1.0, -1.0, -1.0});
    cube->vertices().push_back(new GLfloat[3] {1.0, -1.0, -1.0});
    cube->vertices().push_back(new GLfloat[3] {-1.0, -1.0, 1.0});
    cube->vertices().push_back(new GLfloat[3] {1.0, -1.0, 1.0});

    cube->colors().push_back(new GLfloat[3] {0.0, 1.0, 0.0});
    cube->colors().push_back(new GLfloat[3] {1.0, 1.0, 0.0});
    cube->colors().push_back(new GLfloat[3] {0.0, 1.0, 1.0});
    cube->colors().push_back(new GLfloat[3] {1.0, 1.0, 1.0});
    cube->colors().push_back(new GLfloat[3] {0.0, 0.0, 0.0});
    cube->colors().push_back(new GLfloat[3] {1.0, 0.0, 0.0});
    cube->colors().push_back(new GLfloat[3] {0.0, 0.0, 1.0});
    cube->colors().push_back(new GLfloat[3] {1.0, 0.0, 1.0});

    glutDisplayFunc(draw);
    glutMainLoop();

    delete cube;
}
