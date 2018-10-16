#ifndef CUBE_H
#define CUBE_H

#include <vector>
#include <GL/glut.h>

class Cube {
public:
    Cube();
    virtual ~Cube();
    std::vector<GLfloat*>& vertices();
    std::vector<GLfloat*>& colors();
    float theta_x();
    float theta_y();
    float theta_z();
    
    void RotateX(float theta_x);
    void RotateY(float theta_y);
    void RotateZ(float theta_z);
    void Draw();
private:
    std::vector<GLfloat*> vertices_;
    std::vector<GLfloat*> colors_;
    float theta_x_;
    float theta_y_;
    float theta_z_;
    
    void DrawPolygon(int a, int b, int c, int d); 
};

#endif
