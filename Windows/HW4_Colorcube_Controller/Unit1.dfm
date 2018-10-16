object Form1: TForm1
  Left = 267
  Top = 148
  Width = 960
  Height = 528
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
    Width = 457
    Height = 457
    OnGLInit = init
    OnGLDraw = draw
  end
  object RotationGroupBox: TGroupBox
    Left = 496
    Top = 16
    Width = 433
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
      Left = 312
      Top = 32
      Width = 6
      Height = 13
      Caption = '0'
    end
    object RotationYValueLabel: TLabel
      Left = 312
      Top = 64
      Width = 6
      Height = 13
      Caption = '0'
    end
    object RotationZValueLabel: TLabel
      Left = 312
      Top = 96
      Width = 6
      Height = 13
      Caption = '0'
    end
    object RotationXScrollBar: TScrollBar
      Left = 40
      Top = 32
      Width = 257
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 0
    end
    object RotationYScrollBar: TScrollBar
      Left = 40
      Top = 64
      Width = 257
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 1
    end
    object RotationZScrollBar: TScrollBar
      Left = 40
      Top = 96
      Width = 257
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 2
    end
    object ResetRotationBtn: TButton
      Left = 344
      Top = 32
      Width = 73
      Height = 81
      Caption = 'Reset'
      TabOrder = 3
    end
  end
  object TranslationGroupBox: TGroupBox
    Left = 496
    Top = 176
    Width = 433
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
      Left = 312
      Top = 32
      Width = 6
      Height = 13
      Caption = '0'
    end
    object TranslationYValueLabel: TLabel
      Left = 312
      Top = 64
      Width = 6
      Height = 13
      Caption = '0'
    end
    object TranslationZValueLabel: TLabel
      Left = 312
      Top = 96
      Width = 6
      Height = 13
      Caption = '0'
    end
    object TranslationXScrollBar: TScrollBar
      Left = 40
      Top = 32
      Width = 257
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 0
    end
    object TranslationYScrollBar: TScrollBar
      Left = 40
      Top = 64
      Width = 257
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 1
    end
    object TranslationZScrollBar: TScrollBar
      Left = 40
      Top = 96
      Width = 257
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 2
    end
    object ResetTranslationBtn: TButton
      Left = 344
      Top = 32
      Width = 73
      Height = 81
      Caption = 'Reset'
      TabOrder = 3
    end
  end
  object ScalingGroupBox: TGroupBox
    Left = 496
    Top = 336
    Width = 433
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
      Left = 312
      Top = 32
      Width = 6
      Height = 13
      Caption = '0'
    end
    object ScalingYValueLabel: TLabel
      Left = 312
      Top = 64
      Width = 6
      Height = 13
      Caption = '0'
    end
    object ScalingZValueLabel: TLabel
      Left = 312
      Top = 96
      Width = 6
      Height = 13
      Caption = '0'
    end
    object ScalingXScrollBar: TScrollBar
      Left = 40
      Top = 32
      Width = 257
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 0
    end
    object ScalingYScrollBar: TScrollBar
      Left = 40
      Top = 64
      Width = 257
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 1
    end
    object ScalingZScrollBar: TScrollBar
      Left = 40
      Top = 96
      Width = 257
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 2
    end
    object ResetScalingBtn: TButton
      Left = 344
      Top = 32
      Width = 73
      Height = 81
      Caption = 'Reset'
      TabOrder = 3
    end
  end
end
