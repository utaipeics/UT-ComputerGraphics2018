//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "GLCtrl.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TGLBox *GLBox1;
    TGroupBox *RotationGroupBox;
    TScrollBar *RotationXScrollBar;
    TScrollBar *RotationYScrollBar;
    TScrollBar *RotationZScrollBar;
    TLabel *RotationXAxisLabel;
    TLabel *RotationYAxisLabel;
    TLabel *RotationZAxisLabel;
    TLabel *RotationXValueLabel;
    TLabel *RotationYValueLabel;
    TLabel *RotationZValueLabel;
    TButton *ResetRotationBtn;
    TGroupBox *TranslationGroupBox;
    TLabel *TranslationXAxisLabel;
    TLabel *TranslationYAxisLabel;
    TLabel *TranslationZAxisLabel;
    TLabel *TranslationXValueLabel;
    TLabel *TranslationYValueLabel;
    TLabel *TranslationZValueLabel;
    TScrollBar *TranslationXScrollBar;
    TScrollBar *TranslationYScrollBar;
    TScrollBar *TranslationZScrollBar;
    TButton *ResetTranslationBtn;
    TGroupBox *ScalingGroupBox;
    TLabel *ScalingXAxisLabel;
    TLabel *ScalingYAxisLabel;
    TLabel *ScalingZAxisLabel;
    TLabel *ScalingXValueLabel;
    TLabel *ScalingYValueLabel;
    TLabel *ScalingZValueLabel;
    TScrollBar *ScalingXScrollBar;
    TScrollBar *ScalingYScrollBar;
    TScrollBar *ScalingZScrollBar;
    TButton *ResetScalingBtn;
    void __fastcall draw(TObject *Sender);
    void __fastcall init(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
