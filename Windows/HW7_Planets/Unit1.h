//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "GLCtrl.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class Planet
{
private:
    const double kRevolveFactor;
    const double kRotateFactor;
    float r_, g_, b_;
    float axial_tilt_;
    float diameter_;
    float distance_; // distance to the Sun.

    double revolve_;
    double rotate_;

public:
    Planet(const double revolve_factor, const double rotate_factor);
    void SetColor(const float r, const float g, const float b);
    void SetAxialTilt(const float axial_tilt);
    void SetDiameter(const float diameter);
    void SetDistance(const float distance);

    double rotate();
    double set_rotate(const float rotate);

    void Update();
    void Draw(GLenum style);
};

class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TGLBox *GLBox1;
    TTimer *Timer1;
    void __fastcall draw(TObject *Sender);
    void __fastcall init(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
