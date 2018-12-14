//---------------------------------------------------------------------------
#include <string>
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "GLCtrl"
#pragma resource "*.dfm"

void DrawAxises();

TForm1* Form1;
GLUquadric* Obj;

const double SunRotateFactor = 360.0 / 26.9;
const double MercuryRevolveFactor = 360.0 / 87.97;
const double MercuryRotateFactor = 360.0 / 58.6;
const double VenusRevolveFactor = 360.0 / 224.7;
const double VenusRotateFactor = 360.0 / 243.01;
const double EarthRevolveFactor = 360.0 / 365.26;
const double MarsRevolveFactor = 360.0 / 686.98;
const double MarsRotateFactor = 360.0 / 1.026;

double SunRotate;
Planet* Mercury;
Planet* Venus;
Planet* Earth;
Planet* Mars;


Planet::Planet(const double revolve_factor, const double rotate_factor)
: kRevolveFactor(revolve_factor), kRotateFactor(rotate_factor)
{
    r_ = g_ = b_ = 0.0;
    axial_tilt_ = 0.0;
    diameter_ = 0.0;
    distance_ = 0.0;

    revolve_ = 0.0;
    rotate_ = 0.0;
}

void Planet::SetColor(const float r, const float g, const float b)
{
    r_ = r;
    g_ = g;
    b_ = b;
}

void Planet::SetAxialTilt(const float axial_tilt)
{
    axial_tilt_ = axial_tilt;
}

void Planet::SetDiameter(const float diameter)
{
    diameter_ = diameter;
}

void Planet::SetDistance(const float distance)
{
    distance_ = distance;
}

double Planet::rotate()
{
    return rotate_;
}

double Planet::set_rotate(const float rotate)
{
    rotate_ = rotate;
}

void Planet::Update()
{
    revolve_ += kRevolveFactor;
    rotate_ += kRotateFactor;
}

void Planet::Draw(GLenum style)
{
    // Render the planet itself.
    glLoadIdentity();
    glOrtho(-25.0, 25.0, -25.0, 25.0, -25.0, 25.0);
    gluLookAt(0.5, 0.5, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    gluQuadricDrawStyle(Obj, style);
    glColor3f(r_, g_, b_);
    glRotatef(revolve_, 0.0, 1.0, 0.0);
    glTranslatef(distance_, 0.0, 0.0);
    glRotatef(axial_tilt_, 1.0, 0.0, 0.0);
    glRotatef(rotate_, 0.0, 1.0, 0.0);
    gluSphere(Obj, diameter_, 36, 12);

    // Render the track.
    glLoadIdentity();
    glOrtho(-25.0, 25.0, -25.0, 25.0, -25.0, 25.0);
    gluLookAt(0.5, 0.5, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    gluQuadricDrawStyle(Obj, GLU_LINE);
    glColor3f(1.0, 1.0, 1.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    gluDisk(Obj, distance_, distance_, 500, 1);
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    Obj = gluNewQuadric();
    SunRotate = 0.0;

    Mercury = new Planet(MercuryRevolveFactor, MercuryRotateFactor);
    Mercury->SetColor(0.94, 0.74, 0.54);
    Mercury->SetAxialTilt(52.92);
    Mercury->SetDiameter(0.4868);
    Mercury->SetDistance(5.8);

    Venus = new Planet(VenusRevolveFactor, VenusRotateFactor);
    Venus->SetColor(1.0, 1.0, 1.0);
    Venus->SetAxialTilt(52.92);
    Venus->SetDiameter(1.2103);
    Venus->SetDistance(10.76);

    Earth = new Planet(EarthRevolveFactor, 0);
    Earth->SetColor(0.5, 0.5, 0.95);
    Earth->SetAxialTilt(86.94);
    Earth->SetDiameter(1.2742);
    Earth->SetDistance(14.96);

    Mars = new Planet(MarsRevolveFactor, MarsRotateFactor);
    Mars->SetColor(1.0, 0.1, 0.1);
    Mars->SetAxialTilt(73.26);
    Mars->SetDiameter(0.6794);
    Mars->SetDistance(22.794);
}


//---------------------------------------------------------------------------
void __fastcall TForm1::init(TObject *Sender)
{
    glEnable(GL_DEPTH_TEST);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::draw(TObject *Sender)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.1, 0.1, 0.1, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(-25.0, 25.0, -25.0, 25.0, -25.0, 25.0);
    gluLookAt(0.5, 0.5, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    DrawAxises();

    // Render the Sun.
    glLoadIdentity();
    glOrtho(-25.0, 25.0, -25.0, 25.0, -25.0, 25.0);
    gluLookAt(0.5, 0.5, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    gluQuadricDrawStyle(Obj, GLU_FILL);
    gluQuadricTexture(Obj, GL_TRUE);
    glColor3f(1.0, 0.04, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    gluSphere(Obj, 1.392, 36, 12);

    // Render the planets.
    Mercury->Draw(GLU_FILL);
    Venus->Draw(GLU_FILL);
    Earth->Draw(GLU_LINE);
    Mars->Draw(GLU_FILL);

    glFlush();
}

void DrawAxises() {
    glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(25, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 25, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 25);
    glEnd();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    double earth_rotate = Earth->rotate();
    Earth->set_rotate((int) (earth_rotate + 60) % 360);

    if (Earth->rotate() == 0) {
        SunRotate += SunRotateFactor;
        Mercury->Update();
        Venus->Update();
        Earth->Update();
        Mars->Update();
    }

    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
    delete Mercury;
    delete Venus;
    delete Earth;
    delete Mars;
    
    gluDeleteQuadric(Obj);
}

