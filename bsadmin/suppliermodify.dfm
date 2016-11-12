object frmsuppliermodify: Tfrmsuppliermodify
  Left = 0
  Top = 0
  Caption = #20379#24212#21830#20462#25913
  ClientHeight = 540
  ClientWidth = 847
  Color = cl3DLight
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poMainFormCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object RzToolbar1: TRzToolbar
    Left = 0
    Top = 0
    Width = 847
    Height = 29
    Images = ImageList1
    ButtonWidth = 60
    ShowButtonCaptions = True
    TextOptions = ttoSelectiveTextOnRight
    BorderInner = fsNone
    BorderOuter = fsGroove
    BorderSides = [sdTop]
    BorderWidth = 0
    Color = cl3DLight
    TabOrder = 0
    VisualStyle = vsClassic
    ToolbarControls = (
      BtnChangeOptions
      BtnVerticalTile
      BtnExit)
    object BtnExit: TRzToolButton
      Left = 152
      Top = 2
      Hint = 'Exit'
      DisabledIndex = 1
      ImageIndex = 0
      Caption = #36864#20986
      OnClick = BtnExitClick
    end
    object BtnChangeOptions: TRzToolButton
      Left = 4
      Top = 2
      Hint = 'Change Options'
      DisabledIndex = 3
      ImageIndex = 2
      Caption = #20462#25913
      OnClick = BtnChangeOptionsClick
    end
    object BtnVerticalTile: TRzToolButton
      Left = 64
      Top = 2
      Width = 88
      Hint = 'Vertical Tile'
      DisabledIndex = 5
      ImageIndex = 4
      Caption = #21512#24182#20379#24212#21830
      Color = cl3DLight
      Visible = False
      OnClick = BtnVerticalTileClick
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 29
    Width = 847
    Height = 511
    Align = alClient
    Color = cl3DLight
    ParentBackground = False
    TabOrder = 1
    object GroupBox1: TGroupBox
      Left = 25
      Top = 6
      Width = 377
      Height = 57
      Caption = #26597#35810#26465#20214
      Color = cl3DLight
      ParentBackground = False
      ParentColor = False
      TabOrder = 0
      object cbQueryType: TRzComboBox
        Left = 65
        Top = 42
        Width = 81
        Height = 21
        ItemHeight = 13
        TabOrder = 0
        Text = #26465#30721
        Visible = False
        OnClick = cbQueryTypeClick
        Items.Strings = (
          #26465#30721
          #20070#21495
          #33258#32534#30721
          #20070#21517)
        ItemIndex = 0
        Values.Strings = (
          '1'
          '2'
          '3'
          '4')
      end
      object edtQuery: TEdit
        Left = 173
        Top = 42
        Width = 229
        Height = 19
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 1
        Visible = False
        OnKeyPress = edtQueryKeyPress
      end
    end
    object GroupBox2: TGroupBox
      Left = 488
      Top = 6
      Width = 321
      Height = 57
      Caption = #20379#24212#21830
      Color = cl3DLight
      ParentBackground = False
      ParentColor = False
      TabOrder = 1
      object lblSupplier: TRzLabel
        Left = 19
        Top = 20
        Width = 108
        Height = 13
        Caption = #36873#25321#35201#20462#25913#30340#20379#24212#21830
        BlinkIntervalOff = 600
        BlinkIntervalOn = 600
      end
      object sbnewcustomer: TSpeedButton
        Left = 286
        Top = 21
        Width = 23
        Height = 19
        Caption = '....'
        Flat = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        Visible = False
      end
      object cbsupplier: TComboBox
        Left = 141
        Top = 20
        Width = 145
        Height = 21
        ItemHeight = 0
        TabOrder = 0
      end
    end
    object dgdetail: TDBGrid
      Left = 25
      Top = 85
      Width = 801
      Height = 388
      DataSource = ds
      FixedColor = cl3DLight
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgMultiSelect]
      TabOrder = 2
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
      Columns = <
        item
          Expanded = False
          FieldName = 'ISBN'
          Width = 80
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'Name'
          Title.Caption = #20070#21517
          Width = 133
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'UserDefCode'
          Title.Caption = #33258#32534#30721
          Width = 79
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'Barcode'
          Title.Caption = #26465#30721
          Width = 70
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'Price'
          Title.Caption = #23450#20215
          Width = 76
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'Amount'
          Title.Caption = #24211#23384
          Width = 72
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'SupplierName'
          Title.Caption = #20379#24212#21830
          Width = 73
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'fullname'
          Title.Caption = #20986#29256#31038
          Width = 74
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'Author'
          Title.Caption = #20316#32773
          Visible = True
        end>
    end
    object cbheader: TCheckBox
      Left = 71
      Top = 25
      Width = 64
      Height = 17
      Caption = #21333#22836
      Checked = True
      Color = cl3DLight
      ParentColor = False
      State = cbChecked
      TabOrder = 3
      OnClick = cbheaderClick
    end
    object edntheader: TEdit
      Left = 135
      Top = 21
      Width = 210
      Height = 21
      NumbersOnly = True
      TabOrder = 4
      OnKeyPress = edntheaderKeyPress
    end
  end
  object cbdetail: TCheckBox
    Left = 41
    Top = 91
    Width = 43
    Height = 17
    Caption = #26126#32454
    TabOrder = 2
    Visible = False
    OnClick = cbdetailClick
  end
  object ImageList1: TImageList
    Left = 768
    Top = 8
    Bitmap = {
      494C010106000A00080010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000002000000001002000000000000020
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF330000FF330000FF330000FF33
      0000FF330000FF330000FF330000FF330000FF330000FF330000FF330000FF33
      0000FF330000FF330000FF330000000000009999990099999900999999009999
      9900999999009999990099999900999999009999990099999900999999009999
      9900999999009999990099999900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF330000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FF330000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FF330000000000009999990000000000000000000000
      0000000000000000000000000000999999000000000000000000000000000000
      0000000000000000000099999900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF330000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FF330000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FF330000000000009999990000000000000000000000
      0000000000000000000000000000999999000000000000000000000000000000
      0000000000000000000099999900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF330000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FF330000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FF330000000000009999990000000000000000000000
      0000000000000000000000000000999999000000000000000000000000000000
      0000000000000000000099999900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF330000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FF330000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FF330000000000009999990000000000000000000000
      0000000000000000000000000000999999000000000000000000000000000000
      0000000000000000000099999900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF330000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FF330000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FF330000000000009999990000000000000000000000
      0000000000000000000000000000999999000000000000000000000000000000
      0000000000000000000099999900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF330000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FF330000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FF330000000000009999990000000000000000000000
      0000000000000000000000000000999999000000000000000000000000000000
      0000000000000000000099999900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF330000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FF330000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FF330000000000009999990000000000000000000000
      0000000000000000000000000000999999000000000000000000000000000000
      0000000000000000000099999900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF330000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FF330000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FF330000000000009999990000000000000000000000
      0000000000000000000000000000999999000000000000000000000000000000
      0000000000000000000099999900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF330000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FF330000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FF330000000000009999990000000000000000000000
      0000000000000000000000000000999999000000000000000000000000000000
      0000000000000000000099999900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF330000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FF330000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FF330000000000009999990000000000000000000000
      0000000000000000000000000000999999000000000000000000000000000000
      0000000000000000000099999900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF330000FF330000FF330000FF33
      0000FF330000FF330000FF330000FF330000FF330000FF330000FF330000FF33
      0000FF330000FF330000FF330000000000009999990099999900999999009999
      9900999999009999990099999900999999009999990099999900999999009999
      9900999999009999990099999900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF330000FF330000FF330000FF33
      0000FFCC9900FF3300006666FF00FF330000FF330000FF330000FF330000FFCC
      9900FF3300006666FF00FF330000000000009999990099999900999999009999
      9900CCCCCC0099999900CCCCCC0099999900999999009999990099999900CCCC
      CC0099999900CCCCCC0099999900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFCC9900FF330000FF330000FF33
      0000FF330000FF330000FF330000FFCC9900FF330000FF330000FF330000FF33
      0000FF330000FF330000FFCC990000000000CCCCCC0099999900999999009999
      9900999999009999990099999900CCCCCC009999990099999900999999009999
      99009999990099999900CCCCCC00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000E2EFF100000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000E2EFF100000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000E2EF
      F100E5E5E500CCCCCC00E5E5E500E2EFF1000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000E2EF
      F10000000000CCCCCC00E5E5E500E2EFF1000000000000000000000000000000
      000000000000000000000000000000000000CC996600CC996600CC996600CC99
      6600CC996600CC996600CC996600CC996600CC996600CC996600CC996600CC99
      6600CC996600CC996600CC996600CC9966009999990099999900999999009999
      9900999999009999990099999900999999009999990099999900999999009999
      99009999990099999900999999009999990000000000E2EFF100E5E5E500B2B2
      B200CC9999009966660099666600B2B2B200CCCCCC00E5E5E500E2EFF1000000
      00000000000000000000000000000000000000000000E2EFF10000000000B2B2
      B200999999009999990099999900B2B2B200CCCCCC0000000000E2EFF1000000
      000000000000000000000000000000000000CC996600FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00CC9966009999990000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000099999900E5E5E500CC99990099666600CC99
      9900CC999900FFFFFF00996666009999990099999900B2B2B200E5E5E5000000
      0000000000000000000000000000000000000000000099999900999999009999
      990099999900FFFFFF00999999009999990099999900B2B2B200000000000000
      000000000000000000000000000000000000CC996600FFFFFF00CC996600CC99
      6600CC996600CC996600FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00CC9966009999990000000000999999009999
      9900999999009999990000000000000000000000000000000000000000000000
      00000000000000000000000000009999990099666600CC999900FFCC9900FFCC
      9900FFCCCC00FFFFFF0099666600336699003366990033669900E2EFF1000000
      0000000000000000000000000000000000009999990099999900C0C0C000C0C0
      C000CCCCCC00FFFFFF0099999900999999009999990099999900E2EFF1000000
      000000000000000000000000000000000000CC996600FFFFFF00CC996600FFFF
      FF00FFFFFF00CC996600FFFFFF00993300009933000099330000993300009933
      00009933000099330000FFFFFF00CC9966009999990000000000999999000000
      0000000000009999990000000000999999009999990099999900999999009999
      99009999990099999900000000009999990099666600FFCC9900FFCC9900FFCC
      9900FFCCCC00FFFFFF009966660066CCCC0066CCCC000099CC00FFFFFF00FFCC
      CC000000000000000000000000000000000099999900C0C0C000C0C0C000C0C0
      C000CCCCCC00FFFFFF0099999900C0C0C000C0C0C00099999900FFFFFF00CCCC
      CC0000000000000000000000000000000000CC996600FFFFFF00CC996600FFFF
      FF00FFFFFF00CC996600FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00CC9966009999990000000000999999000000
      0000000000009999990000000000000000000000000000000000000000000000
      00000000000000000000000000009999990099666600FFCC9900FFCC9900FFCC
      9900FFCCCC00FFFFFF009966660066CCCC0066CCFF003399CC00FFCCCC00CC66
      00000000000000000000000000000000000099999900C0C0C000C0C0C000C0C0
      C000CCCCCC00FFFFFF0099999900C0C0C000CCCCCC0099999900CCCCCC009999
      990000000000000000000000000000000000CC996600FFFFFF00CC996600CC99
      6600CC996600CC996600FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00CC9966009999990000000000999999009999
      9900999999009999990000000000000000000000000000000000000000000000
      00000000000000000000000000009999990099666600FFCC9900CC999900CC99
      6600FFCCCC00FFFFFF009966660099CCCC0099CCFF00B2B2B200FF660000CC66
      00000000000000000000000000000000000099999900C0C0C000999999009999
      9900CCCCCC00FFFFFF0099999900CCCCCC00CCCCCC00B2B2B200999999009999
      990000000000000000000000000000000000CC996600FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00CC9966009999990000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000009999990099666600FFCC990099666600FFFF
      FF00FFCCCC00FFFFFF009966660099CCCC00C0C0C000CC660000CC660000CC66
      0000CC660000CC660000CC6600000000000099999900C0C0C00066666600FFFF
      FF00CCCCCC00FFFFFF0099999900CCCCCC00C0C0C00099999900999999009999
      990099999900999999009999990000000000CC996600FFFFFF00CC996600CC99
      6600CC996600CC996600FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00CC9966009999990000000000999999009999
      9900999999009999990000000000000000000000000000000000000000000000
      00000000000000000000000000009999990099666600FFCC9900CC9999009966
      6600FFCCCC00FFFFFF009966660000000000CC660000CC660000CC660000CC66
      0000CC660000CC660000CC6600000000000099999900C0C0C000999999006666
      6600CCCCCC00FFFFFF0099999900E5E5E5009999990099999900999999009999
      990099999900999999009999990000000000CC996600FFFFFF00CC996600FFFF
      FF00FFFFFF00CC996600FFFFFF00993300009933000099330000993300009933
      00009933000099330000FFFFFF00CC9966009999990000000000999999000000
      0000000000009999990000000000999999009999990099999900999999009999
      99009999990099999900000000009999990099666600FFCC9900FFCC9900FFCC
      9900FFCCCC00FFFFFF009966660000000000CC999900CC660000CC660000CC66
      0000CC660000CC660000CC6600000000000099999900C0C0C000C0C0C000C0C0
      C000CCCCCC00FFFFFF0099999900E5E5E5009999990099999900999999009999
      990099999900999999009999990000000000CC996600FFFFFF00CC996600FFFF
      FF00FFFFFF00CC996600FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00CC9966009999990000000000999999000000
      0000000000009999990000000000000000000000000000000000000000000000
      00000000000000000000000000009999990099666600FFCC9900FFCC9900FFCC
      9900FFCCCC00FFFFFF0099666600CCCCCC00E2EFF100CC999900FF660000CC66
      00000000000000000000000000000000000099999900C0C0C000C0C0C000C0C0
      C000CCCCCC00FFFFFF0099999900CCCCCC00E2EFF10099999900999999009999
      990000000000000000000000000000000000CC996600FFFFFF00CC996600CC99
      6600CC996600CC996600FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00CC9966009999990000000000999999009999
      9900999999009999990000000000000000000000000000000000000000000000
      00000000000000000000000000009999990099666600FFCC9900FFCC9900FFCC
      9900FFCCCC00FFFFFF009966660099CCCC000000000099CCCC00FFCC9900CC66
      00000000000000000000000000000000000099999900C0C0C000C0C0C000C0C0
      C000CCCCCC00FFFFFF0099999900CCCCCC00E5E5E500CCCCCC00C0C0C0009999
      990000000000000000000000000000000000CC996600FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00CC9966009999990000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000009999990099666600CC999900FFCC9900FFCC
      9900FFCCCC00FFFFFF0099666600CCCCCC00000000003399CC0000000000FFCC
      9900000000000000000000000000000000009999990099999900C0C0C000C0C0
      C000CCCCCC00FFFFFF0099999900CCCCCC00E5E5E5009999990000000000C0C0
      C00000000000000000000000000000000000CC996600FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00CC996600CC996600CC996600CC996600CC996600CC99
      6600CC996600CC996600CC996600CC9966009999990000000000000000000000
      0000000000000000000099999900999999009999990099999900999999009999
      99009999990099999900999999009999990000000000C0C0C000CC996600CC99
      9900CCCC9900FFFFFF00996666000099CC000099CC000099CC00000000000000
      00000000000000000000000000000000000000000000C0C0C000999999009999
      9900C0C0C000FFFFFF0099999900999999009999990099999900000000000000
      000000000000000000000000000000000000CC996600FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC996600CC996600CCCCCC00CCCCCC00CCCCCC00CCCCCC00CC99
      6600000000000000000000000000000000009999990000000000000000000000
      0000000000009999990099999900CCCCCC00CCCCCC00CCCCCC00CCCCCC009999
      990000000000000000000000000000000000000000000000000000000000CCCC
      CC00CC9999009966660099666600000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000CCCC
      CC00999999009999990099999900000000000000000000000000000000000000
      00000000000000000000000000000000000000000000CC996600CC996600CC99
      6600CC9966000000000000000000CC996600CC996600CC996600CC9966000000
      0000000000000000000000000000000000000000000099999900999999009999
      9900999999000000000000000000999999009999990099999900999999000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000200000000100010000000000000100000000000000000000
      000000000000000000000000FFFFFF00FFFFFFFF000000000001000100000000
      00017EFD0000000000017EFD0000000000017EFD0000000000017EFD00000000
      00017EFD0000000000017EFD0000000000017EFD0000000000017EFD00000000
      00017EFD0000000000017EFD0000000000010001000000000001000100000000
      0001000100000000FFFFFFFF00000000FDFFFDFFFFFFFFFFE0FFE8FF00000000
      801FA05F00007FFE001F803F000043FE001F001F00005A02000F000F00005BFE
      000F000F000043FE000F000F00007FFE00010001000043FE0101000100005A02
      0101000100005BFE000F000F000043FE008F000F00007FFE00AF002F00007C00
      803F803F000F780FE1FFE1FF861F861F00000000000000000000000000000000
      000000000000}
  end
  object ds: TDataSource
    DataSet = aq
    Left = 160
    Top = 152
  end
  object aq: TADOQuery
    Parameters = <>
    Left = 136
    Top = 264
  end
  object con: TADOConnection
    Left = 360
    Top = 192
  end
  object query: TADOQuery
    Parameters = <>
    Left = 752
    Top = 96
  end
end
