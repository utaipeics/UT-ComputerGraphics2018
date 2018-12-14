object Form1: TForm1
  Left = 632
  Top = 205
  Width = 581
  Height = 600
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
    Height = 537
    OnGLInit = init
    OnGLDraw = draw
  end
  object Timer1: TTimer
    Interval = 50
    OnTimer = Timer1Timer
    Top = 560
  end
end
