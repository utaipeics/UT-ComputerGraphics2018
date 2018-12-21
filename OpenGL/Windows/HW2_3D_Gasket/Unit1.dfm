object Form1: TForm1
  Left = 993
  Top = 247
  Width = 423
  Height = 447
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
    Width = 385
    Height = 385
    OnGLInit = Init
    OnGLDraw = Draw
  end
  object Timer1: TTimer
    OnTimer = UpdateTetra
    Left = 376
    Top = 376
  end
end
