object frmteacher: Tfrmteacher
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #25945#24072
  ClientHeight = 367
  ClientWidth = 426
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 426
    Height = 367
    Align = alClient
    BevelOuter = bvLowered
    Caption = 'Panel1'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = #24494#36719#38597#40657
    Font.Style = []
    ParentFont = False
    ShowCaption = False
    TabOrder = 0
    object Label1: TLabel
      Left = 34
      Top = 24
      Width = 42
      Height = 20
      Caption = #22995#21517#65306
    end
    object Label2: TLabel
      Left = 248
      Top = 24
      Width = 31
      Height = 20
      Caption = #22352#26426':'
    end
    object Label3: TLabel
      Left = 16
      Top = 122
      Width = 59
      Height = 20
      Caption = #23398#26657#29677#32423':'
    end
    object Label4: TLabel
      Left = 248
      Top = 80
      Width = 42
      Height = 20
      Caption = #25163#26426#65306
    end
    object Label5: TLabel
      Left = 34
      Top = 164
      Width = 42
      Height = 20
      Caption = #22320#22336#65306
    end
    object Label6: TLabel
      Left = 34
      Top = 80
      Width = 42
      Height = 20
      Caption = #31185#30446#65306
    end
    object Label7: TLabel
      Left = 32
      Top = 216
      Width = 42
      Height = 20
      Caption = #22791#27880#65306
    end
    object editname: TEdit
      Left = 82
      Top = 21
      Width = 121
      Height = 28
      TabOrder = 0
    end
    object edittel: TEdit
      Left = 285
      Top = 21
      Width = 121
      Height = 28
      TabOrder = 1
    end
    object editaddress: TEdit
      Left = 82
      Top = 161
      Width = 324
      Height = 28
      TabOrder = 2
    end
    object editclass: TEdit
      Left = 81
      Top = 121
      Width = 325
      Height = 28
      TabOrder = 3
    end
    object editkemu: TEdit
      Left = 82
      Top = 77
      Width = 121
      Height = 28
      TabOrder = 4
    end
    object editmob: TEdit
      Left = 285
      Top = 77
      Width = 121
      Height = 28
      TabOrder = 5
    end
    object Button1: TButton
      Left = 189
      Top = 318
      Width = 105
      Height = 37
      Caption = #20445#23384
      ModalResult = 2
      TabOrder = 6
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 309
      Top = 318
      Width = 97
      Height = 37
      Caption = #21462#28040
      ModalResult = 2
      TabOrder = 7
      OnClick = Button2Click
    end
    object memo: TMemo
      Left = 80
      Top = 213
      Width = 326
      Height = 89
      Lines.Strings = (
        '')
      TabOrder = 8
    end
  end
  object adoaq: TADOQuery
    Parameters = <>
    Left = 192
    Top = 120
  end
end
