//---------------------------------------------------------------------------
#include <string>
#include <fstream>
#include <sstream>
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "GLCtrl"
#pragma resource "*.dfm"

void DrawPolygon(int a, int b, int c, int d);
void DrawColorCube();
void DrawLights();
void DrawAxises();

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

/* Lights */
GLfloat red_light_ambient[] = { 0.3f, 0.0f, 0.0f, 0.0f };
GLfloat red_light_diffuse[] = { 1.0f, 0.0f, 0.0f, 1.0f };
GLfloat red_light_specular[] = { 1.0f, 0.0f, 0.0f, 1.0f };

GLfloat green_light_ambient[] = { 0.0f, 0.3f, 0.0f, 0.0f };
GLfloat green_light_diffuse[] = { 0.0f, 1.0f, 0.0f, 1.0f };
GLfloat green_light_specular[] = { 0.0f, 1.0f, 0.0f, 1.0f };

GLfloat blue_light_ambient[] = { 0.0f, 0.0f, 0.3f, 0.0f };
GLfloat blue_light_diffuse[] = { 0.0f, 0.0f, 1.0f, 1.0f };
GLfloat blue_light_specular[] = { 0.0f, 0.0f, 1.0f, 1.0f };

GLfloat light0_position[] = { 8.0f, 0.0f, 8.0f, 1.0f };
GLfloat light1_position[] = { 4.0f, 8.0f, 4.0f, 1.0f };
GLfloat light2_position[] = { -8.0f, 0.0f, 8.0f, 1.0f };

/* Materials */
GLfloat* selected_material_ambient;
GLfloat* selected_material_diffuse;
GLfloat* selected_material_specular;

GLfloat bronze_ambient[] = { 0.2125f, 0.1275f, 0.054f, 1.0f };
GLfloat bronze_diffuse[] = { 0.714f, 0.4284f, 0.18144f, 1.0f };
GLfloat bronze_specular[] = { 0.393548f, 0.271906f, 0.166721f, 1.0f };

GLfloat silver_ambient[] = { 0.19225f, 0.19225f, 0.19225f, 1.0f };
GLfloat silver_diffuse[] = { 0.50754f, 0.50754f, 0.50754f, 1.0f };
GLfloat silver_specular[] = { 0.508273f, 0.508273f, 0.508273f, 1.0f };

GLfloat gold_ambient[] = { 0.24725, 0.1995f, 0.0745f, 1.0f };
GLfloat gold_diffuse[] = { 0.75164f, 0.60648f, 0.22648f, 1.0f };
GLfloat gold_specular[] = { 0.628281f, 0.555802f, 0.366065f, 1.0f };


static GLfloat theta_x;
static GLfloat theta_y;
static GLfloat theta_z;

static GLfloat trans_x;
static GLfloat trans_y;
static GLfloat trans_z;

static GLfloat scale_x;
static GLfloat scale_y;
static GLfloat scale_z;

static bool lighting_enabled;
static bool red_light_on;
static bool green_light_on;
static bool blue_light_on;

static bool single_viewport;
static GLenum shading_mode;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    theta_x = theta_y = theta_z = 0;
    trans_x = trans_y = trans_z = 0;
    scale_x = scale_y = scale_z = 3;

    lighting_enabled = false;
    red_light_on = true;
    green_light_on = true;
    blue_light_on = true;

    selected_material_ambient = NULL;
    selected_material_diffuse = NULL;
    selected_material_specular = NULL;

    single_viewport = true;
    shading_mode = GL_SMOOTH;
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
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);

    // Handle shading mode.
    glPolygonMode(GL_FRONT, (shading_mode == GL_LINE) ? GL_LINE : GL_FILL);
    glPolygonMode(GL_BACK, GL_LINE);

    if (lighting_enabled) {
        glEnable(GL_LIGHTING);
        glEnable(GL_COLOR_MATERIAL);
    } else {
        glDisable(GL_LIGHTING);
        glDisable(GL_COLOR_MATERIAL);
    }

    if (selected_material_ambient && selected_material_diffuse && selected_material_specular) {
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, selected_material_ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, selected_material_diffuse);        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, selected_material_specular);
    }
    
    glShadeModel(shading_mode);

    // Draw axises.
    if (single_viewport) {
        glViewport(0, 0, GLBox1->Width, GLBox1->Height);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
        gluLookAt(0.5, 0.5, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
        DrawLights();
        DrawAxises();
    } else {
        glViewport(GLBox1->Width / 2, 0, GLBox1->Width / 2, GLBox1->Height / 2);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
        gluLookAt(0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
        DrawLights();
        DrawAxises();

        glViewport(0, 0, GLBox1->Width / 2, GLBox1->Height / 2);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
        gluLookAt(0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
        DrawLights();
        DrawAxises();

        glViewport(0, GLBox1->Height / 2, GLBox1->Width / 2, GLBox1->Height / 2);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
        gluLookAt(0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0);
        DrawLights();
        DrawAxises();

        glViewport(GLBox1->Width / 2, GLBox1->Height / 2, GLBox1->Width / 2, GLBox1->Height / 2);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
        gluLookAt(0.5, 0.5, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
        DrawLights();
        DrawAxises();
    }


    if (single_viewport) {
        glViewport(0, 0, GLBox1->Width, GLBox1->Height);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
        gluLookAt(0.5, 0.5, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

        glTranslatef(trans_x, trans_y, trans_z);
        glRotatef(theta_x, 1, 0, 0);
        glRotatef(theta_y, 0, 1, 0);
        glRotatef(theta_z, 0, 0, 1);
        glScalef(scale_x, scale_y, scale_z);
        DrawColorCube();
    } else {
        glViewport(GLBox1->Width / 2, 0, GLBox1->Width / 2, GLBox1->Height / 2);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
        gluLookAt(0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

        glTranslatef(trans_x, trans_y, trans_z);
        glRotatef(theta_x, 1, 0, 0);
        glRotatef(theta_y, 0, 1, 0);
        glRotatef(theta_z, 0, 0, 1);
        glScalef(scale_x, scale_y, scale_z);
        DrawColorCube();

        glViewport(0, 0, GLBox1->Width / 2, GLBox1->Height / 2);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
        gluLookAt(0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

        glTranslatef(trans_x, trans_y, trans_z);
        glRotatef(theta_x, 1, 0, 0);
        glRotatef(theta_y, 0, 1, 0);
        glRotatef(theta_z, 0, 0, 1);
        glScalef(scale_x, scale_y, scale_z);
        DrawColorCube();

        glViewport(0, GLBox1->Height / 2, GLBox1->Width / 2, GLBox1->Height / 2);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
        gluLookAt(0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0);

        glTranslatef(trans_x, trans_y, trans_z);
        glRotatef(theta_x, 1, 0, 0);
        glRotatef(theta_y, 0, 1, 0);
        glRotatef(theta_z, 0, 0, 1);
        glScalef(scale_x, scale_y, scale_z);
        DrawColorCube();

        glViewport(GLBox1->Width / 2, GLBox1->Height / 2, GLBox1->Width / 2, GLBox1->Height / 2);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
        gluLookAt(0.5, 0.5, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

        glTranslatef(trans_x, trans_y, trans_z);
        glRotatef(theta_x, 1, 0, 0);
        glRotatef(theta_y, 0, 1, 0);
        glRotatef(theta_z, 0, 0, 1);
        glScalef(scale_x, scale_y, scale_z);
        DrawColorCube();
    }
    
    glFlush();
}
//---------------------------------------------------------------------------
void DrawPolygon(int a, int b, int c, int d) {
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

void DrawColorCube() {
    DrawPolygon(0, 3, 2, 1);
    DrawPolygon(2, 3, 7, 6);
    DrawPolygon(0, 4, 7, 3);
    DrawPolygon(1, 2, 6, 5);
    DrawPolygon(4, 5, 6, 7);
    DrawPolygon(0, 1, 5, 4);
}

void DrawLights() {
    GLfloat global_ambient[] = { 0.2f, 0.2f, 0.2f, 0.0f };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

    glLightfv(GL_LIGHT0, GL_AMBIENT, red_light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, red_light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, red_light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

    glLightfv(GL_LIGHT1, GL_AMBIENT, green_light_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, green_light_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, green_light_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);

    glLightfv(GL_LIGHT2, GL_AMBIENT, blue_light_ambient);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, blue_light_diffuse);
    glLightfv(GL_LIGHT2, GL_SPECULAR, blue_light_specular);
    glLightfv(GL_LIGHT2, GL_POSITION, light2_position);

    if (red_light_on) {
        glEnable(GL_LIGHT0);
    } else {
        glDisable(GL_LIGHT0);
    }

    if (green_light_on) {
        glEnable(GL_LIGHT1);
    } else {
        glDisable(GL_LIGHT1);
    }

    if (blue_light_on) {
        glEnable(GL_LIGHT2);
    } else {
        glDisable(GL_LIGHT2);
    }
}

void DrawAxises() {
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

void __fastcall TForm1::RedLightBoxClick(TObject *Sender)
{
    red_light_on = !red_light_on;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::GreenLightBoxClick(TObject *Sender)
{
    green_light_on = !green_light_on;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BlueLightBoxClick(TObject *Sender)
{
    blue_light_on = !blue_light_on;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LineShadingBtnClick(TObject *Sender)
{
    shading_mode = GL_LINE;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FlatShadingBtnClick(TObject *Sender)
{
    shading_mode = GL_FLAT;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SmoothShadingBtnClick(TObject *Sender)
{
    shading_mode = GL_SMOOTH;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SingleViewportBtnClick(TObject *Sender)
{
    single_viewport = true;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FourViewportBtnClick(TObject *Sender)
{
    single_viewport = false;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LightingEnabledBoxClick(TObject *Sender)
{
    lighting_enabled = !lighting_enabled;

    RedLightBox->Enabled = lighting_enabled;
    GreenLightBox->Enabled = lighting_enabled;
    BlueLightBox->Enabled = lighting_enabled;

    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BronzeMaterialBtnClick(TObject *Sender)
{
    selected_material_ambient = bronze_ambient;
    selected_material_diffuse = bronze_diffuse;
    selected_material_specular = bronze_specular;

    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SilverMaterialBtnClick(TObject *Sender)
{
    selected_material_ambient = silver_ambient;
    selected_material_diffuse = silver_diffuse;
    selected_material_specular = silver_specular;

    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::GoldMaterialBtnClick(TObject *Sender)
{
    selected_material_ambient = gold_ambient;
    selected_material_diffuse = gold_diffuse;
    selected_material_specular = gold_specular;

    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OriginalMaterialBtnClick(TObject *Sender)
{
    selected_material_ambient = NULL;
    selected_material_diffuse = NULL;
    selected_material_specular = NULL;

    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OpenModelFileBtnClick(TObject *Sender)
{
    if (OD->Execute()) {
        // what
    }
}
//---------------------------------------------------------------------------

