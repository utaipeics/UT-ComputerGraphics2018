#include <iostream>
#include <GL/glut.h>
#include "display.hpp"

Display::Display(int width, int height, const std::string& title) {
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(title.c_str());
}

Display::~Display() {
    
}


int Display::width() const {
    return width_;
}

int Display::height() const {
    return height_;
}

std::string Display::title() const {
    return title_;
}
