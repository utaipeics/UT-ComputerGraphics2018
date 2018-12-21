//---------------------------------------------------------------------------
#include <string>
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "GLCtrl"
#pragma resource "*.dfm"

void drawPolygon(int a, int b, int c, int d);
void drawColorCube();
void drawAxises();

TForm1 *Form1;

/* Cube's data */
GLfloat vertices[][3] = {
    {-1.0, -1.0, -1.0}, {1.0, -1.0, -1.0},
    {1.0, 1.0, -1.0}, {-1.0, 1.0, -1.0}, {-1.0, -1.0, 1.0},
    {1.0, -1.0, 1.0}, {1.0, 1.0, 1.0}, {-1.0, 1.0, 1.0}
};

GLfloat colors[][3] = {
    {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0},
    {1.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0},
    {1.0, 0.0, 1.0}, {1.0, 1.0, 1.0}, {0.0, 1.0, 1.0}
};

static GLfloat theta_x;
static GLfloat theta_y;
static GLfloat theta_z;

static GLfloat trans_x;
static GLfloat trans_y;
static GLfloat trans_z;

static GLfloat scale_x;
static GLfloat scale_y;
static GLfloat scale_z;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{

}


//---------------------------------------------------------------------------
void __fastcall TForm1::init(TObject *Sender)
{
    glEnable(GL_DEPTH_TEST);

    theta_x = 0;
    theta_y = 0;
    theta_z = 0;

    trans_x = 0;
    trans_y = 0;
    trans_z = 0;

    scale_x = 1;
    scale_y = 1;
    scale_z = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::draw(TObject *Sender)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.1, 0.1, 0.1, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
    gluLookAt(0.5, 0.5, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Handle object rotation.
    // Make sure we rotate the object at (0, 0, 0).
    // Otherwise, it will revolve around (0, 0, 0).
    glTranslatef(trans_x, trans_y, trans_z);
    glRotatef(theta_x, 1, 0, 0);
    glRotatef(theta_y, 0, 1, 0);
    glRotatef(theta_z, 0, 0, 1);
    glScalef(scale_x, scale_y, scale_z);
    drawColorCube();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
    gluLookAt(0.5, 0.5, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    drawAxises();

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

void drawAxises() {
    glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(10, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 10, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 10);
    glEnd();
}

//---------------------------------------------------------------------------
void __fastcall TForm1::RotationXScrollBarChange(TObject *Sender)
{
    theta_x = RotationXScrollBar->Position;
    RotationXValueLabel->Caption = (int) theta_x;
    GLBox1->Invalidate();
}

void __fastcall TForm1::RotationYScrollBarChange(TObject *Sender)
{
    theta_y = RotationYScrollBar->Position;
    RotationYValueLabel->Caption = (int) theta_y;
    GLBox1->Invalidate();
}

void __fastcall TForm1::RotationZScrollBarChange(TObject *Sender)
{
    theta_z = RotationZScrollBar->Position;
    RotationZValueLabel->Caption = (int) theta_z;
    GLBox1->Invalidate();
}

void __fastcall TForm1::ResetRotationBtnClick(TObject *Sender)
{
    theta_x = 0;
    theta_y = 0;
    theta_z = 0;
    RotationXScrollBar->Position = 0;
    RotationYScrollBar->Position = 0;
    RotationZScrollBar->Position = 0;
    RotationXValueLabel->Caption = 0;
    RotationYValueLabel->Caption = 0;
    RotationZValueLabel->Caption = 0;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TranslationXScrollBarChange(TObject *Sender)
{
    trans_x = TranslationXScrollBar->Position;
    TranslationXValueLabel->Caption = (int) trans_x;
    GLBox1->Invalidate();
}

void __fastcall TForm1::TranslationYScrollBarChange(TObject *Sender)
{
    trans_y = TranslationYScrollBar->Position;
    TranslationYValueLabel->Caption = (int) trans_y;
    GLBox1->Invalidate();
}

void __fastcall TForm1::TranslationZScrollBarChange(TObject *Sender)
{
    trans_z = TranslationZScrollBar->Position;
    TranslationZValueLabel->Caption = (int) trans_z;
    GLBox1->Invalidate();
}

void __fastcall TForm1::ResetTranslationBtnClick(TObject *Sender)
{
    trans_x = 0;
    trans_y = 0;
    trans_z = 0;
    TranslationXScrollBar->Position = 0;
    TranslationYScrollBar->Position = 0;
    TranslationZScrollBar->Position = 0;
    TranslationXValueLabel->Caption = 0;
    TranslationYValueLabel->Caption = 0;
    TranslationZValueLabel->Caption = 0;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ScalingXScrollBarChange(TObject *Sender)
{
    scale_x = ScalingXScrollBar->Position;
    ScalingXValueLabel->Caption = (int) scale_x;
    GLBox1->Invalidate();
}

void __fastcall TForm1::ScalingYScrollBarChange(TObject *Sender)
{
    scale_y = ScalingYScrollBar->Position;
    ScalingYValueLabel->Caption = (int) scale_y;
    GLBox1->Invalidate();
}

void __fastcall TForm1::ScalingZScrollBarChange(TObject *Sender)
{
    scale_z = ScalingZScrollBar->Position;
    ScalingZValueLabel->Caption = (int) scale_z;
    GLBox1->Invalidate();
}

void __fastcall TForm1::ResetScalingBtnClick(TObject *Sender)
{
    scale_x = 1;
    scale_y = 1;
    scale_z = 1;
    ScalingXScrollBar->Position = 1;
    ScalingYScrollBar->Position = 1;
    ScalingZScrollBar->Position = 1;
    ScalingXValueLabel->Caption = 1;
    ScalingYValueLabel->Caption = 1;
    ScalingZValueLabel->Caption = 1;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SetRotation(int new_theta_x, int new_theta_y, int new_theta_z)
{
    theta_x = new_theta_x;
    theta_y = new_theta_y;
    theta_z = new_theta_z;

    RotationXScrollBar->Position = new_theta_x;
    RotationYScrollBar->Position = new_theta_y;
    RotationZScrollBar->Position = new_theta_z;

    RotationXValueLabel->Caption = (int) new_theta_x;
    RotationYValueLabel->Caption = (int) new_theta_y;
    RotationZValueLabel->Caption = (int) new_theta_z;

    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Iso1BtnClick(TObject *Sender)
{
    SetRotation(0, 0, 0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::IsoBtn2Click(TObject *Sender)
{
    SetRotation(0, -90, 0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Iso3BtnClick(TObject *Sender)
{
    SetRotation(0, -180, 0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Iso4BtnClick(TObject *Sender)
{
    SetRotation(0, 90, 0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Iso8BtnClick(TObject *Sender)
{
    SetRotation(0, 0, 180);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Iso5BtnClick(TObject *Sender)
{
    SetRotation(0, 90, 180);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Iso6BtnClick(TObject *Sender)
{
    SetRotation(0, 180, 180);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Iso7BtnClick(TObject *Sender)
{
    SetRotation(0, -90, 180);
}
//---------------------------------------------------------------------------

