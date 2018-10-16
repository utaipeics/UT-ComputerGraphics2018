object Form1: TForm1
  Left = 875
  Top = 395
  Width = 537
  Height = 434
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
    Left = 24
    Top = 16
    Width = 481
    Height = 369
    OnGLInit = init
    OnGLDraw = draw
  end
end
