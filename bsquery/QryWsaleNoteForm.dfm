inherited frmQryWsaleNote: TfrmQryWsaleNote
  Caption = #21457#36135#26597#35810
  ExplicitTop = -328
  PixelsPerInch = 96
  TextHeight = 13
  inherited rztlbr1: TRzToolbar
    ToolbarControls = (
      tlbtnQry
      tlbtnExport
      BtnAlignBottom
      tlbtnExit)
    inherited tlbtnQry: TRzToolButton
      ParentFont = False
    end
    inherited tlbtnExport: TRzToolButton
      ParentFont = False
    end
    inherited tlbtnExit: TRzToolButton
      ParentFont = False
    end
    inherited BtnAlignBottom: TRzToolButton
      ParentFont = False
    end
  end
  inherited grpbx1: TRzGroupBox
    inherited lbl1: TLabel
      Left = 393
      ExplicitLeft = 393
    end
    inherited lbl2: TLabel
      Left = 460
      ExplicitLeft = 460
    end
    inherited lbl3: TLabel
      Left = 393
      ExplicitLeft = 393
    end
    inherited lbl4: TLabel
      Left = 460
      ExplicitLeft = 460
    end
    inherited Label36: TLabel
      Left = 393
      ExplicitLeft = 393
    end
    inherited Label37: TLabel
      Left = 460
      ExplicitLeft = 460
    end
    inherited SpeedButton1: TSpeedButton
      Left = 860
      Top = 49
      Height = 23
      Visible = False
      ExplicitLeft = 860
      ExplicitTop = 49
      ExplicitHeight = 23
    end
    inherited chckbxStartTime: TRzCheckBox
      Left = 3
      Top = 17
      ExplicitLeft = 3
      ExplicitTop = 17
    end
    inherited chckbxEndTime: TRzCheckBox
      Left = 3
      ExplicitLeft = 3
    end
    inherited chckbxBookName: TRzCheckBox
      Left = 175
      ExplicitLeft = 175
    end
    inherited chckbxISBN: TRzCheckBox
      Left = 175
      ExplicitLeft = 175
    end
    inherited chckbxCustomer: TRzCheckBox
      Left = 346
      Top = 106
      Width = 43
      Caption = #23458#25143
      ExplicitLeft = 346
      ExplicitTop = 106
      ExplicitWidth = 43
    end
    inherited chckbxBkstack: TRzCheckBox
      Left = 678
      ExplicitLeft = 678
    end
    inherited chckbxUserDefNum: TRzCheckBox
      Left = 3
      Top = 78
      ExplicitLeft = 3
      ExplicitTop = 78
    end
    inherited chckbxPrice: TRzCheckBox
      Left = 346
      ExplicitLeft = 346
    end
    inherited chckbxAuthor: TRzCheckBox
      Left = 175
      ExplicitLeft = 175
    end
    inherited chckbxAmount: TRzCheckBox
      Left = 346
      ExplicitLeft = 346
    end
    inherited chckbxPress: TRzCheckBox
      Left = 678
      Top = 16
      ExplicitLeft = 678
      ExplicitTop = 16
    end
    inherited chckbxType: TRzCheckBox
      Left = 678
      Top = 106
      ExplicitLeft = 678
      ExplicitTop = 106
    end
    inherited chckbxRemarks: TRzCheckBox
      Left = 864
      Top = 47
      ExplicitLeft = 864
      ExplicitTop = 47
    end
    inherited chckbxStorage: TRzCheckBox
      Left = 678
      ExplicitLeft = 678
    end
    inherited edtBookName: TRzEdit
      Left = 221
      Width = 115
      ExplicitLeft = 221
      ExplicitWidth = 115
    end
    inherited edtISBN: TRzEdit
      Left = 221
      Width = 115
      ExplicitLeft = 221
      ExplicitWidth = 115
    end
    inherited edtUserDefNum: TRzEdit
      Left = 73
      ExplicitLeft = 73
    end
    inherited edtAuthor: TRzEdit
      Left = 221
      Width = 115
      ExplicitLeft = 221
      ExplicitWidth = 115
    end
    inherited edtPress: TRzEdit
      Left = 724
      Top = 14
      ExplicitLeft = 724
      ExplicitTop = 14
    end
    inherited edtRemarks: TRzEdit
      Left = 909
      Top = 45
      Width = 92
      ExplicitLeft = 909
      ExplicitTop = 45
      ExplicitWidth = 92
    end
    inherited edtCustomer: TRzEdit
      Left = 413
      Width = 45
      OnKeyPress = edtCustomerKeyPress
      ExplicitLeft = 413
      ExplicitWidth = 45
    end
    inherited numedtMinPrice: TRzNumericEdit
      Left = 413
      Width = 45
      ExplicitLeft = 413
      ExplicitWidth = 45
    end
    inherited numedtMinAmount: TRzNumericEdit
      Left = 413
      Width = 45
      ExplicitLeft = 413
      ExplicitWidth = 45
    end
    inherited numedtMaxPrice: TRzNumericEdit
      Left = 482
      Width = 45
      ExplicitLeft = 482
      ExplicitWidth = 45
    end
    inherited numedtMaxAmount: TRzNumericEdit
      Left = 482
      Width = 45
      ExplicitLeft = 482
      ExplicitWidth = 45
    end
    inherited dblkpcbbCustomer: TRzDBLookupComboBox
      Left = 457
      Width = 212
      ExplicitLeft = 457
      ExplicitWidth = 212
    end
    inherited dblkpcbbStorage: TRzDBLookupComboBox
      Left = 724
      Width = 130
      ExplicitLeft = 724
      ExplicitWidth = 130
    end
    inherited dblkpcbbBookstack: TRzDBLookupComboBox
      Left = 724
      Width = 130
      ExplicitLeft = 724
      ExplicitWidth = 130
    end
    inherited cboutstorage: TRzCheckBox
      Left = 585
      Top = 139
      ExplicitLeft = 585
      ExplicitTop = 139
    end
    inherited cbreturnstorage: TCheckBox
      Left = 881
      Top = 242
      ExplicitLeft = 881
      ExplicitTop = 242
    end
    inherited cbinstorage: TRzCheckBox
      Left = 474
      Top = 139
      Caption = #21457#36135
      ExplicitLeft = 474
      ExplicitTop = 139
    end
    inherited cblost: TCheckBox
      Left = 773
      Top = 242
      ExplicitLeft = 773
      ExplicitTop = 242
    end
    inherited cbdamage: TCheckBox
      Left = 825
      Top = 242
      ExplicitLeft = 825
      ExplicitTop = 242
    end
    inherited chdiscount: TCheckBox
      Left = 346
      ExplicitLeft = 346
    end
    inherited edmaxdiscount: TEdit
      Left = 482
      Width = 45
      ExplicitLeft = 482
      ExplicitWidth = 45
    end
    inherited chstaff: TCheckBox
      Left = 536
      ExplicitLeft = 536
    end
    inherited cbstaff: TComboBox
      Left = 593
      Top = 13
      Width = 76
      ExplicitLeft = 593
      ExplicitTop = 13
      ExplicitWidth = 76
    end
    inherited chnocheck: TCheckBox
      Left = 654
      Top = 139
      ExplicitLeft = 654
      ExplicitTop = 139
    end
    inherited chcheckpart: TCheckBox
      Left = 727
      Top = 139
      ExplicitLeft = 727
      ExplicitTop = 139
    end
    inherited chchecked: TCheckBox
      Left = 800
      Top = 139
      ExplicitLeft = 800
      ExplicitTop = 139
    end
    inherited edmindiscount: TEdit
      Left = 413
      Width = 45
      ExplicitLeft = 413
      ExplicitWidth = 45
    end
    inherited chjytype: TCheckBox
      Left = 536
      Top = 78
      ExplicitLeft = 536
      ExplicitTop = 78
    end
    inherited cbjytype: TComboBox
      Left = 593
      Top = 74
      Width = 76
      ExplicitLeft = 593
      ExplicitTop = 74
      ExplicitWidth = 76
    end
    inherited dblkpcbbPress: TRzDBLookupComboBox
      Left = 760
      Top = 14
      Width = 94
      ExplicitLeft = 760
      ExplicitTop = 14
      ExplicitWidth = 94
    end
    inherited dtedtStart: TRzDateTimePicker
      Left = 73
      ExplicitLeft = 73
    end
    inherited dtedtEnd: TRzDateTimePicker
      Left = 73
      ExplicitLeft = 73
    end
    inherited chdanhao: TRzCheckBox
      Left = 864
      Top = 78
      ExplicitLeft = 864
      ExplicitTop = 78
    end
    inherited eddanhao: TRzEdit
      Left = 909
      Top = 75
      Width = 92
      ExplicitLeft = 909
      ExplicitTop = 75
      ExplicitWidth = 92
    end
    inherited chrktype: TCheckBox
      Left = 536
      Caption = #21457#36135#31867
      ExplicitLeft = 536
    end
    inherited cbrktype: TComboBox
      Left = 593
      Width = 76
      TabOrder = 58
      Text = #19968#33324#21457#36135
      Items.Strings = (
        #19968#33324#21457#36135
        #26679#20070#21457#36135)
      ExplicitLeft = 593
      ExplicitWidth = 76
    end
    inherited chsuptype: TCheckBox
      Left = 864
      Top = 17
      Caption = #23458#25143#31867
      TabOrder = 55
      ExplicitLeft = 864
      ExplicitTop = 17
    end
    inherited cbsuptype: TComboBox
      Left = 922
      Top = 13
      Width = 79
      TabOrder = 56
      ExplicitLeft = 922
      ExplicitTop = 13
      ExplicitWidth = 79
    end
    inherited edtyname: TEdit
      Left = 760
      Width = 94
      TabOrder = 57
      ExplicitLeft = 760
      ExplicitWidth = 94
    end
    inherited edpyquery: TEdit
      Left = 724
      ExplicitLeft = 724
    end
    inherited cbcaigou: TCheckBox
      Left = 864
      Top = 142
      Visible = False
      ExplicitLeft = 864
      ExplicitTop = 142
    end
    object chckbx1: TRzCheckBox
      Left = 3
      Top = 106
      Width = 55
      Height = 19
      Caption = #20379#24212#21830
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #24494#36719#38597#40657
      Font.Style = []
      ParentFont = False
      State = cbUnchecked
      TabOrder = 49
    end
    object dblkpcbbSupplierID: TRzDBLookupComboBox
      Left = 113
      Top = 105
      Width = 223
      Height = 23
      Ctl3D = False
      DataField = 'SupplierID'
      KeyField = 'ID'
      ListField = 'Name'
      ListSource = dsrcSupplier
      ParentCtl3D = False
      TabOrder = 50
      OnClick = dblkpcbbSupplierIDClick
      FrameStyle = fsNone
    end
    object edsuplier: TEdit
      Left = 73
      Top = 105
      Width = 41
      Height = 23
      AutoSize = False
      Ctl3D = False
      ImeName = #29579#30721#20116#31508#22411#36755#20837#27861'86'#29256
      ParentCtl3D = False
      TabOrder = 51
      OnKeyPress = edsuplierKeyPress
    end
    object chandan: TCheckBox
      Left = 346
      Top = 139
      Width = 70
      Height = 17
      Caption = #26126#32454#25353#21333
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #24494#36719#38597#40657
      Font.Style = []
      ParentFont = False
      TabOrder = 52
      Visible = False
    end
    object cbquyue: TRzCheckBox
      Left = 864
      Top = 106
      Width = 43
      Height = 19
      Caption = #21306#22495
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #24494#36719#38597#40657
      Font.Style = []
      ParentFont = False
      State = cbUnchecked
      TabOrder = 59
    end
    object cbqueyueselect: TComboBox
      Left = 909
      Top = 103
      Width = 92
      Height = 25
      BevelKind = bkFlat
      Ctl3D = False
      ItemHeight = 17
      ParentCtl3D = False
      TabOrder = 60
      OnChange = cbqueyueselectChange
      OnClick = cbsuptypeClick
    end
    object cbjinge: TRzCheckBox
      Left = 4
      Top = 135
      Width = 43
      Height = 19
      Caption = #37329#39069
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #24494#36719#38597#40657
      Font.Style = []
      ParentFont = False
      State = cbUnchecked
      TabOrder = 61
    end
    object nejinge: TRzNumericEdit
      Left = 73
      Top = 134
      Width = 95
      Height = 23
      Ctl3D = False
      ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
      ParentCtl3D = False
      TabOrder = 62
      OnChange = numedtMinPriceChange
      AllowBlank = True
      IntegersOnly = False
      DisplayFormat = '###,##0.00'
    end
  end
  inherited pgcntrlResult: TRzPageControl
    OnChange = pgcntrlResultChange
    FixedDimension = 23
    inherited tbshtByNtHeader: TRzTabSheet
      ExplicitLeft = 1
      ExplicitTop = 24
      ExplicitWidth = 1008
      ExplicitHeight = 484
      inherited dbgrdByNtHeader: TDBGridEh
        Columns = <
          item
            Alignment = taCenter
            EditButtons = <>
            FieldName = 'xuhao'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #24207
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 30
          end
          item
            EditButtons = <>
            FieldName = 'Code'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #21333#21495
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 100
          end
          item
            EditButtons = <>
            FieldName = 'CodeStr'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #21333#21495
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 100
          end
          item
            EditButtons = <>
            FieldName = 'CustomerName'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #23458#25143#21517#31216
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 150
          end
          item
            EditButtons = <>
            FieldName = 'Date'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #26085#26399
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 70
          end
          item
            EditButtons = <>
            FieldName = 'FixedPrice'
            Footer.FieldName = 'FixedPrice'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #30721#27915
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 65
          end
          item
            EditButtons = <>
            FieldName = 'DiscountedPrice'
            Footer.FieldName = 'DiscountedPrice'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #23454#27915
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 65
          end
          item
            EditButtons = <>
            FieldName = 'salecbprice'
            Footer.FieldName = 'salecbprice'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #25104#26412
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 65
          end
          item
            EditButtons = <>
            FieldName = 'profite'
            Footer.FieldName = 'profite'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #27611#21033
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 65
          end
          item
            EditButtons = <>
            FieldName = 'Amount'
            Footer.FieldName = 'Amount'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #25968#37327
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 35
          end
          item
            EditButtons = <>
            FieldName = 'checked'
            Footer.FieldName = 'checked'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #24050#32467
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 65
          end
          item
            EditButtons = <>
            FieldName = 'nochecked'
            Footer.FieldName = 'nochecked'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #26410#32467
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 65
          end
          item
            EditButtons = <>
            FieldName = 'Remarks'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #22791#27880
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 120
          end
          item
            EditButtons = <>
            FieldName = 'staffname'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #19994#21153#21592
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 50
          end
          item
            EditButtons = <>
            FieldName = 'Operatorname'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #25805#20316#21592
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 50
          end
          item
            EditButtons = <>
            FieldName = 'StgName'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #24215#21517
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 120
          end
          item
            EditButtons = <>
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #21457#31080
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Visible = False
            Width = 54
          end>
      end
    end
    inherited tbshtByNote: TRzTabSheet
      ExplicitLeft = 1
      ExplicitTop = 24
      ExplicitWidth = 1008
      ExplicitHeight = 484
      inherited dbgrdByNote: TDBGridEh
        PopupMenu = PopupMenu1
        Columns = <
          item
            Alignment = taCenter
            EditButtons = <>
            FieldName = 'xuhao'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #24207
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 30
          end
          item
            EditButtons = <>
            FieldName = 'CustomerName'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #23458#25143#21517#31216
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 120
          end
          item
            EditButtons = <>
            FieldName = 'ISBN'
            Footers = <>
            Title.Alignment = taCenter
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 100
          end
          item
            EditButtons = <>
            FieldName = 'BookName'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #20070#21517
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 200
          end
          item
            EditButtons = <>
            FieldName = 'UserDefCode'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #33258#32534#30721
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 75
          end
          item
            EditButtons = <>
            FieldName = 'Price'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #23450#20215
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 50
          end
          item
            EditButtons = <>
            FieldName = 'FixedPrice'
            Footer.FieldName = 'FixedPrice'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #30721#27915
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 65
          end
          item
            EditButtons = <>
            FieldName = 'DiscountedPrice'
            Footer.FieldName = 'DiscountedPrice'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #23454#27915
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 120
          end
          item
            EditButtons = <>
            FieldName = 'salecbprice'
            Footer.FieldName = 'salecbprice'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #25104#26412
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 65
          end
          item
            EditButtons = <>
            FieldName = 'profite'
            Footer.FieldName = 'profite'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #27611#21033#28070
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 65
          end
          item
            EditButtons = <>
            FieldName = 'Author'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #20316#32773
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 50
          end
          item
            EditButtons = <>
            FieldName = 'PressName'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #29256#21035
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 50
          end
          item
            EditButtons = <>
            FieldName = 'Date'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #21333#25454#26085#26399
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 70
          end
          item
            EditButtons = <>
            FieldName = 'Amount'
            Footer.FieldName = 'Amount'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #25968#37327
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 35
          end
          item
            EditButtons = <>
            FieldName = 'Code'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #21333#21495
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Visible = False
            Width = 100
          end
          item
            EditButtons = <>
            FieldName = 'CodeStr'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #21333#21495
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 100
          end
          item
            EditButtons = <>
            FieldName = 'PosAmount'
            Footer.FieldName = 'PosAmount'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #21457#36135
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Visible = False
            Width = 35
          end
          item
            EditButtons = <>
            FieldName = 'NegAmount'
            Footer.FieldName = 'NegAmount'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #36864#36135
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 35
          end
          item
            EditButtons = <>
            FieldName = 'Discount'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #25240#25187'%'
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 45
          end
          item
            EditButtons = <>
            FieldName = 'PressDate'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #20986#29256#26085#26399
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 70
          end
          item
            EditButtons = <>
            FieldName = 'BktypeName'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #31867#21035
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 60
          end
          item
            EditButtons = <>
            FieldName = 'staffname'
            Footers = <>
            Title.Caption = #19994#21153#21592
            Width = 50
          end
          item
            EditButtons = <>
            FieldName = 'StorageName'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #24215#21517
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 120
          end
          item
            EditButtons = <>
            FieldName = 'bookcatalogid'
            Footers = <>
            Visible = False
          end>
      end
    end
    inherited tbshtByCustomer: TRzTabSheet
      Caption = #23458#25143
      ExplicitLeft = 1
      ExplicitTop = 24
      ExplicitWidth = 1008
      ExplicitHeight = 484
      inherited dbgrdByCustomer: TDBGridEh
        Columns = <
          item
            Alignment = taCenter
            EditButtons = <>
            FieldName = 'xuhao'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #24207
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 30
          end
          item
            EditButtons = <>
            FieldName = 'CustomerName'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #23458#25143#21517#31216
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 200
          end
          item
            EditButtons = <>
            FieldName = 'FixedPrice'
            Footer.FieldName = 'FixedPrice'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #30721#27915
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 65
          end
          item
            EditButtons = <>
            FieldName = 'DiscountedPrice'
            Footer.FieldName = 'DiscountedPrice'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #23454#27915
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 65
          end
          item
            EditButtons = <>
            FieldName = 'salecbprice'
            Footer.FieldName = 'salecbprice'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #25104#26412
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 65
          end
          item
            EditButtons = <>
            FieldName = 'profite'
            Footer.FieldName = 'profite'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #27611#21033
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 65
          end
          item
            EditButtons = <>
            FieldName = 'Amount'
            Footer.FieldName = 'Amount'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #25968#37327
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 50
          end
          item
            EditButtons = <>
            FieldName = 'checked'
            Footer.FieldName = 'checked'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #24050#32467
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 65
          end
          item
            EditButtons = <>
            FieldName = 'nochecked'
            Footer.FieldName = 'nochecked'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #26410#32467
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 65
          end
          item
            EditButtons = <>
            FieldName = 'totalyue'
            Footer.FieldName = 'totalyue'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #20313#39069
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 65
          end
          item
            EditButtons = <>
            FieldName = 'StorageName'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #24215#21517
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 180
          end>
      end
    end
    inherited tbshtByBktype: TRzTabSheet
      ExplicitLeft = 1
      ExplicitTop = 24
      ExplicitWidth = 1008
      ExplicitHeight = 484
      inherited dbgrdByBktype: TDBGridEh
        Columns = <
          item
            Alignment = taCenter
            EditButtons = <>
            FieldName = 'xuhao'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #24207
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 30
          end
          item
            EditButtons = <>
            FieldName = 'BktypeName'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #31867#21035
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 200
          end
          item
            EditButtons = <>
            FieldName = 'FixedPrice'
            Footer.FieldName = 'FixedPrice'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #30721#27915
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 65
          end
          item
            EditButtons = <>
            FieldName = 'DiscountedPrice'
            Footer.FieldName = 'DiscountedPrice'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #23454#27915
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 65
          end
          item
            EditButtons = <>
            FieldName = 'salecbprice'
            Footer.FieldName = 'salecbprice'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #25104#26412
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 65
          end
          item
            EditButtons = <>
            FieldName = 'profite'
            Footer.FieldName = 'profite'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #27611#21033
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 65
          end
          item
            EditButtons = <>
            FieldName = 'Amount'
            Footer.FieldName = 'Amount'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #25968#37327
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 50
          end
          item
            EditButtons = <>
            FieldName = 'StorageName'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #24215#21517
            Title.Font.Charset = ANSI_CHARSET
            Title.Font.Color = clNavy
            Title.Font.Height = -12
            Title.Font.Name = #24494#36719#38597#40657
            Title.Font.Style = []
            Width = 180
          end>
      end
    end
    inherited tbshtByPress: TRzTabSheet
      ExplicitLeft = 1
      ExplicitTop = 24
      ExplicitWidth = 1008
      ExplicitHeight = 484
      inherited dbgrdByPress: TDBGridEh
        Columns = <
          item
            Alignment = taCenter
            EditButtons = <>
            FieldName = 'xuhao'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #24207
            Width = 30
          end
          item
            EditButtons = <>
            FieldName = 'PressName'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #29256#21035
            Width = 200
          end
          item
            EditButtons = <>
            FieldName = 'FixedPrice'
            Footer.FieldName = 'FixedPrice'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #30721#27915
            Width = 65
          end
          item
            EditButtons = <>
            FieldName = 'DiscountedPrice'
            Footer.FieldName = 'DiscountedPrice'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #23454#27915
            Width = 65
          end
          item
            EditButtons = <>
            FieldName = 'salecbprice'
            Footer.FieldName = 'salecbprice'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #25104#26412
            Width = 65
          end
          item
            EditButtons = <>
            FieldName = 'profite'
            Footer.FieldName = 'profite'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #27611#21033
            Width = 65
          end
          item
            EditButtons = <>
            FieldName = 'Amount'
            Footer.FieldName = 'Amount'
            Footer.ValueType = fvtSum
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #25968#37327
            Width = 50
          end
          item
            EditButtons = <>
            FieldName = 'StorageName'
            Footers = <>
            Title.Alignment = taCenter
            Title.Caption = #24215#21517
            Width = 180
          end>
      end
    end
  end
  inherited dsetByCustomer: TADODataSet
    Left = 152
    Top = 544
  end
  inherited dsrcByCustomer: TDataSource
    Left = 200
    Top = 392
  end
  inherited dsetByBktype: TADODataSet
    Left = 488
    Top = 304
  end
  inherited spQryNote: TADOStoredProc
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@Start'
        Attributes = [paNullable]
        DataType = ftDateTime
        Value = Null
      end
      item
        Name = '@End'
        Attributes = [paNullable]
        DataType = ftDateTime
        Value = Null
      end
      item
        Name = '@Name'
        Attributes = [paNullable]
        DataType = ftWideString
        Size = 100
        Value = Null
      end
      item
        Name = '@UserDefCode'
        Attributes = [paNullable]
        DataType = ftWideString
        Size = 10
        Value = Null
      end
      item
        Name = '@PressID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Value = Null
      end
      item
        Name = '@ISBN'
        Attributes = [paNullable]
        DataType = ftString
        Size = 15
        Value = Null
      end
      item
        Name = '@MaxPrice'
        Attributes = [paNullable]
        DataType = ftBCD
        Precision = 19
        Value = Null
      end
      item
        Name = '@MinPrice'
        Attributes = [paNullable]
        DataType = ftBCD
        Precision = 19
        Value = Null
      end
      item
        Name = '@BktypeID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Value = Null
      end
      item
        Name = '@CustomerID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Value = Null
      end
      item
        Name = '@Author'
        Attributes = [paNullable]
        DataType = ftWideString
        Size = 10
        Value = Null
      end
      item
        Name = '@Remarks'
        Attributes = [paNullable]
        DataType = ftWideString
        Size = 500
        Value = Null
      end
      item
        Name = '@BkstackID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Value = Null
      end
      item
        Name = '@MaxAmount'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Value = Null
      end
      item
        Name = '@MinAmount'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Value = Null
      end
      item
        Name = '@StgID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Value = Null
      end
      item
        Name = '@Bsmode'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Value = Null
      end
      item
        Name = '@SearchMode'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Value = Null
      end
      item
        Name = '@NoteCode'
        DataType = ftString
        Size = 20
        Value = Null
      end
      item
        Name = '@type'
        DataType = ftInteger
        Value = Null
      end
      item
        Name = '@return'
        DataType = ftInteger
        Value = Null
      end
      item
        Name = '@lost'
        DataType = ftInteger
        Value = Null
      end
      item
        Name = '@damage'
        DataType = ftInteger
        Value = Null
      end
      item
        Name = '@staff'
        Attributes = [paNullable]
        DataType = ftInteger
        Value = Null
      end
      item
        Name = '@mindiscount'
        Attributes = [paNullable]
        DataType = ftFloat
        Value = Null
      end
      item
        Name = '@maxdiscount'
        Attributes = [paNullable]
        DataType = ftFloat
        Value = Null
      end
      item
        Name = '@check'
        Attributes = [paNullable]
        DataType = ftInteger
        Value = Null
      end
      item
        Name = '@nocheck'
        Attributes = [paNullable]
        DataType = ftInteger
        Value = Null
      end
      item
        Name = '@checkpart'
        Attributes = [paNullable]
        DataType = ftInteger
        Value = Null
      end
      item
        Name = '@checked'
        Attributes = [paNullable]
        DataType = ftInteger
        Value = Null
      end
      item
        Name = '@SupplierID'
        Attributes = [paNullable]
        DataType = ftInteger
        Value = Null
      end
      item
        Name = '@BKJYtype'
        DataType = ftInteger
        Value = Null
      end
      item
        Name = '@MaxDamage'
        DataType = ftInteger
        Value = Null
      end
      item
        Name = '@MinDamage'
        DataType = ftInteger
        Value = Null
      end
      item
        Name = '@career'
        DataType = ftInteger
        Precision = 10
        Value = Null
      end
      item
        Name = '@andan'
        DataType = ftInteger
        Size = 10
        Value = Null
      end
      item
        Name = '@jinge'
        DataType = ftFloat
        Value = Null
      end
      item
        Name = '@outstorage'
        DataType = ftInteger
        Size = 10
        Value = Null
      end
      item
        Name = '@instorage'
        DataType = ftInteger
        Size = 10
        Value = Null
      end>
  end
  inherited dsetCustomer: TADODataSet
    CommandText = 
      'select ID, Name from CUST_CustomerInfo where  Type in(2,3) and c' +
      'ustomerstate=1 order by name'
    Left = 176
    Top = 448
  end
  inherited dsrcCustomer: TDataSource
    Left = 384
    Top = 296
  end
  inherited dsrcStorage: TDataSource
    Left = 576
    Top = 256
  end
  inherited dsetStorage: TADODataSet
    Left = 248
    Top = 352
  end
  inherited dsrcBookstack: TDataSource
    Left = 192
    Top = 256
  end
  inherited dsetBookstack: TADODataSet
    Left = 104
    Top = 384
  end
  inherited ImageList1: TImageList
    Bitmap = {
      494C010108000A00480110001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000003000000001002000000000000030
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
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000E2EFF100E5E5E500B2B2
      B200CC9999009966660099666600B2B2B200CCCCCC00E5E5E500E2EFF1000000
      00000000000000000000000000000000000000000000E2EFF10000000000B2B2
      B200999999009999990099999900B2B2B200CCCCCC0000000000E2EFF1000000
      0000000000000000000000000000000000000000000099330000993300009933
      0000993300009933000099330000993300009933000099330000993300009933
      0000993300009933000000000000000000000000000099999900999999009999
      9900999999009999990099999900999999009999990099999900999999009999
      990099999900999999000000000000000000E5E5E500CC99990099666600CC99
      9900CC999900FFFFFF00996666009999990099999900B2B2B200E5E5E5000000
      0000000000000000000000000000000000000000000099999900999999009999
      990099999900FFFFFF00999999009999990099999900B2B2B200000000000000
      0000000000000000000000000000000000000000000099330000CC996600CC99
      6600CC996600CC996600CC996600CC996600CC996600CC996600CC996600CC99
      6600CC9966009933000000000000000000000000000099999900CCCCCC00CCCC
      CC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00CCCCCC0099999900000000000000000099666600CC999900FFCC9900FFCC
      9900FFCCCC00FFFFFF0099666600336699003366990033669900E2EFF1000000
      0000000000000000000000000000000000009999990099999900C0C0C000C0C0
      C000CCCCCC00FFFFFF0099999900999999009999990099999900E2EFF1000000
      0000000000000000000000000000000000000000000099330000CC996600CC99
      6600CC996600CC996600CC996600CC996600CC996600CC996600CC996600CC99
      6600CC9966009933000000000000000000000000000099999900CCCCCC00CCCC
      CC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00CCCCCC0099999900000000000000000099666600FFCC9900FFCC9900FFCC
      9900FFCCCC00FFFFFF009966660066CCCC0066CCCC000099CC00FFFFFF00FFCC
      CC000000000000000000000000000000000099999900C0C0C000C0C0C000C0C0
      C000CCCCCC00FFFFFF0099999900C0C0C000C0C0C00099999900FFFFFF00CCCC
      CC00000000000000000000000000000000000000000099330000CC996600CC99
      6600CC996600CC996600CC996600CC996600CC996600CC996600CC996600CC99
      6600CC9966009933000000000000000000000000000099999900CCCCCC00CCCC
      CC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00CCCCCC0099999900000000000000000099666600FFCC9900FFCC9900FFCC
      9900FFCCCC00FFFFFF009966660066CCCC0066CCFF003399CC00FFCCCC00CC66
      00000000000000000000000000000000000099999900C0C0C000C0C0C000C0C0
      C000CCCCCC00FFFFFF0099999900C0C0C000CCCCCC0099999900CCCCCC009999
      9900000000000000000000000000000000000000000099330000993300009933
      0000993300009933000099330000993300009933000099330000993300009933
      0000993300009933000000000000000000000000000099999900999999009999
      9900999999009999990099999900999999009999990099999900999999009999
      99009999990099999900000000000000000099666600FFCC9900CC999900CC99
      6600FFCCCC00FFFFFF009966660099CCCC0099CCFF00B2B2B200FF660000CC66
      00000000000000000000000000000000000099999900C0C0C000999999009999
      9900CCCCCC00FFFFFF0099999900CCCCCC00CCCCCC00B2B2B200999999009999
      9900000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000099666600FFCC990099666600FFFF
      FF00FFCCCC00FFFFFF009966660099CCCC00C0C0C000CC660000CC660000CC66
      0000CC660000CC660000CC6600000000000099999900C0C0C00066666600FFFF
      FF00CCCCCC00FFFFFF0099999900CCCCCC00C0C0C00099999900999999009999
      99009999990099999900999999000000000000000000CC996600000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000CC996600000000000000000000000000CCCCCC00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000CCCCCC00000000000000000099666600FFCC9900CC9999009966
      6600FFCCCC00FFFFFF009966660000000000CC660000CC660000CC660000CC66
      0000CC660000CC660000CC6600000000000099999900C0C0C000999999006666
      6600CCCCCC00FFFFFF0099999900E5E5E5009999990099999900999999009999
      9900999999009999990099999900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000099666600FFCC9900FFCC9900FFCC
      9900FFCCCC00FFFFFF009966660000000000CC999900CC660000CC660000CC66
      0000CC660000CC660000CC6600000000000099999900C0C0C000C0C0C000C0C0
      C000CCCCCC00FFFFFF0099999900E5E5E5009999990099999900999999009999
      99009999990099999900999999000000000000000000CC996600000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000CC996600000000000000000000000000CCCCCC00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000CCCCCC00000000000000000099666600FFCC9900FFCC9900FFCC
      9900FFCCCC00FFFFFF0099666600CCCCCC00E2EFF100CC999900FF660000CC66
      00000000000000000000000000000000000099999900C0C0C000C0C0C000C0C0
      C000CCCCCC00FFFFFF0099999900CCCCCC00E2EFF10099999900999999009999
      9900000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000099666600FFCC9900FFCC9900FFCC
      9900FFCCCC00FFFFFF009966660099CCCC000000000099CCCC00FFCC9900CC66
      00000000000000000000000000000000000099999900C0C0C000C0C0C000C0C0
      C000CCCCCC00FFFFFF0099999900CCCCCC00E5E5E500CCCCCC00C0C0C0009999
      99000000000000000000000000000000000000000000CC996600000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000CC996600000000000000000000000000CCCCCC00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000CCCCCC00000000000000000099666600CC999900FFCC9900FFCC
      9900FFCCCC00FFFFFF0099666600CCCCCC00000000003399CC0000000000FFCC
      9900000000000000000000000000000000009999990099999900C0C0C000C0C0
      C000CCCCCC00FFFFFF0099999900CCCCCC00E5E5E5009999990000000000C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000CC996600CC99
      9900CCCC9900FFFFFF00996666000099CC000099CC000099CC00000000000000
      00000000000000000000000000000000000000000000C0C0C000999999009999
      9900C0C0C000FFFFFF0099999900999999009999990099999900000000000000
      00000000000000000000000000000000000000000000CC99660000000000CC99
      660000000000CC99660000000000CC99660000000000CC99660000000000CC99
      660000000000CC996600000000000000000000000000CCCCCC0000000000CCCC
      CC0000000000CCCCCC0000000000CCCCCC0000000000CCCCCC0000000000CCCC
      CC0000000000CCCCCC000000000000000000000000000000000000000000CCCC
      CC00CC9999009966660099666600000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000CCCC
      CC00999999009999990099999900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000CCCCCC00C0C0C000E5E5
      E500000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000CCCCCC00C0C0C000E5E5
      E500000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000CCCCCC0066999900666699009999
      9900E5E5E5000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000CCCCCC00B2B2B200999999009999
      9900E5E5E5000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000993300000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000066CCFF003399CC006666
      990099999900E5E5E50000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000CCCCCC00B2B2B2009999
      990099999900E5E5E50000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000993300009933
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000999999009999
      99000000000000000000000000000000000000000000CCCCFF0066CCFF003399
      CC006666990099999900E5E5E500000000000000000000000000000000000000
      00000000000000000000000000000000000000000000E5E5E500CCCCCC00B2B2
      B2009999990099999900E5E5E500000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009933
      0000993300009933000099330000993300009933000099330000993300009933
      0000993300000000000000000000000000000000000000000000000000009999
      9900999999009999990099999900999999009999990099999900999999009999
      9900999999000000000000000000000000000000000000000000CCCCFF0066CC
      FF003399CC006666990099999900E5E5E5000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000E5E5E500CCCC
      CC00B2B2B2009999990099999900E5E5E5000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000993300009933
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000999999009999
      990000000000000000000000000000000000000000000000000000000000CCCC
      FF0066CCFF003399CC0066669900CCCCCC00FFCCCC00CC999900CC999900CC99
      9900CCCC9900E5E5E5000000000000000000000000000000000000000000E5E5
      E500CCCCCC00B2B2B20099999900CCCCCC00E5E5E50099999900999999009999
      9900B2B2B200E5E5E50000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000993300000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000CCCCFF0066CCFF00B2B2B200CC999900CCCC9900F2EABF00FFFFCC00F2EA
      BF00F2EABF00CC999900ECC6D900000000000000000000000000000000000000
      0000E5E5E500CCCCCC00B2B2B20099999900B2B2B200CCCCCC00CCCCCC00CCCC
      CC00CCCCCC0099999900E5E5E500000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000E5E5E500CC999900FFCC9900FFFFCC00FFFFCC00FFFFCC00FFFF
      FF00FFFFFF00FFFFFF00CC999900E5E5E5000000000000000000000000000000
      000000000000E5E5E50099999900E5E5E500CCCCCC00CCCCCC00CCCCCC00E5E5
      E500E5E5E500E5E5E50099999900E5E5E500CC996600CC996600CC996600CC99
      6600CC996600CC996600CC99660000000000000000003399CC00006699000066
      9900006699000066990000669900006699009999990099999900999999009999
      9900999999009999990099999900000000000000000099999900999999009999
      9900999999009999990099999900999999000000000000000000000000000000
      000000000000FFCCCC00CCCC9900FFFFCC00F2EABF00FFFFCC00FFFFCC00FFFF
      FF00FFFFFF00FFFFFF00F2EABF00CCCC99000000000000000000000000000000
      000000000000E5E5E500B2B2B200CCCCCC00CCCCCC00CCCCCC00CCCCCC00E5E5
      E500E5E5E500E5E5E500CCCCCC00B2B2B200CC996600FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00CC99660000000000000000003399CC0099FFFF0099FF
      FF0099FFFF0099FFFF0099FFFF00006699009999990000000000000000000000
      0000000000000000000099999900000000000000000099999900CCCCCC00CCCC
      CC00CCCCCC00CCCCCC00CCCCCC00999999000000000000000000000000000000
      000000000000CCCC9900FFCC9900F2EABF00F2EABF00FFFFCC00FFFFCC00FFFF
      CC00FFFFFF00FFFFFF00F2EABF00CC9999000000000000000000000000000000
      000000000000B2B2B200E5E5E500CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00E5E5E500E5E5E500CCCCCC0099999900CC996600FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00CC99660000000000000000003399CC0099FFFF0099FF
      FF0099FFFF0099FFFF0099FFFF00006699009999990000000000000000000000
      0000000000000000000099999900000000000000000099999900CCCCCC00CCCC
      CC00CCCCCC00CCCCCC00CCCCCC00999999000000000000000000000000000000
      000000000000CC999900F2EABF00F2EABF00F2EABF00F2EABF00FFFFCC00FFFF
      CC00FFFFCC00FFFFCC00FFFFCC00CC9999000000000000000000000000000000
      00000000000099999900CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00CCCCCC00CCCCCC00CCCCCC0099999900CC996600FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00CC99660000000000000000003399CC0099FFFF0099FF
      FF0099FFFF0099FFFF0099FFFF00006699009999990000000000000000000000
      0000000000000000000099999900000000000000000099999900CCCCCC00CCCC
      CC00CCCCCC00CCCCCC00CCCCCC00999999000000000000000000000000000000
      000000000000CCCC9900F2EABF00FFFFCC00F2EABF00F2EABF00F2EABF00FFFF
      CC00FFFFCC00FFFFCC00F2EABF00CC9999000000000000000000000000000000
      000000000000B2B2B200CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00CCCCCC00CCCCCC00CCCCCC0099999900CC996600FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00CC99660000000000000000003399CC0099FFFF0099FF
      FF0099FFFF0099FFFF0099FFFF00006699009999990000000000000000000000
      0000000000000000000099999900000000000000000099999900CCCCCC00CCCC
      CC00CCCCCC00CCCCCC00CCCCCC00999999000000000000000000000000000000
      000000000000FFCCCC00CCCC9900FFFFFF00FFFFFF00F2EABF00F2EABF00F2EA
      BF00F2EABF00FFFFCC00CCCC9900CCCC99000000000000000000000000000000
      000000000000E5E5E500B2B2B200E5E5E500E5E5E500CCCCCC00CCCCCC00CCCC
      CC00CCCCCC00CCCCCC00B2B2B200B2B2B200CC996600FFFFFF00FFFFFF00CC99
      6600CC996600CC996600CC99660000000000000000003399CC0099FFFF0099FF
      FF003399CC003399CC003399CC003399CC009999990000000000000000009999
      9900999999009999990099999900000000000000000099999900CCCCCC00CCCC
      CC00999999009999990099999900999999000000000000000000000000000000
      000000000000E5E5E500CC999900ECC6D900FFFFFF00FFFFCC00F2EABF00F2EA
      BF00F2EABF00FFCC9900CC999900E5E5E5000000000000000000000000000000
      000000000000E5E5E50099999900E5E5E500E5E5E500CCCCCC00CCCCCC00CCCC
      CC00CCCCCC00E5E5E50099999900E5E5E500CC996600FFFFFF00FFFFFF00CC99
      6600E5E5E500CC9966000000000000000000000000003399CC0099FFFF0099FF
      FF003399CC00CCFFFF0000669900000000009999990000000000000000009999
      9900E5E5E5009999990000000000000000000000000099999900CCCCCC00CCCC
      CC0099999900CCCCCC0099999900000000000000000000000000000000000000
      00000000000000000000FFCCCC00CC999900FFCCCC00F2EABF00F2EABF00F2EA
      BF00CCCC9900CC999900FFCCCC00000000000000000000000000000000000000
      00000000000000000000E5E5E50099999900E5E5E500CCCCCC00CCCCCC00CCCC
      CC00B2B2B20099999900E5E5E50000000000CC996600FFFFFF00FFFFFF00CC99
      6600CC996600000000000000000000000000000000003399CC0099FFFF0099FF
      FF003399CC000066990000000000000000009999990000000000000000009999
      9900999999000000000000000000000000000000000099999900CCCCCC00CCCC
      CC00999999009999990000000000000000000000000000000000000000000000
      0000000000000000000000000000E5E5E500CCCC9900CC999900CC999900CC99
      9900CC999900E5E5E50000000000000000000000000000000000000000000000
      0000000000000000000000000000E5E5E500B2B2B20099999900999999009999
      990099999900E5E5E5000000000000000000CC996600CC996600CC996600CC99
      660000000000000000000000000000000000000000003399CC003399CC003399
      CC003399CC000000000000000000000000009999990099999900999999009999
      9900000000000000000000000000000000000000000099999900999999009999
      990099999900000000000000000000000000424D3E000000000000003E000000
      2800000040000000300000000100010000000000800100000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FDFFFDFFFFFFFFFFE0FFE8FFFFFFFFFF
      801FA05F80038003001F803F80038003001F001F80038003000F000F80038003
      000F000F80038003000F000FFFFFFFFF00010001BFFBBFFB01010001FFFFFFFF
      01010001BFFBBFFB000F000FFFFFFFFF008F000FBFFBBFFB00AF002FFFFFFFFF
      803F803FAAABAAABE1FFE1FFFFFFFFFF8FFF8FFFFFFFFFFF07FF07FFFFDFFFDF
      83FF83FFFFCFFFCF81FF81FFE007E007C0FFC0FFFFCFFFCFE003E003FFDFFFDF
      F001F001FFFFFFFFF800F80001800180F800F80001807D80F800F80001807D80
      F800F80001807D80F800F80001807D80F800F80001806180F800F80003816381
      FC01FC0107836783FE03FE030F870F8700000000000000000000000000000000
      000000000000}
  end
  inherited dsetPress: TADODataSet
    Left = 304
    Top = 360
  end
  inherited dsetSupplier: TADODataSet
    CommandText = 
      'select ID, Name from CUST_CustomerInfo where  Type =1  and custo' +
      'merstate=1 order by name'
  end
  inherited savedlg: TSaveDialog
    Left = 760
    Top = 296
  end
  object PopupMenu1: TPopupMenu [31]
    Left = 376
    Top = 272
    object N1: TMenuItem
      Caption = #21382#21490#26126#32454
      OnClick = N1Click
    end
  end
  inherited PopupMenu2: TPopupMenu
    Left = 464
    Top = 288
  end
end
