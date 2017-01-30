//---------------------------------------------------------------------------

#ifndef MainScriptH
#define MainScriptH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <pngimage.hpp>
#include <CheckLst.hpp>
#include <vector>
//---------------------------------------------------------------------------
enum PATCH_TYPE
{
	PT_FPS = 1,
	PT_STAMINA,
	PT_ALWAYS_LIGHT,
	PT_PAPERDOLL_SLOTS,
	PT_SPLASH_SCREEN,
	PT_RESOLUTION,
	PT_OPTIONS_NOTIFICATION,
	PT_MULTI_UO,
	PT_COUNT
};
//---------------------------------------------------------------------------
enum PATCH_STATE
{
	PS_DISABLE = 0,
	PS_ENABLE,
	PS_NOT_FOUND
};
//---------------------------------------------------------------------------
enum PATCH_MESSAGES
{
	PM_INSTALL = WM_USER + 666,
	PM_INFO,
	PM_ENABLE,
	PM_DISABLE
};
//---------------------------------------------------------------------------
typedef DWORD __cdecl GET_PROCESS_PATCHES_FUN(HWND, DWORD);
typedef DWORD __cdecl GET_FILE_PATCHES_FUN(const char*);
typedef DWORD __cdecl SET_FILE_PATCHES_FUN(const char*, DWORD);
//---------------------------------------------------------------------------
class TPatcher : public TForm
{
__published:	// IDE-managed Components
	TListBox *lb_ClientList;
	TLabel *Label1;
	TPageControl *pc_Main;
	TTabSheet *ts_PatchMemory;
	TTabSheet *ts_PatchFile;
	TButton *bt_SetClientPatch;
	TOpenDialog *od_ClientPath;
	TEdit *eb_ClientPath;
	TGroupBox *GroupBox1;
	TCheckBox *cb_FPS;
	TCheckBox *cb_Stamina;
	TCheckBox *cb_AlwaysLight;
	TCheckBox *cb_PaperdollSlots;
	TGroupBox *gb_OrionInfo;
	TLabel *lb_OrionGitHub;
	TLabel *lb_OrionDiscord;
	TLabel *lb_OrionForum;
	TImage *img_Refresh;
	TLabel *lb_TextFPS;
	TLabel *lb_TextStamina;
	TLabel *lb_TextAlwaysLight;
	TLabel *lb_TextPaperdollSlots;
	TTimer *tm_Creation;
	TGroupBox *GroupBox2;
	TLabel *lb_FileTextStamina;
	TLabel *lb_FileTextAlwaysLight;
	TLabel *lb_FileTextPaperdollSlots;
	TCheckBox *cb_FileStamina;
	TCheckBox *cb_FileAlwaysLight;
	TCheckBox *cb_FilePaperdollSlots;
	TButton *bt_ClientPatch;
	TImage *img_RefreshFilePatches;
	TCheckBox *cb_FileSplashScreen;
	TLabel *lb_FileTextSplashScreen;
	TLabel *Label2;
	TLabel *lb_FileTextResolution;
	TCheckBox *cb_FileResolution;
	TLabel *lb_FileTextOptionsNotification;
	TCheckBox *cb_FileOptionsNotification;
	TLabel *lb_TextOptionsNotification;
	TCheckBox *cb_OptionsNotification;
	TLabel *lb_FileTextMultiUO;
	TCheckBox *cb_FileMultiUO;
	void __fastcall eb_ClientPathKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall bt_SetClientPatchClick(TObject *Sender);
	void __fastcall lb_OrionGitHubClick(TObject *Sender);
	void __fastcall lb_ClientListClick(TObject *Sender);
	void __fastcall img_RefreshClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall RuntimePatchClickProc(TObject *Sender);
	void __fastcall TextLabelRuntimePatckClickProc(TObject *Sender);
	void __fastcall FileTextLabelRuntimePatckClickProc(TObject *Sender);
	void __fastcall tm_CreationTimer(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall img_RefreshFilePatchesClick(TObject *Sender);
	void __fastcall bt_ClientPatchClick(TObject *Sender);

private:	// User declarations
	std::vector<HWND> m_ClientList;

	TCheckBox *m_CheckboxList[PT_COUNT - 1];
	TLabel *m_LabelsList[PT_COUNT - 1];

	HMODULE m_Dll;

	TCheckBox *m_FileCheckboxList[PT_COUNT - 1];
	TLabel *m_FileLabelsList[PT_COUNT - 1];

	void DisableRuntimePatches();
	void DisableFilePatches();

	void SetCheckStateNoProcess(TCheckBox *object, const bool &state);

public:		// User declarations
	__fastcall TPatcher(TComponent* Owner);

	void __fastcall OnMessagePathInfo(TMessage &Message);

#pragma warn -inl
BEGIN_MESSAGE_MAP
	MESSAGE_HANDLER(PM_INFO, TMessage, OnMessagePathInfo)
END_MESSAGE_MAP(TForm)
};
//---------------------------------------------------------------------------
extern PACKAGE TPatcher *Patcher;
//---------------------------------------------------------------------------
#endif
