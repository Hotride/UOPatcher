object Patcher: TPatcher
  Left = 0
  Top = 0
  AlphaBlend = True
  AlphaBlendValue = 0
  BorderStyle = bsSingle
  Caption = 'UO Patcher v1701.29 by Hotride'
  ClientHeight = 297
  ClientWidth = 658
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MV Boli'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 17
  object Label1: TLabel
    Left = 128
    Top = 8
    Width = 58
    Height = 17
    Caption = 'Client list'
  end
  object img_Refresh: TImage
    Left = 192
    Top = 8
    Width = 20
    Height = 20
    Cursor = crHandPoint
    Hint = 'Refresh clients list'
    ParentShowHint = False
    Picture.Data = {
      0954506E67496D61676589504E470D0A1A0A0000000D49484452000000140000
      001408060000008D891D0D000000017352474200AECE1CE90000000467414D41
      0000B18F0BFC6105000000097048597300000EC400000EC401952B0E1B000004
      BC4944415478DA7D957950556518879F73572E283B22B880208B242A884B96A6
      18A38EE0A035CDE092A58E28A9E4441A336E4D8E8EA611462C8A299A504CE592
      3530E6D21096A0103111422C83E0C216CBC57BB95CEEE9BB97CAC6B4EF9F33F3
      CDFB7BCEBBFCCE7BA4AEAE2E99279C8A9F7FE3484A1617BE2E60C072DF76A756
      8C6449CC42B66C8D67F294094F92213D0EBC78A1904D8909F4293B58B541C7D2
      574613E8A71391505367E06C7E339F661AD00DBA91969A4ECC92054F07EEDD7B
      804387F6B3FEC02862633D7092FA914C662C96A110854250352ABAD172FE5C1B
      99DB5A484A4A66C78EEDFF051E3C90C2BEEC77397C3C98E9410A4C7D263AF403
      184D462CF2C010505263A7D1E1364C85DA4143E96D0B496BAB495EB79B6DDBB7
      3E029695561219359BF7BF1A4F78A09AD63613DD0F3B7119EE8BBB6328F61A4F
      64919CB1FF01ADDD1574E99B707270C7C34DA2BCD6CCDBCBEAB972A988F069A1
      43C0E766CD667254136B36F850DFD883053341DE2F1138FA65BC5C6621490ADB
      DB2D1633773BAF537BF70BAA9AF244F54EF88F1B4E76463DBF5CF2A1F87AD110
      D0D9D99982DA4934D41A309B4D4CF25BC39C6776D920B52DE769EEB8864A30FD
      4746E2ED1E832C9A545CB5079D7604CDED45289D4A8909A9C36030231D3F9627
      679E89E3ADC361D4FDDEC2449F5896CCC862C0DCCF8592B5425082D962C09AA3
      4AA563BCE70C16461C137D55A05468F8B2780D7AE535D2931B885F918B343D6C
      BE1CBDA9027B0F57740A0F62671EC1DB2D9CF33F6DA1BC21177BAD9B1886CA96
      AD79D024FAD8C5B321F12C08DB6BBBCBFFE175EADB2F33D069E4625AA8D55D2A
      39AF3C94EAEA1E3C1D83880A7B8F3FFAAAF9BE320583102B955A21B31A4162D0
      D28F8F871FABE66588186B7BEC4415DBB9D35EC6841067E2C22AAD40E4A3B7A6
      73A7CA8069B097F6DE467129E1E8E025A6EB2CB253FEDBB698CC0FE9E86D12B1
      269442ED3E7C2C5A95336342EC583FB5C40A54CA87AE4EE15E432F2EC3BC99EA
      1F2BF2B1A05168B959972FC4ADC2D0AABF70D6B2CD68D5F6A2D791E8C40B2B1A
      0BD01B5AF1F47520695E0552C4A4E7E5E0E58DB8786808183187CDD1276CE292
      9ACF387575A768BC1A955233641BD9424F5F1B11018BD9B8289B96CE1A8E166E
      403F709FD67BBD54E7FA226567E5C8C94756B36A4F085ECAA9242D3D65135737
      FFC8E7C5FBA8B97B4B4C78A86CAB3F83BD67B072EE1EC6794EE1E4E524AE56E6
      33D6DF9BAC776EB03F31E7910FE33EF425DC7F2E33FDA3191C34F0C2C49574EA
      EF535876427C1D776C400FA731444D7E4D3CBD28AA3AC9E96B29C84A8B1896CC
      89845F11AC21605A6A06BB8F25B3F9E01CF43D7A8C863EA22396B36C66026A95
      FB630BAA5D4C36838B37CFD16DD4E3EAE6CC273B4BD8B56E9F6D4BFDB31C1212
      1228ACCA65517C38A6FE01068C4602BC82F0F31CC5386115A5A8BAA5BD8EDA07
      2D54B7D420A9B5D83B38F06DE60DA28297939E9EFED8FAB240E2D64472CEE6F0
      E2A6204606B8D3D3D1CD60BF514C5C631BB15936892D6B87A3C8EA416D1BDFA5
      DD66F5B2D5A47E900A8AA72CD833A7F3D8FC6602169D4CE06237C64FF36598AB
      CE66EDBE4E0375A58DDCFEA6038541E2A3947456BC1AF7FF1BFBEF53565A4EC6
      C7595C2EB842A7B1D576E76A3782F90B23D9F846BC5855614FFC05FC093FBD0A
      CB2015AF1A0000000049454E44AE426082}
    ShowHint = True
    OnClick = img_RefreshClick
  end
  object lb_ClientList: TListBox
    Left = 8
    Top = 27
    Width = 297
    Height = 219
    ItemHeight = 17
    TabOrder = 0
    OnClick = lb_ClientListClick
  end
  object pc_Main: TPageControl
    Left = 311
    Top = 8
    Width = 341
    Height = 283
    ActivePage = ts_PatchMemory
    TabOrder = 1
    object ts_PatchMemory: TTabSheet
      Caption = 'Patch memory'
      ImageIndex = 1
      object GroupBox1: TGroupBox
        Left = 3
        Top = 0
        Width = 327
        Height = 249
        Caption = 'Available patches'
        TabOrder = 0
        object lb_TextFPS: TLabel
          Tag = 1
          Left = 26
          Top = 24
          Width = 24
          Height = 17
          Caption = 'FPS'
          OnClick = TextLabelRuntimePatckClickProc
        end
        object lb_TextStamina: TLabel
          Tag = 2
          Left = 26
          Top = 47
          Width = 48
          Height = 17
          Caption = 'Stamina'
          OnClick = TextLabelRuntimePatckClickProc
        end
        object lb_TextAlwaysLight: TLabel
          Tag = 3
          Left = 26
          Top = 70
          Width = 72
          Height = 17
          Caption = 'Always light'
          OnClick = TextLabelRuntimePatckClickProc
        end
        object lb_TextPaperdollSlots: TLabel
          Tag = 4
          Left = 26
          Top = 93
          Width = 87
          Height = 17
          Caption = 'Paperdoll slots'
          OnClick = TextLabelRuntimePatckClickProc
        end
        object lb_TextOptionsNotification: TLabel
          Tag = 7
          Left = 26
          Top = 116
          Width = 140
          Height = 17
          Caption = 'No options notification'
          OnClick = TextLabelRuntimePatckClickProc
        end
        object cb_FPS: TCheckBox
          Tag = 1
          Left = 8
          Top = 24
          Width = 17
          Height = 17
          Enabled = False
          TabOrder = 0
          OnClick = RuntimePatchClickProc
        end
        object cb_Stamina: TCheckBox
          Tag = 2
          Left = 8
          Top = 47
          Width = 17
          Height = 17
          Color = clBtnFace
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MV Boli'
          Font.Style = []
          ParentColor = False
          ParentFont = False
          TabOrder = 1
          OnClick = RuntimePatchClickProc
        end
        object cb_AlwaysLight: TCheckBox
          Tag = 3
          Left = 8
          Top = 70
          Width = 17
          Height = 17
          Enabled = False
          TabOrder = 2
          OnClick = RuntimePatchClickProc
        end
        object cb_PaperdollSlots: TCheckBox
          Tag = 4
          Left = 8
          Top = 93
          Width = 17
          Height = 17
          Enabled = False
          TabOrder = 3
          OnClick = RuntimePatchClickProc
        end
        object cb_OptionsNotification: TCheckBox
          Tag = 7
          Left = 8
          Top = 116
          Width = 17
          Height = 17
          Enabled = False
          TabOrder = 4
          OnClick = RuntimePatchClickProc
        end
      end
    end
    object ts_PatchFile: TTabSheet
      Caption = 'Patch client file'
      ImageIndex = 2
      object bt_SetClientPatch: TButton
        Left = 304
        Top = 2
        Width = 26
        Height = 22
        Caption = '...'
        TabOrder = 0
        OnClick = bt_SetClientPatchClick
      end
      object eb_ClientPath: TEdit
        Left = 3
        Top = 1
        Width = 298
        Height = 25
        TabOrder = 1
        OnKeyUp = eb_ClientPathKeyUp
      end
      object GroupBox2: TGroupBox
        Left = 3
        Top = 32
        Width = 327
        Height = 216
        Caption = 'Available patches'
        TabOrder = 2
        object lb_FileTextStamina: TLabel
          Tag = 2
          Left = 26
          Top = 23
          Width = 48
          Height = 17
          Caption = 'Stamina'
          OnClick = FileTextLabelRuntimePatckClickProc
        end
        object lb_FileTextAlwaysLight: TLabel
          Tag = 3
          Left = 26
          Top = 46
          Width = 72
          Height = 17
          Caption = 'Always light'
          OnClick = FileTextLabelRuntimePatckClickProc
        end
        object lb_FileTextPaperdollSlots: TLabel
          Tag = 4
          Left = 26
          Top = 69
          Width = 87
          Height = 17
          Caption = 'Paperdoll slots'
          OnClick = FileTextLabelRuntimePatckClickProc
        end
        object img_RefreshFilePatches: TImage
          Left = 115
          Top = 0
          Width = 20
          Height = 20
          Cursor = crHandPoint
          Hint = 'Refresh patches info for current file'
          ParentShowHint = False
          Picture.Data = {
            0954506E67496D61676589504E470D0A1A0A0000000D49484452000000140000
            001408060000008D891D0D000000017352474200AECE1CE90000000467414D41
            0000B18F0BFC6105000000097048597300000EC400000EC401952B0E1B000004
            BC4944415478DA7D957950556518879F73572E283B22B880208B242A884B96A6
            18A38EE0A035CDE092A58E28A9E4441A336E4D8E8EA611462C8A299A504CE592
            3530E6D21096A0103111422C83E0C216CBC57BB95CEEE9BB97CAC6B4EF9F33F3
            CDFB7BCEBBFCCE7BA4AEAE2E99279C8A9F7FE3484A1617BE2E60C072DF76A756
            8C6449CC42B66C8D67F294094F92213D0EBC78A1904D8909F4293B58B541C7D2
            574613E8A71391505367E06C7E339F661AD00DBA91969A4ECC92054F07EEDD7B
            804387F6B3FEC02862633D7092FA914C662C96A110854250352ABAD172FE5C1B
            99DB5A484A4A66C78EEDFF051E3C90C2BEEC77397C3C98E9410A4C7D263AF403
            184D462CF2C010505263A7D1E1364C85DA4143E96D0B496BAB495EB79B6DDBB7
            3E029695561219359BF7BF1A4F78A09AD63613DD0F3B7119EE8BBB6328F61A4F
            64919CB1FF01ADDD1574E99B707270C7C34DA2BCD6CCDBCBEAB972A988F069A1
            43C0E766CD667254136B36F850DFD883053341DE2F1138FA65BC5C6621490ADB
            DB2D1633773BAF537BF70BAA9AF244F54EF88F1B4E76463DBF5CF2A1F87AD110
            D0D9D99982DA4934D41A309B4D4CF25BC39C6776D920B52DE769EEB8864A30FD
            4746E2ED1E832C9A545CB5079D7604CDED45289D4A8909A9C36030231D3F9627
            679E89E3ADC361D4FDDEC2449F5896CCC862C0DCCF8592B5425082D962C09AA3
            4AA563BCE70C16461C137D55A05468F8B2780D7AE535D2931B885F918B343D6C
            BE1CBDA9027B0F57740A0F62671EC1DB2D9CF33F6DA1BC21177BAD9B1886CA96
            AD79D024FAD8C5B321F12C08DB6BBBCBFFE175EADB2F33D069E4625AA8D55D2A
            39AF3C94EAEA1E3C1D83880A7B8F3FFAAAF9BE320583102B955A21B31A4162D0
            D28F8F871FABE66588186B7BEC4415DBB9D35EC6841067E2C22AAD40E4A3B7A6
            73A7CA8069B097F6DE467129E1E8E025A6EB2CB253FEDBB698CC0FE9E86D12B1
            269442ED3E7C2C5A95336342EC583FB5C40A54CA87AE4EE15E432F2EC3BC99EA
            1F2BF2B1A05168B959972FC4ADC2D0AABF70D6B2CD68D5F6A2D791E8C40B2B1A
            0BD01B5AF1F47520695E0552C4A4E7E5E0E58DB8786808183187CDD1276CE292
            9ACF387575A768BC1A955233641BD9424F5F1B11018BD9B8289B96CE1A8E166E
            403F709FD67BBD54E7FA226567E5C8C94756B36A4F085ECAA9242D3D65135737
            FFC8E7C5FBA8B97B4B4C78A86CAB3F83BD67B072EE1EC6794EE1E4E524AE56E6
            33D6DF9BAC776EB03F31E7910FE33EF425DC7F2E33FDA3191C34F0C2C49574EA
            EF535876427C1D776C400FA731444D7E4D3CBD28AA3AC9E96B29C84A8B1896CC
            89845F11AC21605A6A06BB8F25B3F9E01CF43D7A8C863EA22396B36C66026A95
            FB630BAA5D4C36838B37CFD16DD4E3EAE6CC273B4BD8B56E9F6D4BFDB31C1212
            1228ACCA65517C38A6FE01068C4602BC82F0F31CC5386115A5A8BAA5BD8EDA07
            2D54B7D420A9B5D83B38F06DE60DA28297939E9EFED8FAB240E2D64472CEE6F0
            E2A6204606B8D3D3D1CD60BF514C5C631BB15936892D6B87A3C8EA416D1BDFA5
            DD66F5B2D5A47E900A8AA72CD833A7F3D8FC6602169D4CE06237C64FF36598AB
            CE66EDBE4E0375A58DDCFEA6038541E2A3947456BC1AF7FF1BFBEF53565A4EC6
            C7595C2EB842A7B1D576E76A3782F90B23D9F846BC5855614FFC05FC093FBD0A
            CB2015AF1A0000000049454E44AE426082}
          ShowHint = True
          OnClick = img_RefreshFilePatchesClick
        end
        object lb_FileTextSplashScreen: TLabel
          Tag = 5
          Left = 26
          Top = 92
          Width = 98
          Height = 17
          Caption = 'No splash screen'
          OnClick = FileTextLabelRuntimePatckClickProc
        end
        object lb_FileTextResolution: TLabel
          Tag = 6
          Left = 26
          Top = 115
          Width = 61
          Height = 17
          Caption = 'Resolution'
          OnClick = FileTextLabelRuntimePatckClickProc
        end
        object lb_FileTextOptionsNotification: TLabel
          Tag = 7
          Left = 26
          Top = 138
          Width = 140
          Height = 17
          Caption = 'No options notification'
          OnClick = FileTextLabelRuntimePatckClickProc
        end
        object lb_FileTextMultiUO: TLabel
          Tag = 8
          Left = 26
          Top = 161
          Width = 70
          Height = 17
          Caption = 'Multi client'
          OnClick = FileTextLabelRuntimePatckClickProc
        end
        object cb_FileStamina: TCheckBox
          Tag = 2
          Left = 8
          Top = 23
          Width = 17
          Height = 17
          Color = clBtnFace
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MV Boli'
          Font.Style = []
          ParentColor = False
          ParentFont = False
          TabOrder = 0
        end
        object cb_FileAlwaysLight: TCheckBox
          Tag = 3
          Left = 8
          Top = 46
          Width = 17
          Height = 17
          Enabled = False
          TabOrder = 1
        end
        object cb_FilePaperdollSlots: TCheckBox
          Tag = 4
          Left = 8
          Top = 69
          Width = 17
          Height = 17
          Enabled = False
          TabOrder = 2
        end
        object bt_ClientPatch: TButton
          Left = 157
          Top = 0
          Width = 75
          Height = 22
          Caption = 'Patch it!'
          TabOrder = 3
          OnClick = bt_ClientPatchClick
        end
        object cb_FileSplashScreen: TCheckBox
          Tag = 5
          Left = 8
          Top = 92
          Width = 17
          Height = 17
          Enabled = False
          TabOrder = 4
        end
        object cb_FileResolution: TCheckBox
          Tag = 6
          Left = 8
          Top = 115
          Width = 17
          Height = 17
          Enabled = False
          TabOrder = 5
        end
        object cb_FileOptionsNotification: TCheckBox
          Tag = 7
          Left = 8
          Top = 138
          Width = 17
          Height = 17
          Enabled = False
          TabOrder = 6
        end
        object cb_FileMultiUO: TCheckBox
          Tag = 8
          Left = 8
          Top = 161
          Width = 17
          Height = 17
          Enabled = False
          TabOrder = 7
        end
      end
    end
  end
  object gb_OrionInfo: TGroupBox
    Left = 8
    Top = 248
    Width = 297
    Height = 43
    BiDiMode = bdLeftToRight
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MV Boli'
    Font.Style = []
    ParentBiDiMode = False
    ParentFont = False
    TabOrder = 2
    object lb_OrionGitHub: TLabel
      Left = 30
      Top = 20
      Width = 48
      Height = 16
      Cursor = crHandPoint
      Caption = 'GitHub'
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold, fsUnderline]
      ParentColor = False
      ParentFont = False
      OnClick = lb_OrionGitHubClick
    end
    object lb_OrionDiscord: TLabel
      Tag = 1
      Left = 122
      Top = 20
      Width = 55
      Height = 16
      Cursor = crHandPoint
      Caption = 'Discord'
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold, fsUnderline]
      ParentColor = False
      ParentFont = False
      OnClick = lb_OrionGitHubClick
    end
    object lb_OrionForum: TLabel
      Tag = 2
      Left = 220
      Top = 20
      Width = 44
      Height = 16
      Cursor = crHandPoint
      Caption = 'Forum'
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold, fsUnderline]
      ParentColor = False
      ParentFont = False
      OnClick = lb_OrionGitHubClick
    end
    object Label2: TLabel
      Left = 13
      Top = -2
      Width = 271
      Height = 20
      Caption = 'Try to use Orion Ultima Online client!'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -15
      Font.Name = 'MV Boli'
      Font.Style = []
      ParentFont = False
    end
  end
  object od_ClientPath: TOpenDialog
    Filter = 'UO Client|*.exe'
  end
  object tm_Creation: TTimer
    Enabled = False
    Interval = 20
    OnTimer = tm_CreationTimer
    Left = 32
  end
end
