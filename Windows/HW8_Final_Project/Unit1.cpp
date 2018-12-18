//---------------------------------------------------------------------------
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "GLCtrl"
#pragma resource "*.dfm"

using std::string;
using std::vector;
using std::stringstream;

void RenderObject(int viewport_x, int viewport_y, int viewport_width, int viewport_height,
        GLfloat ortho_size, GLfloat cam_x, GLfloat cam_y, GLfloat cam_z,
        GLfloat cam_nx, GLfloat cam_ny, GLfloat cam_nz);
        
void DrawTriangle(GLfloat* vertex1, GLfloat* vertex2, GLfloat* vertex3,
        GLfloat* normal1, GLfloat* normal2, GLfloat* normal3,
        GLfloat* front_color, GLfloat* back_color);

void DrawPolygon(int a, int b, int c, int d);
void DrawColorCube();
void DrawCustomModel();
void DrawLights();
void DrawAxises();
GLfloat Max(GLfloat v1, GLfloat v2, GLfloat v3);

vector<string> Split(const string& s, const char delimiter);

/* Cube's data */
GLfloat vertices[][3] = {
    {-1.0, -1.0, -1.0}, {1.0, -1.0, -1.0},
    {1.0, 1.0, -1.0}, {-1.0, 1.0, -1.0}, {-1.0, -1.0, 1.0},
    {1.0, -1.0, 1.0}, {1.0, 1.0, 1.0}, {-1.0, 1.0, 1.0}
};

GLfloat normals[][3] = {
    {-1.0, -1.0, -1.0}, {1.0, -1.0, -1.0}, {1.0, 1.0, -1.0},
    {-1.0, 1.0, -1.0}, {-1.0, 1.0, -1.0}, {-1.0, -1.0, 1.0},
    {1.0, -1.0, 1.0}, {1.0, 1.0, 1.0}, {-1.0, 1.0, 1.0}
};

GLfloat colors[][3] = {
    {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0},
    {1.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0},
    {1.0, 0.0, 1.0}, {1.0, 1.0, 1.0}, {0.0, 1.0, 1.0}
};

/* Loaded model's data */
struct Vertex {
    GLfloat x, y, z;
    GLfloat nx, ny, nz;
};

struct Triangle {
    int vertex1, vertex2, vertex3; // Vertices ref ids.
    int fr, fg, fb, br, bg, bb;    // front-rgb and back-rgb.
};

Triangle* model_triangles;
Vertex* model_vertices;

int simple_triangles_count;
int colored_triangles_count;
int vertices_count;

GLfloat calibration_offset_x, calibration_offset_y, calibration_offset_z;

/* Lights */
GLfloat red_light_ambient[] = { 0.2f, 0.0f, 0.0f, 0.0f };
GLfloat red_light_diffuse[] = { 0.9f, 0.0f, 0.0f, 1.0f };
GLfloat red_light_specular[] = { 0.9f, 0.0f, 0.0f, 1.0f };

GLfloat green_light_ambient[] = { 0.0f, 0.2f, 0.0f, 0.0f };
GLfloat green_light_diffuse[] = { 0.0f, 0.9f, 0.0f, 1.0f };
GLfloat green_light_specular[] = { 0.0f, 0.9f, 0.0f, 1.0f };

GLfloat blue_light_ambient[] = { 0.0f, 0.0f, 0.2f, 0.0f };
GLfloat blue_light_diffuse[] = { 0.0f, 0.0f, 0.9f, 1.0f };
GLfloat blue_light_specular[] = { 0.0f, 0.0f, 0.9f, 1.0f };

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


TForm1 *Form1;
GLfloat world_size;
GLfloat cam_dist;
GLfloat theta_x, theta_y, theta_z;
GLfloat trans_x, trans_y, trans_z;
GLfloat scale_x, scale_y, scale_z;
GLenum shading_mode;
bool lighting_enabled;
bool red_light_on, green_light_on, blue_light_on;
bool single_viewport;
bool obj_is_custom_model;
bool not_freed;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner) {
    simple_triangles_count = 0;
    colored_triangles_count = 0;
    vertices_count = 0;

    world_size = 3.0f;
    cam_dist = 0.5f;

    calibration_offset_x = calibration_offset_y = calibration_offset_z = 0;

    theta_x = theta_y = theta_z = 0;
    trans_x = trans_y = trans_z = 0;
    scale_x = scale_y = scale_z = 1;

    shading_mode = GL_SMOOTH;
    
    selected_material_ambient = NULL;
    selected_material_diffuse = NULL;
    selected_material_specular = NULL;

    lighting_enabled = false;
    red_light_on = true;
    green_light_on = true;
    blue_light_on = true;

    single_viewport = true;
    obj_is_custom_model = false;
    not_freed = false;
}


//---------------------------------------------------------------------------
void __fastcall TForm1::init(TObject *Sender) {
    glEnable(GL_DEPTH_TEST);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::draw(TObject *Sender) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.1, 0.1, 0.1, 1.0);

    // Shading
    glPolygonMode(GL_FRONT, (shading_mode == GL_LINE) ? GL_LINE : GL_FILL);
    glPolygonMode(GL_BACK, (shading_mode == GL_LINE) ? GL_LINE : GL_FILL);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
    glShadeModel(shading_mode);

    // Lighting
    if (lighting_enabled) {
        glEnable(GL_LIGHTING);
        glEnable(GL_COLOR_MATERIAL);
    } else {
        glDisable(GL_LIGHTING);
        glDisable(GL_COLOR_MATERIAL);
    }

    // Material
    if (selected_material_ambient && selected_material_diffuse && selected_material_specular) {
        glMaterialfv(GL_FRONT, GL_AMBIENT, selected_material_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, selected_material_diffuse);        glMaterialfv(GL_FRONT, GL_SPECULAR, selected_material_specular);
    }

    // Render object(s)
    if (single_viewport) {
        // Render only one viewport, which fills the entire GLBox.
        RenderObject(0, 0, GLBox1->Width, GLBox1->Height,
                world_size, cam_dist, cam_dist, cam_dist, 0.0, 1.0, 0.0);
    } else {
        // Render object within bottom-right viewport.
        RenderObject(GLBox1->Width / 2, 0, GLBox1->Width / 2, GLBox1->Height / 2,
                world_size, cam_dist, 0.0, 0.0, 0.0, 1.0, 0.0);

        // Render object within bottom-left viewport.
        RenderObject(0, 0, GLBox1->Width / 2, GLBox1->Height / 2,
                world_size, 0.0, 0.0, cam_dist, 0.0, 1.0, 0.0);

        // Render object within top-left viewport.
        RenderObject(0, GLBox1->Height / 2, GLBox1->Width / 2, GLBox1->Height / 2,
                world_size, 0.0, cam_dist, 0.0, 1.0, 0.0, 0.0);

        // Render object within top-right viewport.
        RenderObject(GLBox1->Width / 2, GLBox1->Height / 2, GLBox1->Width / 2, GLBox1->Height / 2,
                world_size, cam_dist, cam_dist, cam_dist, 0.0, 1.0, 0.0);
    }
    
    glFlush();
}
//---------------------------------------------------------------------------
void RenderObject(int viewport_x, int viewport_y, int viewport_width, int viewport_height,
        GLfloat ortho_size, GLfloat cam_x, GLfloat cam_y, GLfloat cam_z,
        GLfloat cam_nx, GLfloat cam_ny, GLfloat cam_nz) {

    glViewport(viewport_x, viewport_y, viewport_width, viewport_height);

    // Render lights and axies.
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(-ortho_size, ortho_size, -ortho_size, ortho_size, -ortho_size, ortho_size);
    gluLookAt(cam_x, cam_y, cam_z, 0.0, 0.0, 0.0, cam_nx, cam_ny, cam_nz);
    DrawLights();
    DrawAxises();

    // Render colorcube.
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(-ortho_size, ortho_size, -ortho_size, ortho_size, -ortho_size, ortho_size);
    gluLookAt(cam_x, cam_y, cam_z, 0.0, 0.0, 0.0, cam_nx, cam_ny, cam_nz);
    glTranslatef(trans_x * world_size / 180, trans_y * world_size / 180, trans_z * world_size / 180);
    glRotatef(theta_x, 1, 0, 0);
    glRotatef(theta_y, 0, 1, 0);
    glRotatef(theta_z, 0, 0, 1);
    glScalef(scale_x, scale_y, scale_z);

    if (obj_is_custom_model) {
        glRotatef(-90, 1, 0, 0);
        DrawCustomModel();
    } else {
        DrawColorCube();
    }
}

void DrawTriangle(GLfloat* vertex1, GLfloat* vertex2, GLfloat* vertex3,
        GLfloat* normal1, GLfloat* normal2, GLfloat* normal3,
        GLfloat* front_color, GLfloat* back_color) {

    glBegin(GL_TRIANGLES);
        glEnable(GL_CULL_FACE);
        
        glCullFace(GL_BACK);
        glColor3fv(front_color);
        glNormal3fv(normal1);
        glVertex3fv(vertex1);
        glNormal3fv(normal2);
        glVertex3fv(vertex2);
        glNormal3fv(normal3);
        glVertex3fv(vertex3);

        glCullFace(GL_FRONT);
        glColor3fv(back_color);
        glVertex3fv(vertex1);
        glVertex3fv(vertex2);
        glVertex3fv(vertex3);
    glEnd();
}

void DrawPolygon(int a, int b, int c, int d) {
    glBegin(GL_POLYGON);
        glColor3fv(colors[a]);
        glNormal3fv(normals[a]);
        glVertex3fv(vertices[a]);

        glColor3fv(colors[b]);
        glNormal3fv(normals[b]);
        glVertex3fv(vertices[b]);

        glColor3fv(colors[c]);
        glNormal3fv(normals[c]);
        glVertex3fv(vertices[c]);

        glColor3fv(colors[d]);
        glNormal3fv(normals[d]);
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

void DrawCustomModel() {
    for (int i = 0; i < colored_triangles_count; i++) {
        Vertex& v1 = model_vertices[ model_triangles[i].vertex1 ];
        Vertex& v2 = model_vertices[ model_triangles[i].vertex2 ];
        Vertex& v3 = model_vertices[ model_triangles[i].vertex3 ];

        GLfloat fr = model_triangles[i].fr / 255.0f;
        GLfloat fg = model_triangles[i].fg / 255.0f;
        GLfloat fb = model_triangles[i].fb / 255.0f;
        GLfloat br = model_triangles[i].br / 255.0f;
        GLfloat bg = model_triangles[i].bg / 255.0f;
        GLfloat bb = model_triangles[i].bb / 255.0f;

        GLfloat vertex1[3] = { v1.x - calibration_offset_x, v1.y - calibration_offset_y, v1.z - calibration_offset_z};
        GLfloat vertex2[3] = { v2.x - calibration_offset_x, v2.y - calibration_offset_y, v2.z - calibration_offset_z};
        GLfloat vertex3[3] = { v3.x - calibration_offset_x, v3.y - calibration_offset_y, v3.z - calibration_offset_z};

        GLfloat normal1[3] = { v1.nx, v1.ny, v1.nz };
        GLfloat normal2[3] = { v2.nx, v2.ny, v2.nz };
        GLfloat normal3[3] = { v3.nx, v3.ny, v3.nz };

        GLfloat front_color[3] = { fr, fg, fb };
        GLfloat back_color[3] = { br, bg, bb };

        DrawTriangle(vertex1, vertex2, vertex3, normal1, normal2, normal3, front_color, back_color);
    }
}

void DrawLights() {
    GLfloat global_ambient[] = { 0.2f, 0.2f, 0.2f, 0.0f };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

    GLfloat light0_position[] = { world_size * 2, 0.0f, 0, 1.0f };
    GLfloat light1_position[] = { 0.0f, world_size * 2, 0.0f, 1.0f };
    GLfloat light2_position[] = { 0.0f, 0.0f, world_size * 2, 1.0f };

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
        glVertex3f(world_size, 0, 0);

        glColor3f(0, 1, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, world_size, 0);

        glColor3f(0, 0, 1);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, world_size);
    glEnd();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RotationXScrollBarChange(TObject *Sender) {
    theta_x = RotationXScrollBar->Position;
    RotationXValueLabel->Caption = (int) theta_x;
    GLBox1->Invalidate();
}

void __fastcall TForm1::RotationYScrollBarChange(TObject *Sender) {
    theta_y = RotationYScrollBar->Position;
    RotationYValueLabel->Caption = (int) theta_y;
    GLBox1->Invalidate();
}

void __fastcall TForm1::RotationZScrollBarChange(TObject *Sender) {
    theta_z = RotationZScrollBar->Position;
    RotationZValueLabel->Caption = (int) theta_z;
    GLBox1->Invalidate();
}

void __fastcall TForm1::ResetRotationBtnClick(TObject *Sender) {
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

void __fastcall TForm1::TranslationXScrollBarChange(TObject *Sender) {
    trans_x = TranslationXScrollBar->Position;
    TranslationXValueLabel->Caption = (int) trans_x;
    GLBox1->Invalidate();
}

void __fastcall TForm1::TranslationYScrollBarChange(TObject *Sender) {
    trans_y = TranslationYScrollBar->Position;
    TranslationYValueLabel->Caption = (int) trans_y;
    GLBox1->Invalidate();
}

void __fastcall TForm1::TranslationZScrollBarChange(TObject *Sender) {
    trans_z = TranslationZScrollBar->Position;
    TranslationZValueLabel->Caption = (int) trans_z;
    GLBox1->Invalidate();
}

void __fastcall TForm1::ResetTranslationBtnClick(TObject *Sender) {
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
void __fastcall TForm1::ScalingXScrollBarChange(TObject *Sender) {
    scale_x = ScalingXScrollBar->Position;
    ScalingXValueLabel->Caption = (int) scale_x;
    GLBox1->Invalidate();
}

void __fastcall TForm1::ScalingYScrollBarChange(TObject *Sender) {
    scale_y = ScalingYScrollBar->Position;
    ScalingYValueLabel->Caption = (int) scale_y;
    GLBox1->Invalidate();
}

void __fastcall TForm1::ScalingZScrollBarChange(TObject *Sender) {
    scale_z = ScalingZScrollBar->Position;
    ScalingZValueLabel->Caption = (int) scale_z;
    GLBox1->Invalidate();
}

void __fastcall TForm1::ResetScalingBtnClick(TObject *Sender) {
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
void __fastcall TForm1::SetRotation(int new_theta_x, int new_theta_y, int new_theta_z) {
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
void __fastcall TForm1::Iso1BtnClick(TObject *Sender) {
    SetRotation(0, 0, 0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::IsoBtn2Click(TObject *Sender) {
    SetRotation(0, -90, 0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Iso3BtnClick(TObject *Sender) {
    SetRotation(0, -180, 0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Iso4BtnClick(TObject *Sender) {
    SetRotation(0, 90, 0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Iso8BtnClick(TObject *Sender) {
    SetRotation(0, 0, 180);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Iso5BtnClick(TObject *Sender) {
    SetRotation(0, 90, 180);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Iso6BtnClick(TObject *Sender) {
    SetRotation(0, 180, 180);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Iso7BtnClick(TObject *Sender) {
    SetRotation(0, -90, 180);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RedLightBoxClick(TObject *Sender) {
    red_light_on = !red_light_on;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::GreenLightBoxClick(TObject *Sender) {
    green_light_on = !green_light_on;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BlueLightBoxClick(TObject *Sender) {
    blue_light_on = !blue_light_on;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LineShadingBtnClick(TObject *Sender) {
    shading_mode = GL_LINE;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FlatShadingBtnClick(TObject *Sender) {
    shading_mode = GL_FLAT;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SmoothShadingBtnClick(TObject *Sender) {
    shading_mode = GL_SMOOTH;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SingleViewportBtnClick(TObject *Sender) {
    single_viewport = true;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FourViewportBtnClick(TObject *Sender) {
    single_viewport = false;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LightingEnabledBoxClick(TObject *Sender) {
    lighting_enabled = !lighting_enabled;

    RedLightBox->Enabled = lighting_enabled;
    GreenLightBox->Enabled = lighting_enabled;
    BlueLightBox->Enabled = lighting_enabled;

    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BronzeMaterialBtnClick(TObject *Sender) {
    selected_material_ambient = bronze_ambient;
    selected_material_diffuse = bronze_diffuse;
    selected_material_specular = bronze_specular;

    LightingEnabledBox->Checked = true;
    lighting_enabled = true;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SilverMaterialBtnClick(TObject *Sender) {
    selected_material_ambient = silver_ambient;
    selected_material_diffuse = silver_diffuse;
    selected_material_specular = silver_specular;

    LightingEnabledBox->Checked = true;
    lighting_enabled = true;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::GoldMaterialBtnClick(TObject *Sender) {
    selected_material_ambient = gold_ambient;
    selected_material_diffuse = gold_diffuse;
    selected_material_specular = gold_specular;

    LightingEnabledBox->Checked = true;
    lighting_enabled = true;
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OriginalMaterialBtnClick(TObject *Sender) {
    selected_material_ambient = NULL;
    selected_material_diffuse = NULL;
    selected_material_specular = NULL;

    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OpenModelFileBtnClick(TObject *Sender) {
    if (OD->Execute()) {
        MsgLabel->Caption = "Loading model... Please wait.";
        
        bool min_max_initialized = false;
        GLfloat min_vertex_x = 0;
        GLfloat max_vertex_x = 0;
        GLfloat min_vertex_y = 0;
        GLfloat max_vertex_y = 0;
        GLfloat min_vertex_z = 0;
        GLfloat max_vertex_z = 0;

        AnsiString directory = ExtractFileDir(OD->FileName);
        AnsiString filename = ExtractFileName(OD->FileName);
        AnsiString filepath = directory + "\\" + filename;

        std::ifstream file(filepath.c_str());
        string line;

        // Get the number of simple triangles.
        std::getline(file, line);
        stringstream(Split(line, ':')[1]) >> simple_triangles_count;

        // Get the number of colored triangles.
        std::getline(file, line);
        stringstream(Split(line, ':')[1]) >> colored_triangles_count;
        model_triangles = (Triangle*) malloc(colored_triangles_count * sizeof(Triangle));

        // Get the number of defined vertices.
        std::getline(file, line);
        stringstream(Split(line, ':')[1]) >> vertices_count;
        model_vertices = (Vertex*) malloc(vertices_count * sizeof(Vertex));

        for (int i = 0; i < colored_triangles_count; i++) {
            std::getline(file, line);
            model_triangles[i] = Triangle();
            Triangle& t = model_triangles[i];

            vector<string> tokens = Split(line, ' ');
            stringstream(tokens[1]) >> t.vertex1;
            stringstream(tokens[2]) >> t.vertex2;
            stringstream(tokens[3]) >> t.vertex3;
            stringstream(tokens[4]) >> t.fr;
            stringstream(tokens[5]) >> t.fg;
            stringstream(tokens[6]) >> t.fb;
            stringstream(tokens[7]) >> t.br;
            stringstream(tokens[8]) >> t.bg;
            stringstream(tokens[9]) >> t.bb;
        }

        for (int i = 0; i < vertices_count; i++) {
            std::getline(file, line);
            model_vertices[i] = Vertex();
            Vertex& v = model_vertices[i];

            vector<string> tokens = Split(line, ' ');
            stringstream(tokens[1]) >> v.x;
            stringstream(tokens[2]) >> v.y;
            stringstream(tokens[3]) >> v.z;
            stringstream(tokens[4]) >> v.nx;
            stringstream(tokens[5]) >> v.ny;
            stringstream(tokens[6]) >> v.nz;

            if (!min_max_initialized) {
                min_vertex_x = v.x;
                max_vertex_x = v.x;

                min_vertex_y = v.y;
                max_vertex_y = v.y;
                
                min_vertex_z = v.z;
                max_vertex_z = v.z;

                min_max_initialized = true;
            }

            min_vertex_x = (v.x < min_vertex_x) ? v.x : min_vertex_x;
            max_vertex_x = (v.x > max_vertex_x) ? v.x : max_vertex_x;

            min_vertex_y = (v.y < min_vertex_y) ? v.y : min_vertex_y;
            max_vertex_y = (v.y > max_vertex_y) ? v.y : max_vertex_y;

            min_vertex_z = (v.z < min_vertex_z) ? v.z : min_vertex_z;
            max_vertex_z = (v.z > max_vertex_z) ? v.z : max_vertex_z;
        }

        GLfloat edge1_width = (max_vertex_x - min_vertex_x);
        GLfloat edge2_width = (max_vertex_y - min_vertex_y);
        GLfloat edge3_width = (max_vertex_z - min_vertex_z);

        GLfloat model_center_x = (max_vertex_x + min_vertex_x) / 2.0;
        GLfloat model_center_y = (max_vertex_y + min_vertex_y) / 2.0;
        GLfloat model_center_z = (max_vertex_z + min_vertex_z) / 2.0;

        calibration_offset_x = model_center_x - 0;
        calibration_offset_y = model_center_y - 0;
        calibration_offset_z = model_center_z - 0;

        world_size = Max(edge1_width, edge2_width, edge3_width);

        obj_is_custom_model = true;
        not_freed = true;
        MsgLabel->Caption = "Loaded model: " + filepath;

        GLBox1->Invalidate();
    } else {
        OpenModelFileBtn->Checked = false;
        ColorcubeModelBtn->Checked = true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ColorcubeModelBtnClick(TObject *Sender)
{
    world_size = 3.0;
    obj_is_custom_model = false;

    if (not_freed) {
        free(model_triangles);
        free(model_vertices);
        not_freed = false;
    }

    MsgLabel->Caption = "";
    GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender) {
    if (not_freed) {
        free(model_triangles);
        free(model_vertices);
        not_freed = false;
    }
}
//---------------------------------------------------------------------------
vector<string> Split(const string& s, const char delimiter) {
    stringstream ss(s);
    string t;
    vector<string> tokens;

    while (std::getline(ss, t, delimiter)) {
        if (t.length() > 0) {
            tokens.push_back(t);
        }
    }
    return tokens;
}
//---------------------------------------------------------------------------
GLfloat Max(GLfloat v1, GLfloat v2, GLfloat v3) {
    GLfloat max = v1;
    if (v2 > max) max = v2;
    if (v3 > max) max = v3;
    return max;
}
