object Form1: TForm1
  Left = 122
  Top = 97
  Width = 952
  Height = 659
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GLBox1: TGLBox
    Left = 16
    Top = 16
    Width = 593
    Height = 593
    OnGLInit = init
    OnGLDraw = draw
  end
  object RotationGroupBox: TGroupBox
    Left = 624
    Top = 16
    Width = 305
    Height = 137
    Caption = 'Rotation'
    TabOrder = 1
    object RotationXAxisLabel: TLabel
      Left = 16
      Top = 32
      Width = 7
      Height = 13
      Caption = 'X'
    end
    object RotationYAxisLabel: TLabel
      Left = 16
      Top = 64
      Width = 7
      Height = 13
      Caption = 'Y'
    end
    object RotationZAxisLabel: TLabel
      Left = 16
      Top = 96
      Width = 7
      Height = 13
      Caption = 'Z'
    end
    object RotationXValueLabel: TLabel
      Left = 208
      Top = 32
      Width = 6
      Height = 13
      Caption = '0'
    end
    object RotationYValueLabel: TLabel
      Left = 208
      Top = 64
      Width = 6
      Height = 13
      Caption = '0'
    end
    object RotationZValueLabel: TLabel
      Left = 208
      Top = 96
      Width = 6
      Height = 13
      Caption = '0'
    end
    object RotationXScrollBar: TScrollBar
      Left = 40
      Top = 32
      Width = 153
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 0
      OnChange = RotationXScrollBarChange
    end
    object RotationYScrollBar: TScrollBar
      Left = 40
      Top = 64
      Width = 153
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 1
      OnChange = RotationYScrollBarChange
    end
    object RotationZScrollBar: TScrollBar
      Left = 40
      Top = 96
      Width = 153
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 2
      OnChange = RotationZScrollBarChange
    end
    object ResetRotationBtn: TButton
      Left = 232
      Top = 32
      Width = 57
      Height = 81
      Caption = 'Reset'
      TabOrder = 3
      OnClick = ResetRotationBtnClick
    end
  end
  object TranslationGroupBox: TGroupBox
    Left = 624
    Top = 160
    Width = 305
    Height = 137
    Caption = 'Translation'
    TabOrder = 2
    object TranslationXAxisLabel: TLabel
      Left = 16
      Top = 32
      Width = 7
      Height = 13
      Caption = 'X'
    end
    object TranslationYAxisLabel: TLabel
      Left = 16
      Top = 64
      Width = 7
      Height = 13
      Caption = 'Y'
    end
    object TranslationZAxisLabel: TLabel
      Left = 16
      Top = 96
      Width = 7
      Height = 13
      Caption = 'Z'
    end
    object TranslationXValueLabel: TLabel
      Left = 208
      Top = 32
      Width = 6
      Height = 13
      Caption = '0'
    end
    object TranslationYValueLabel: TLabel
      Left = 208
      Top = 64
      Width = 6
      Height = 13
      Caption = '0'
    end
    object TranslationZValueLabel: TLabel
      Left = 208
      Top = 96
      Width = 6
      Height = 13
      Caption = '0'
    end
    object TranslationXScrollBar: TScrollBar
      Left = 40
      Top = 32
      Width = 153
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 0
      OnChange = TranslationXScrollBarChange
    end
    object TranslationYScrollBar: TScrollBar
      Left = 40
      Top = 64
      Width = 153
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 1
      OnChange = TranslationYScrollBarChange
    end
    object TranslationZScrollBar: TScrollBar
      Left = 40
      Top = 96
      Width = 153
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 2
      OnChange = TranslationZScrollBarChange
    end
    object ResetTranslationBtn: TButton
      Left = 232
      Top = 32
      Width = 57
      Height = 81
      Caption = 'Reset'
      TabOrder = 3
      OnClick = ResetTranslationBtnClick
    end
  end
  object ScalingGroupBox: TGroupBox
    Left = 624
    Top = 304
    Width = 305
    Height = 137
    Caption = 'Scaling'
    TabOrder = 3
    object ScalingXAxisLabel: TLabel
      Left = 16
      Top = 32
      Width = 7
      Height = 13
      Caption = 'X'
    end
    object ScalingYAxisLabel: TLabel
      Left = 16
      Top = 64
      Width = 7
      Height = 13
      Caption = 'Y'
    end
    object ScalingZAxisLabel: TLabel
      Left = 16
      Top = 96
      Width = 7
      Height = 13
      Caption = 'Z'
    end
    object ScalingXValueLabel: TLabel
      Left = 208
      Top = 32
      Width = 6
      Height = 13
      Caption = '1'
    end
    object ScalingYValueLabel: TLabel
      Left = 208
      Top = 64
      Width = 6
      Height = 13
      Caption = '1'
    end
    object ScalingZValueLabel: TLabel
      Left = 208
      Top = 96
      Width = 6
      Height = 13
      Caption = '1'
    end
    object ScalingXScrollBar: TScrollBar
      Left = 40
      Top = 32
      Width = 153
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      Position = 1
      TabOrder = 0
      OnChange = ScalingXScrollBarChange
    end
    object ScalingYScrollBar: TScrollBar
      Left = 40
      Top = 64
      Width = 153
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      Position = 1
      TabOrder = 1
      OnChange = ScalingYScrollBarChange
    end
    object ScalingZScrollBar: TScrollBar
      Left = 40
      Top = 96
      Width = 153
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      Position = 1
      TabOrder = 2
      OnChange = ScalingZScrollBarChange
    end
    object ResetScalingBtn: TButton
      Left = 232
      Top = 32
      Width = 57
      Height = 81
      Caption = 'Reset'
      TabOrder = 3
      OnClick = ResetScalingBtnClick
    end
  end
  object GroupBox1: TGroupBox
    Left = 624
    Top = 448
    Width = 305
    Height = 97
    Caption = 'Isometric View'
    TabOrder = 4
    object Iso1Btn: TButton
      Left = 16
      Top = 24
      Width = 57
      Height = 25
      Caption = '(1, 1, 1)'
      TabOrder = 0
      OnClick = Iso1BtnClick
    end
    object IsoBtn2: TButton
      Left = 88
      Top = 24
      Width = 57
      Height = 25
      Caption = '(1, 1, -1)'
      TabOrder = 1
      OnClick = IsoBtn2Click
    end
    object Iso3Btn: TButton
      Left = 160
      Top = 24
      Width = 57
      Height = 25
      Caption = '(-1, 1, -1)'
      TabOrder = 2
      OnClick = Iso3BtnClick
    end
    object Iso4Btn: TButton
      Left = 232
      Top = 24
      Width = 57
      Height = 25
      Caption = '(-1, 1, 1)'
      TabOrder = 3
      OnClick = Iso4BtnClick
    end
    object Iso5Btn: TButton
      Left = 16
      Top = 64
      Width = 57
      Height = 25
      Caption = '(1, -1, 1)'
      TabOrder = 4
      OnClick = Iso5BtnClick
    end
    object Iso6Btn: TButton
      Left = 88
      Top = 64
      Width = 57
      Height = 25
      Caption = '(1, -1, -1)'
      TabOrder = 5
      OnClick = Iso6BtnClick
    end
    object Iso7Btn: TButton
      Left = 160
      Top = 64
      Width = 57
      Height = 25
      Caption = '(-1, -1, -1)'
      TabOrder = 6
      OnClick = Iso7BtnClick
    end
    object Iso8Btn: TButton
      Left = 232
      Top = 64
      Width = 57
      Height = 25
      Caption = '(-1, -1, 1)'
      TabOrder = 7
      OnClick = Iso8BtnClick
    end
  end
  object GroupBox2: TGroupBox
    Left = 624
    Top = 552
    Width = 305
    Height = 57
    Caption = 'Lighting'
    TabOrder = 5
    object RedLightBox: TCheckBox
      Left = 24
      Top = 24
      Width = 49
      Height = 17
      Caption = 'Red'
      Checked = True
      State = cbChecked
      TabOrder = 0
      OnClick = RedLightBoxClick
    end
    object GreenLightBox: TCheckBox
      Left = 120
      Top = 24
      Width = 57
      Height = 17
      Caption = 'Green'
      Checked = True
      State = cbChecked
      TabOrder = 1
      OnClick = GreenLightBoxClick
    end
    object BlueLightBox: TCheckBox
      Left = 224
      Top = 24
      Width = 49
      Height = 17
      Caption = 'Blue'
      Checked = True
      State = cbChecked
      TabOrder = 2
      OnClick = BlueLightBoxClick
    end
  end
end
