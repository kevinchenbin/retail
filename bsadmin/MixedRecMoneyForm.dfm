inherited frmMixedRecMoney: TfrmMixedRecMoney
  Caption = #28151#21512#25910#27454
  ClientHeight = 290
  ClientWidth = 279
  Font.Charset = ANSI_CHARSET
  Font.Height = -12
  Font.Name = #24494#36719#38597#40657
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  ExplicitWidth = 285
  ExplicitHeight = 318
  PixelsPerInch = 96
  TextHeight = 17
  object RzLabel1: TRzLabel [0]
    Left = 8
    Top = 11
    Width = 48
    Height = 17
    Caption = #24212#25910#37329#39069
    BlinkIntervalOff = 600
    BlinkIntervalOn = 600
  end
  inherited Panel2: TPanel
    Width = 279
    Height = 290
    Align = alClient
    Ctl3D = False
    ParentBackground = False
    ParentCtl3D = False
    ExplicitWidth = 279
    ExplicitHeight = 290
    object Label1: TLabel [0]
      Left = 34
      Top = 19
      Width = 56
      Height = 19
      Caption = #24212#25910#37329#39069
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -14
      Font.Name = #24494#36719#38597#40657
      Font.Style = [fsBold]
      ParentFont = False
    end
    object RzLabel2: TRzLabel [1]
      Left = 27
      Top = 107
      Width = 63
      Height = 19
      Caption = #20648#20540#21345'(&A)'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -14
      Font.Name = #24494#36719#38597#40657
      Font.Style = [fsBold]
      ParentFont = False
      Transparent = True
      BlinkIntervalOff = 600
      BlinkIntervalOn = 600
    end
    object RzLabel3: TRzLabel [2]
      Left = 42
      Top = 212
      Width = 48
      Height = 19
      Caption = #29616#37329'(&X)'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -14
      Font.Name = #24494#36719#38597#40657
      Font.Style = [fsBold]
      ParentFont = False
      Transparent = True
      BlinkIntervalOff = 600
      BlinkIntervalOn = 600
    end
    object lbl1: TRzLabel [3]
      Left = 20
      Top = 73
      Width = 70
      Height = 19
      Caption = #20648#20540#21345#20313#39069
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -14
      Font.Name = #24494#36719#38597#40657
      Font.Style = [fsBold]
      ParentFont = False
      Transparent = True
      BlinkIntervalOff = 600
      BlinkIntervalOn = 600
    end
    object RzLine1: TRzLine [4]
      Left = 8
      Top = 44
      Width = 257
      Height = 20
    end
    object RzLabel4: TRzLabel [5]
      Left = 30
      Top = 141
      Width = 60
      Height = 19
      Caption = #20248#24800#21048'(&S)'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -14
      Font.Name = #24494#36719#38597#40657
      Font.Style = [fsBold]
      ParentFont = False
      Transparent = True
      BlinkIntervalOff = 600
      BlinkIntervalOn = 600
    end
    object RzLabel5: TRzLabel [6]
      Left = 29
      Top = 176
      Width = 61
      Height = 19
      Caption = #38134#34892#21345'(&Z)'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -14
      Font.Name = #24494#36719#38597#40657
      Font.Style = [fsBold]
      ParentFont = False
      Transparent = True
      BlinkIntervalOff = 600
      BlinkIntervalOn = 600
    end
    inherited btnOk: TRzButton
      Left = 91
      Top = 245
      Width = 76
      Height = 35
      Caption = #30830#35748'(Ent)'
      Color = 16180174
      Font.Charset = ANSI_CHARSET
      Font.Height = -14
      Font.Name = #24494#36719#38597#40657
      Font.Style = [fsBold]
      ParentFont = False
      OnClick = btnOkClick
      ExplicitLeft = 91
      ExplicitTop = 245
      ExplicitWidth = 76
      ExplicitHeight = 35
    end
    inherited btnCancel: TRzButton
      Left = 174
      Top = 245
      Width = 76
      Height = 35
      Caption = #21462#28040'(Esc)'
      Color = 16180174
      Font.Charset = ANSI_CHARSET
      Font.Height = -14
      Font.Name = #24494#36719#38597#40657
      Font.Style = [fsBold]
      ParentFont = False
      ExplicitLeft = 174
      ExplicitTop = 245
      ExplicitWidth = 76
      ExplicitHeight = 35
    end
    object numedtCard: TRzNumericEdit
      Left = 110
      Top = 105
      Width = 140
      Height = 25
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -14
      Font.Name = #24494#36719#38597#40657
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      OnExit = numedtCardExit
      OnKeyPress = numedtCardKeyPress
      IntegersOnly = False
      DisplayFormat = '###,##0.0;'
    end
    object numedtCash: TRzNumericEdit
      Left = 110
      Top = 210
      Width = 140
      Height = 25
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -14
      Font.Name = #24494#36719#38597#40657
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      OnClick = numedtCashClick
      OnKeyPress = numedtCashKeyPress
      IntegersOnly = False
      DisplayFormat = '###,##0.0;'
    end
    object numedtRemain: TRzNumericEdit
      Left = 110
      Top = 71
      Width = 140
      Height = 25
      Color = clInfoBk
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -14
      Font.Name = #24494#36719#38597#40657
      Font.Style = [fsBold]
      ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
      ParentFont = False
      ReadOnly = True
      TabOrder = 4
      OnKeyPress = numedtCardKeyPress
      IntegersOnly = False
      DisplayFormat = '###,##0.0;'
    end
    object numedtyouhui: TRzNumericEdit
      Left = 110
      Top = 139
      Width = 140
      Height = 25
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -14
      Font.Name = #24494#36719#38597#40657
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 5
      OnExit = numedtyouhuiExit
      OnKeyPress = numedtyouhuiKeyPress
      IntegersOnly = False
      DisplayFormat = '###,##0.0;'
    end
    object numedtposcard: TRzNumericEdit
      Left = 110
      Top = 174
      Width = 140
      Height = 25
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -14
      Font.Name = #24494#36719#38597#40657
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 6
      OnExit = numedtposcardExit
      OnKeyPress = numedtposcardKeyPress
      IntegersOnly = False
      DisplayFormat = '###,##0.0;'
    end
  end
  object numedtMustRecMoney: TRzNumericEdit
    Left = 110
    Top = 17
    Width = 140
    Height = 25
    Color = clInfoBk
    Ctl3D = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = #24494#36719#38597#40657
    Font.Style = [fsBold]
    ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    ParentCtl3D = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 1
    DisplayFormat = '###,##0.0'
  end
end
