#ifndef CUBE_H
#define CUBE_H

#include <vector>
#include <GL/glut.h>

class Cube {
public:
    Cube();
    virtual ~Cube();
    void Draw();

    std::vector<GLfloat*>& vertices();
    std::vector<GLfloat*>& colors();
private:
    std::vector<GLfloat*> vertices_;
    std::vector<GLfloat*> colors_;
    
    void DrawPolygon(int a, int b, int c, int d); 
};

#endif
