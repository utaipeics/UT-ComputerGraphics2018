object Form1: TForm1
  Left = 311
  Top = 67
  Width = 1054
  Height = 775
  Caption = '1071 Computer Graphics Final Project - U10516045 '#29579#20896#20013
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
    Width = 713
    Height = 713
    OnGLInit = init
    OnGLDraw = draw
  end
  object RotationGroupBox: TGroupBox
    Left = 744
    Top = 8
    Width = 289
    Height = 105
    Caption = 'Rotation'
    TabOrder = 1
    object RotationXAxisLabel: TLabel
      Left = 16
      Top = 24
      Width = 7
      Height = 13
      Caption = 'X'
    end
    object RotationYAxisLabel: TLabel
      Left = 16
      Top = 48
      Width = 7
      Height = 13
      Caption = 'Y'
    end
    object RotationZAxisLabel: TLabel
      Left = 16
      Top = 72
      Width = 7
      Height = 13
      Caption = 'Z'
    end
    object RotationXValueLabel: TLabel
      Left = 200
      Top = 24
      Width = 6
      Height = 13
      Caption = '0'
    end
    object RotationYValueLabel: TLabel
      Left = 200
      Top = 48
      Width = 6
      Height = 13
      Caption = '0'
    end
    object RotationZValueLabel: TLabel
      Left = 200
      Top = 72
      Width = 6
      Height = 13
      Caption = '0'
    end
    object RotationXScrollBar: TScrollBar
      Left = 32
      Top = 24
      Width = 153
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 0
      OnChange = RotationXScrollBarChange
    end
    object RotationYScrollBar: TScrollBar
      Left = 32
      Top = 48
      Width = 153
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 1
      OnChange = RotationYScrollBarChange
    end
    object RotationZScrollBar: TScrollBar
      Left = 32
      Top = 72
      Width = 153
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 2
      OnChange = RotationZScrollBarChange
    end
    object ResetRotationBtn: TButton
      Left = 224
      Top = 24
      Width = 49
      Height = 65
      Caption = 'Reset'
      TabOrder = 3
      OnClick = ResetRotationBtnClick
    end
  end
  object TranslationGroupBox: TGroupBox
    Left = 744
    Top = 120
    Width = 289
    Height = 105
    Caption = 'Translation'
    TabOrder = 2
    object TranslationXAxisLabel: TLabel
      Left = 16
      Top = 24
      Width = 7
      Height = 13
      Caption = 'X'
    end
    object TranslationYAxisLabel: TLabel
      Left = 16
      Top = 48
      Width = 7
      Height = 13
      Caption = 'Y'
    end
    object TranslationZAxisLabel: TLabel
      Left = 16
      Top = 72
      Width = 7
      Height = 13
      Caption = 'Z'
    end
    object TranslationXValueLabel: TLabel
      Left = 200
      Top = 24
      Width = 6
      Height = 13
      Caption = '0'
    end
    object TranslationYValueLabel: TLabel
      Left = 200
      Top = 48
      Width = 6
      Height = 13
      Caption = '0'
    end
    object TranslationZValueLabel: TLabel
      Left = 200
      Top = 72
      Width = 6
      Height = 13
      Caption = '0'
    end
    object TranslationXScrollBar: TScrollBar
      Left = 32
      Top = 24
      Width = 153
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 0
      OnChange = TranslationXScrollBarChange
    end
    object TranslationYScrollBar: TScrollBar
      Left = 32
      Top = 48
      Width = 153
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 1
      OnChange = TranslationYScrollBarChange
    end
    object TranslationZScrollBar: TScrollBar
      Left = 32
      Top = 72
      Width = 153
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 2
      OnChange = TranslationZScrollBarChange
    end
    object ResetTranslationBtn: TButton
      Left = 224
      Top = 24
      Width = 49
      Height = 65
      Caption = 'Reset'
      TabOrder = 3
      OnClick = ResetTranslationBtnClick
    end
  end
  object ScalingGroupBox: TGroupBox
    Left = 744
    Top = 232
    Width = 289
    Height = 105
    Caption = 'Scaling'
    TabOrder = 3
    object ScalingXAxisLabel: TLabel
      Left = 16
      Top = 24
      Width = 7
      Height = 13
      Caption = 'X'
    end
    object ScalingYAxisLabel: TLabel
      Left = 16
      Top = 48
      Width = 7
      Height = 13
      Caption = 'Y'
    end
    object ScalingZAxisLabel: TLabel
      Left = 16
      Top = 72
      Width = 7
      Height = 13
      Caption = 'Z'
    end
    object ScalingXValueLabel: TLabel
      Left = 200
      Top = 24
      Width = 6
      Height = 13
      Caption = '3'
    end
    object ScalingYValueLabel: TLabel
      Left = 200
      Top = 48
      Width = 6
      Height = 13
      Caption = '3'
    end
    object ScalingZValueLabel: TLabel
      Left = 200
      Top = 72
      Width = 6
      Height = 13
      Caption = '3'
    end
    object ScalingXScrollBar: TScrollBar
      Left = 32
      Top = 24
      Width = 153
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      Position = 3
      TabOrder = 0
      OnChange = ScalingXScrollBarChange
    end
    object ScalingYScrollBar: TScrollBar
      Left = 32
      Top = 48
      Width = 153
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      Position = 3
      TabOrder = 1
      OnChange = ScalingYScrollBarChange
    end
    object ScalingZScrollBar: TScrollBar
      Left = 32
      Top = 72
      Width = 153
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      Position = 3
      TabOrder = 2
      OnChange = ScalingZScrollBarChange
    end
    object ResetScalingBtn: TButton
      Left = 224
      Top = 24
      Width = 49
      Height = 65
      Caption = 'Reset'
      TabOrder = 3
      OnClick = ResetScalingBtnClick
    end
  end
  object GroupBox1: TGroupBox
    Left = 744
    Top = 344
    Width = 289
    Height = 105
    Caption = 'Isometric Views'
    TabOrder = 4
    object Iso1Btn: TButton
      Left = 8
      Top = 24
      Width = 57
      Height = 25
      Caption = '(1, 1, 1)'
      TabOrder = 0
      OnClick = Iso1BtnClick
    end
    object IsoBtn2: TButton
      Left = 80
      Top = 24
      Width = 57
      Height = 25
      Caption = '(1, 1, -1)'
      TabOrder = 1
      OnClick = IsoBtn2Click
    end
    object Iso3Btn: TButton
      Left = 152
      Top = 24
      Width = 57
      Height = 25
      Caption = '(-1, 1, -1)'
      TabOrder = 2
      OnClick = Iso3BtnClick
    end
    object Iso4Btn: TButton
      Left = 224
      Top = 24
      Width = 57
      Height = 25
      Caption = '(-1, 1, 1)'
      TabOrder = 3
      OnClick = Iso4BtnClick
    end
    object Iso5Btn: TButton
      Left = 8
      Top = 64
      Width = 57
      Height = 25
      Caption = '(1, -1, 1)'
      TabOrder = 4
      OnClick = Iso5BtnClick
    end
    object Iso6Btn: TButton
      Left = 80
      Top = 64
      Width = 57
      Height = 25
      Caption = '(1, -1, -1)'
      TabOrder = 5
      OnClick = Iso6BtnClick
    end
    object Iso7Btn: TButton
      Left = 152
      Top = 64
      Width = 57
      Height = 25
      Caption = '(-1, -1, -1)'
      TabOrder = 6
      OnClick = Iso7BtnClick
    end
    object Iso8Btn: TButton
      Left = 224
      Top = 64
      Width = 57
      Height = 25
      Caption = '(-1, -1, 1)'
      TabOrder = 7
      OnClick = Iso8BtnClick
    end
  end
  object GroupBox2: TGroupBox
    Left = 744
    Top = 456
    Width = 289
    Height = 49
    Caption = 'Lighting'
    TabOrder = 5
    object RedLightBox: TCheckBox
      Left = 80
      Top = 24
      Width = 49
      Height = 17
      Caption = 'Red'
      Checked = True
      Enabled = False
      State = cbChecked
      TabOrder = 0
      OnClick = RedLightBoxClick
    end
    object GreenLightBox: TCheckBox
      Left = 144
      Top = 24
      Width = 57
      Height = 17
      Caption = 'Green'
      Checked = True
      Enabled = False
      State = cbChecked
      TabOrder = 1
      OnClick = GreenLightBoxClick
    end
    object BlueLightBox: TCheckBox
      Left = 208
      Top = 24
      Width = 49
      Height = 17
      Caption = 'Blue'
      Checked = True
      Enabled = False
      State = cbChecked
      TabOrder = 2
      OnClick = BlueLightBoxClick
    end
    object LightingEnabledBox: TCheckBox
      Left = 8
      Top = 24
      Width = 57
      Height = 17
      Caption = 'On/Off'
      TabOrder = 3
      OnClick = LightingEnabledBoxClick
    end
  end
  object GroupBox3: TGroupBox
    Left = 744
    Top = 512
    Width = 289
    Height = 49
    Caption = 'Viewport(s)'
    TabOrder = 6
    object SingleViewportBtn: TRadioButton
      Left = 8
      Top = 24
      Width = 57
      Height = 17
      Caption = 'Single'
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = SingleViewportBtnClick
    end
    object FourViewportBtn: TRadioButton
      Left = 80
      Top = 24
      Width = 73
      Height = 17
      Caption = 'Four'
      TabOrder = 1
      OnClick = FourViewportBtnClick
    end
  end
  object GroupBox4: TGroupBox
    Left = 744
    Top = 568
    Width = 289
    Height = 49
    Caption = 'Shading'
    TabOrder = 7
    object LineShadingBtn: TRadioButton
      Left = 8
      Top = 24
      Width = 49
      Height = 17
      Caption = 'Line'
      TabOrder = 0
      OnClick = LineShadingBtnClick
    end
    object FlatShadingBtn: TRadioButton
      Left = 80
      Top = 24
      Width = 49
      Height = 17
      Caption = 'Flat'
      TabOrder = 1
      OnClick = FlatShadingBtnClick
    end
    object SmoothShadingBtn: TRadioButton
      Left = 144
      Top = 24
      Width = 65
      Height = 17
      Caption = 'Smooth'
      Checked = True
      TabOrder = 2
      TabStop = True
      OnClick = SmoothShadingBtnClick
    end
  end
  object GroupBox5: TGroupBox
    Left = 744
    Top = 680
    Width = 289
    Height = 49
    Caption = 'Object'
    TabOrder = 8
    object ColorcubeModelBtn: TRadioButton
      Left = 8
      Top = 24
      Width = 73
      Height = 17
      Caption = 'Colorcube'
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object OpenModelFileBtn: TRadioButton
      Left = 144
      Top = 24
      Width = 113
      Height = 17
      Caption = 'Open Model File...'
      TabOrder = 1
      OnClick = OpenModelFileBtnClick
    end
  end
  object GroupBox6: TGroupBox
    Left = 744
    Top = 624
    Width = 289
    Height = 49
    Caption = 'Material'
    TabOrder = 9
    object BronzeMaterialBtn: TRadioButton
      Left = 80
      Top = 24
      Width = 57
      Height = 17
      Caption = 'Bronze'
      TabOrder = 0
      OnClick = BronzeMaterialBtnClick
    end
    object SilverMaterialBtn: TRadioButton
      Left = 144
      Top = 24
      Width = 57
      Height = 17
      Caption = 'Silver'
      TabOrder = 1
      OnClick = SilverMaterialBtnClick
    end
    object GoldMaterialBtn: TRadioButton
      Left = 208
      Top = 24
      Width = 57
      Height = 17
      Caption = 'Gold'
      TabOrder = 2
      OnClick = GoldMaterialBtnClick
    end
    object OriginalMaterialBtn: TRadioButton
      Left = 8
      Top = 24
      Width = 57
      Height = 17
      Caption = 'Original'
      Checked = True
      TabOrder = 3
      TabStop = True
      OnClick = OriginalMaterialBtnClick
    end
  end
  object OD: TOpenDialog
    DefaultExt = '*.*'
    Top = 736
  end
end
