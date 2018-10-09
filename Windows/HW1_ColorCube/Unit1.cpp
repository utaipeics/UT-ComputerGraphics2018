//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "GLCtrl"
#pragma resource "*.dfm"

void drawPolygon(int a, int b, int c, int d);
void drawColorCube();

TForm1 *Form1;

/* Cube vertices */
GLfloat vertices[][3] = {
    {-1.0, -1.0, -1.0}, {1.0, -1.0, -1.0},
    {1.0, 1.0, -1.0}, {-1.0, 1.0, -1.0}, {-1.0, -1.0, 1.0},
    {1.0, -1.0, 1.0}, {1.0, 1.0, 1.0}, {-1.0, 1.0, 1.0}
};

/* Cube surface colors */
GLfloat colors[][3] = {
    {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, 
    {1.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}, 
    {1.0, 0.0, 1.0}, {1.0, 1.0, 1.0}, {0.0, 1.0, 1.0}
};
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{

}


//---------------------------------------------------------------------------
void __fastcall TForm1::init(TObject *Sender)
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1, 0.1, 0.1, 1.0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::draw(TObject *Sender)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawColorCube();
    glFlush();
}
//---------------------------------------------------------------------------
void drawPolygon(int a, int b, int c, int d) {
    glBegin(GL_POLYGON);
    glColor3fv(colors[a]);
    glVertex3fv(vertices[a]);
    glColor3fv(colors[b]);
    glVertex3fv(vertices[b]);
    glColor3fv(colors[c]);
    glVertex3fv(vertices[c]);
    glColor3fv(colors[d]);
    glVertex3fv(vertices[d]);
    glEnd();
}

void drawColorCube() {
    drawPolygon(0, 3, 2, 1);
    drawPolygon(2, 3, 7, 6);
    drawPolygon(0, 4, 7, 3);
    drawPolygon(1, 2, 6, 5);
    drawPolygon(4, 5, 6, 7);
    drawPolygon(0, 1, 5, 4);
}
