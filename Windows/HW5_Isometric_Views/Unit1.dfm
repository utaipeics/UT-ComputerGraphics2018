object Form1: TForm1
  Left = 224
  Top = 124
  Width = 948
  Height = 631
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
    Width = 537
    Height = 569
    OnGLInit = init
    OnGLDraw = draw
  end
  object RotationGroupBox: TGroupBox
    Left = 568
    Top = 16
    Width = 353
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
      Left = 232
      Top = 32
      Width = 6
      Height = 13
      Caption = '0'
    end
    object RotationYValueLabel: TLabel
      Left = 232
      Top = 64
      Width = 6
      Height = 13
      Caption = '0'
    end
    object RotationZValueLabel: TLabel
      Left = 232
      Top = 96
      Width = 6
      Height = 13
      Caption = '0'
    end
    object RotationXScrollBar: TScrollBar
      Left = 40
      Top = 32
      Width = 177
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
      Width = 177
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
      Width = 177
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 2
      OnChange = RotationZScrollBarChange
    end
    object ResetRotationBtn: TButton
      Left = 256
      Top = 32
      Width = 73
      Height = 81
      Caption = 'Reset'
      TabOrder = 3
      OnClick = ResetRotationBtnClick
    end
  end
  object TranslationGroupBox: TGroupBox
    Left = 568
    Top = 176
    Width = 353
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
      Left = 232
      Top = 32
      Width = 6
      Height = 13
      Caption = '0'
    end
    object TranslationYValueLabel: TLabel
      Left = 232
      Top = 64
      Width = 6
      Height = 13
      Caption = '0'
    end
    object TranslationZValueLabel: TLabel
      Left = 232
      Top = 96
      Width = 6
      Height = 13
      Caption = '0'
    end
    object TranslationXScrollBar: TScrollBar
      Left = 40
      Top = 32
      Width = 177
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
      Width = 177
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
      Width = 177
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 2
      OnChange = TranslationZScrollBarChange
    end
    object ResetTranslationBtn: TButton
      Left = 256
      Top = 32
      Width = 73
      Height = 81
      Caption = 'Reset'
      TabOrder = 3
      OnClick = ResetTranslationBtnClick
    end
  end
  object ScalingGroupBox: TGroupBox
    Left = 568
    Top = 336
    Width = 353
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
      Left = 232
      Top = 32
      Width = 6
      Height = 13
      Caption = '1'
    end
    object ScalingYValueLabel: TLabel
      Left = 232
      Top = 64
      Width = 6
      Height = 13
      Caption = '1'
    end
    object ScalingZValueLabel: TLabel
      Left = 232
      Top = 96
      Width = 6
      Height = 13
      Caption = '1'
    end
    object ScalingXScrollBar: TScrollBar
      Left = 40
      Top = 32
      Width = 177
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
      Width = 177
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
      Width = 177
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      Position = 1
      TabOrder = 2
      OnChange = ScalingZScrollBarChange
    end
    object ResetScalingBtn: TButton
      Left = 256
      Top = 32
      Width = 73
      Height = 81
      Caption = 'Reset'
      TabOrder = 3
      OnClick = ResetScalingBtnClick
    end
  end
  object GroupBox1: TGroupBox
    Left = 568
    Top = 488
    Width = 353
    Height = 97
    Caption = 'Isometric View'
    TabOrder = 4
    object Iso1Btn: TButton
      Left = 8
      Top = 24
      Width = 73
      Height = 25
      Caption = '(1, 1, 1)'
      TabOrder = 0
      OnClick = Iso1BtnClick
    end
    object IsoBtn2: TButton
      Left = 96
      Top = 24
      Width = 73
      Height = 25
      Caption = '(1, 1, -1)'
      TabOrder = 1
      OnClick = IsoBtn2Click
    end
    object Iso3Btn: TButton
      Left = 184
      Top = 24
      Width = 73
      Height = 25
      Caption = '(-1, 1, -1)'
      TabOrder = 2
      OnClick = Iso3BtnClick
    end
    object Iso4Btn: TButton
      Left = 272
      Top = 24
      Width = 73
      Height = 25
      Caption = '(-1, 1, 1)'
      TabOrder = 3
      OnClick = Iso4BtnClick
    end
    object Iso5Btn: TButton
      Left = 8
      Top = 64
      Width = 73
      Height = 25
      Caption = '(1, -1, 1)'
      TabOrder = 4
      OnClick = Iso5BtnClick
    end
    object Iso6Btn: TButton
      Left = 96
      Top = 64
      Width = 73
      Height = 25
      Caption = '(1, -1, -1)'
      TabOrder = 5
      OnClick = Iso6BtnClick
    end
    object Iso7Btn: TButton
      Left = 184
      Top = 64
      Width = 73
      Height = 25
      Caption = '(-1, -1, -1)'
      TabOrder = 6
      OnClick = Iso7BtnClick
    end
    object Iso8Btn: TButton
      Left = 272
      Top = 64
      Width = 73
      Height = 25
      Caption = '(-1, -1, 1)'
      TabOrder = 7
      OnClick = Iso8BtnClick
    end
  end
end
