object frmpassword: Tfrmpassword
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #23494#30721#39564#35777
  ClientHeight = 136
  ClientWidth = 400
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 40
    Top = 32
    Width = 31
    Height = 20
    Caption = #23494#30721':'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = #24494#36719#38597#40657
    Font.Style = []
    ParentFont = False
  end
  object editpassword: TEdit
    Left = 77
    Top = 29
    Width = 281
    Height = 28
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = #24494#36719#38597#40657
    Font.Style = []
    ParentFont = False
    PasswordChar = '*'
    TabOrder = 0
  end
  object Button1: TButton
    Left = 184
    Top = 88
    Width = 81
    Height = 33
    Caption = #30830#35748
    ModalResult = 1
    TabOrder = 1
  end
  object Button2: TButton
    Left = 277
    Top = 88
    Width = 81
    Height = 33
    Caption = #21462#28040
    ModalResult = 2
    TabOrder = 2
  end
end
