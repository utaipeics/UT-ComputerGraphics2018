//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "GLCtrl"
#pragma resource "*.dfm"

typedef GLfloat point[3];

TForm1 *Form1;

point v[] = {{0.0, 0.0, 1.0}, {0.0, 0.942809, -0.33333}, 
    {-0.816497, -0.471405, -0.333333}, {0.816497, -0.471405, -0.333333}};

static const int FPS = 60;
static int n;
static bool reversing;

void triangle(point a, point b, point c) {
    glVertex3fv(a);
    glVertex3fv(b);
    glVertex3fv(c);
}

void tetrahedron(point a, point b, point c, point d) {
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    triangle(a, b, c);
    glColor3f(0.0, 0.0, 1.0);
    triangle(a, d, b);
    glColor3f(1.0, 1.0, 1.0);
    triangle(b, d, c);
    glColor3f(0.0, 1.0, 0.0);
    triangle(a, c, d);
    glEnd();
}

/*
 * Triangle subdivision using vertex numbers.
 * Righthand rule applied to create outward pointing faces.
 */
void divide_tetra(point a, point b, point c, point d, int m) {
    point mid[6];

    if (m > 0) {
        // Compute six midpoints.
        for (int i = 0; i < 3; i++) mid[0][i] = (a[i] + b[i]) / 2;
        for (int i = 0; i < 3; i++) mid[1][i] = (a[i] + c[i]) / 2;
        for (int i = 0; i < 3; i++) mid[2][i] = (a[i] + d[i]) / 2;
        for (int i = 0; i < 3; i++) mid[3][i] = (b[i] + c[i]) / 2;
        for (int i = 0; i < 3; i++) mid[4][i] = (c[i] + d[i]) / 2;
        for (int i = 0; i < 3; i++) mid[5][i] = (b[i] + d[i]) / 2;
        
        // Create 4 tetrahedrons by subdivision.
        divide_tetra(a, mid[0], mid[1], mid[2], m - 1);
        divide_tetra(mid[0], b, mid[3], mid[5], m - 1);
        divide_tetra(mid[1], mid[3], c, mid[4], m - 1);
        divide_tetra(mid[2], mid[5], mid[4], d, m - 1);
    } else {
        // Draw triangle at the end of recursion.
        tetrahedron(a, b, c, d);
    }
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Init(TObject *Sender)
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1, 0.1, 0.1, 1.0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Draw(TObject *Sender)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.1, 0.1, 0.1, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);

    divide_tetra(v[0], v[1], v[2], v[3], n);
    glFlush();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::UpdateTetra(TObject *Sender)
{
    if (n > 0 && n < 6) {
        if (!reversing) {
            n++;
        } else {
            n--;
        }
    } else if (n == 0) {
        reversing = false;
        n++;
    } else if (n == 6) {
        reversing = true;
        n--;
    }

    GLBox1->Refresh();
}
//---------------------------------------------------------------------------
