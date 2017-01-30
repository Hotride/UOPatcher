//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainScript.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPatcher *Patcher;
//---------------------------------------------------------------------------
BOOL SetPrivilege(HANDLE hToken, LPCTSTR lpszPrivilege, BOOL bEnablePrivilege)
{
	TOKEN_PRIVILEGES tp;
	LUID luid;

	if (!LookupPrivilegeValue(NULL, lpszPrivilege, &luid))
		return FALSE;

	tp.PrivilegeCount = 1;
	tp.Privileges[0].Luid = luid;

	if (bEnablePrivilege)
		tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	else
		tp.Privileges[0].Attributes = 0;

	if (!AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(TOKEN_PRIVILEGES), (PTOKEN_PRIVILEGES)NULL, (PDWORD)NULL))
		return FALSE;

	return TRUE;
}
//---------------------------------------------------------------------------
BOOL EnableDebugPrivilages()
{
	HANDLE hToken;

	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
		return FALSE;

	return SetPrivilege(hToken, SE_DEBUG_NAME, TRUE);
}
//---------------------------------------------------------------------------
void __fastcall TPatcher::OnMessagePathInfo(TMessage &M)
{
	HWND hwnd = 0;

	if (lb_ClientList->ItemIndex != -1)
		hwnd = m_ClientList[lb_ClientList->ItemIndex];

	if ((HWND)M.LParam == hwnd)
	{
		unsigned int patchIndex = (M.WParam >> 16) - 1;

		if (patchIndex < PT_COUNT - 1 && m_CheckboxList[patchIndex] != NULL)
		{
			unsigned int patchState = (M.WParam & 0xFFFF);
			bool enabled = (patchState != PS_NOT_FOUND);

			m_CheckboxList[patchIndex]->Enabled = enabled;

			bool state = (patchState == PS_ENABLE);
			SetCheckStateNoProcess(m_CheckboxList[patchIndex], state);

			if (enabled)
				m_LabelsList[patchIndex]->Font->Color = (state ? clGreen : clRed);
			else
				m_LabelsList[patchIndex]->Font->Color = clGray;
		}
	}
	else
		M.Result = DefWindowProc(Handle, M.Msg, M.WParam, M.LParam);
}
//---------------------------------------------------------------------------
__fastcall TPatcher::TPatcher(TComponent* Owner)
: TForm(Owner), m_Dll(0)
{
}
//---------------------------------------------------------------------------
void __fastcall TPatcher::FormCreate(TObject *Sender)
{
	pc_Main->ActivePageIndex = 0;

	m_CheckboxList[0] = cb_FPS;
	m_CheckboxList[1] = cb_Stamina;
	m_CheckboxList[2] = cb_AlwaysLight;
	m_CheckboxList[3] = cb_PaperdollSlots;
	m_CheckboxList[4] = NULL;
	m_CheckboxList[5] = NULL;
	m_CheckboxList[6] = cb_OptionsNotification;
	m_CheckboxList[7] = NULL;

	m_LabelsList[0] = lb_TextFPS;
	m_LabelsList[1] = lb_TextStamina;
	m_LabelsList[2] = lb_TextAlwaysLight;
	m_LabelsList[3] = lb_TextPaperdollSlots;
	m_LabelsList[4] = NULL;
	m_LabelsList[5] = NULL;
	m_LabelsList[6] = lb_TextOptionsNotification;
	m_LabelsList[7] = NULL;

	m_FileCheckboxList[0] = NULL;
	m_FileCheckboxList[1] = cb_FileStamina;
	m_FileCheckboxList[2] = cb_FileAlwaysLight;
	m_FileCheckboxList[3] = cb_FilePaperdollSlots;
	m_FileCheckboxList[4] = cb_FileSplashScreen;
	m_FileCheckboxList[5] = cb_FileResolution;
	m_FileCheckboxList[6] = cb_FileOptionsNotification;
	m_FileCheckboxList[7] = cb_FileMultiUO;

	m_FileLabelsList[0] = NULL;
	m_FileLabelsList[1] = lb_FileTextStamina;
	m_FileLabelsList[2] = lb_FileTextAlwaysLight;
	m_FileLabelsList[3] = lb_FileTextPaperdollSlots;
	m_FileLabelsList[4] = lb_FileTextSplashScreen;
	m_FileLabelsList[5] = lb_FileTextResolution;
	m_FileLabelsList[6] = lb_FileTextOptionsNotification;
	m_FileLabelsList[7] = lb_FileTextMultiUO;

	EnableDebugPrivilages();
	img_RefreshClick(img_Refresh);
	DisableFilePatches();

	tm_Creation->Enabled = true;

	String path = ExtractFilePath(Application->ExeName) + "\\UOMod.dll";

	if (FileExists(path))
		m_Dll = LoadLibrary(path.t_str());
}
//---------------------------------------------------------------------------
void __fastcall TPatcher::FormDestroy(TObject *Sender)
{
	if (m_Dll != 0)
	{
		FreeLibrary(m_Dll);
		m_Dll = 0;
	}
}
//---------------------------------------------------------------------------
void __fastcall TPatcher::bt_SetClientPatchClick(TObject *Sender)
{
	if (od_ClientPath->Execute(Handle))
	{
		eb_ClientPath->Text = od_ClientPath->FileName;
		img_RefreshFilePatchesClick(img_RefreshFilePatches);
	}
}
//---------------------------------------------------------------------------
void __fastcall TPatcher::eb_ClientPathKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key == VK_RETURN)
		img_RefreshFilePatchesClick(img_RefreshFilePatches);
}
//---------------------------------------------------------------------------
void __fastcall TPatcher::lb_OrionGitHubClick(TObject *Sender)
{
	TLabel *obj = ((TLabel*)(Sender));

	if (obj->Tag == 0)
		ShellExecute(0, "Open", "https://github.com/Hotride/OrionUO", NULL, NULL, SW_SHOWNORMAL);
	else if (obj->Tag == 1)
		ShellExecute(0, "Open", "https://discord.gg/UcVKWzB", NULL, NULL, SW_SHOWNORMAL);
	else if (obj->Tag == 2)
		ShellExecute(0, "Open", "http://forum.orion-client.online", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------
void TPatcher::DisableRuntimePatches()
{
	for (int i = 0; i < PT_COUNT -1; i++)
	{
		if (m_CheckboxList[i] != NULL)
		{
			m_CheckboxList[i]->Enabled = false;
			SetCheckStateNoProcess(m_CheckboxList[i], false);
			m_LabelsList[i]->Font->Color = clGray;
		}
	}
}
//---------------------------------------------------------------------------
void TPatcher::DisableFilePatches()
{
	for (int i = 0; i < PT_COUNT -1; i++)
	{
		if (m_FileCheckboxList[i] != NULL)
		{
			m_FileCheckboxList[i]->Enabled = false;
			m_FileLabelsList[i]->Font->Color = clGray;
		}
	}
}
//---------------------------------------------------------------------------
void TPatcher::SetCheckStateNoProcess(TCheckBox *object, const bool &state)
{
	TNotifyEvent ev = object->OnClick;
	object->OnClick = NULL;
	object->Checked = state;
	object->OnClick = ev;
}
//---------------------------------------------------------------------------
void __fastcall TPatcher::img_RefreshClick(TObject *Sender)
{
	lb_ClientList->Items->Clear();
	m_ClientList.clear();

	DisableRuntimePatches();

	char *uoClassName[2] = { "Ultima Online", "Ultima Online Third Dawn" };

	for (int i = 0; i < 2; i++)
	{
		HWND hwnd = FindWindow(uoClassName[i], NULL);

		while (hwnd != 0)
		{
			char title[150] = { 0 };
			GetWindowText(hwnd, title, 150);

			lb_ClientList->Items->Add(title);
			m_ClientList.push_back(hwnd);

			hwnd = FindWindowEx(NULL, hwnd, uoClassName[i], NULL);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TPatcher::lb_ClientListClick(TObject *Sender)
{
	DisableRuntimePatches();

	if (pc_Main->ActivePage != ts_PatchMemory)
		return;

	if (lb_ClientList->ItemIndex == -1)
		return;

	HWND hwnd = m_ClientList[lb_ClientList->ItemIndex];

	HWND dllWindow = FindWindow(("UOModWindow_" + IntToHex((int)hwnd, 8)).t_str(), NULL);

	if (dllWindow == NULL)
	{
		String path = ExtractFilePath(Application->ExeName) + "\\UOMod.dll";

		if (!FileExists(path))
		{
			MessageBox(Handle, ("File not found:\n" + path).t_str(), "Error", MB_OK);
			return;
		}

		DWORD processID = 0;
		GetWindowThreadProcessId(hwnd, &processID);
		HANDLE hp = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, TRUE, processID);

		if (hp != NULL)
		{
			HANDLE hProcess = NULL, hThread = NULL;
			PWSTR pszLibFileRemote = NULL;

			__try
			{
				// Get a handle for the target process.
				hProcess = OpenProcess(
					PROCESS_QUERY_INFORMATION |   // Required by Alpha
					PROCESS_CREATE_THREAD     |   // For CreateRemoteThread
					PROCESS_VM_OPERATION      |   // For VirtualAllocEx/VirtualFreeEx
					PROCESS_VM_WRITE          |   // For WriteProcessMemory
					PROCESS_VM_READ,
					FALSE, processID);

				if (hProcess == NULL)
				{
					MessageBox(Handle, "Open process failed.", "Error", MB_OK);
					return;
				}

				// Calculate the number of bytes needed for the DLL's pathname
				int cch = 1 + lstrlenW(path.c_str());
				int cb  = cch * sizeof(WCHAR);

				// Allocate space in the remote process for the pathname
				pszLibFileRemote=(PWSTR)VirtualAllocEx(hProcess, NULL, cb, MEM_COMMIT, PAGE_READWRITE);

				if (pszLibFileRemote == NULL)
				{
					if (hProcess!=NULL)
						CloseHandle(hProcess);

					MessageBox(Handle, "Memory can't be selected.", "Error", MB_OK);

					return;
				}

				// Copy the DLL's pathname to the remote process's address space
				if (!WriteProcessMemory(hProcess, pszLibFileRemote, (PVOID) path.c_str(), cb, NULL))
				{
					if (pszLibFileRemote != NULL)
						VirtualFreeEx(hProcess, pszLibFileRemote, 0, MEM_RELEASE);

					if (hProcess != NULL)
						CloseHandle(hProcess);

					MessageBox(Handle, "Failed to write string in to the memory.", "Error", MB_OK);

					return;
				}

				// Get the real address of LoadLibraryW in Kernel32.dll
				PTHREAD_START_ROUTINE pfnThreadRtn = (PTHREAD_START_ROUTINE)
				GetProcAddress(GetModuleHandle(TEXT("Kernel32")), "LoadLibraryW");

				if (pfnThreadRtn == NULL)
				{
					if (pszLibFileRemote != NULL)
						VirtualFreeEx(hProcess, pszLibFileRemote, 0, MEM_RELEASE);

					if (hProcess != NULL)
						CloseHandle(hProcess);

					MessageBox(Handle, "LoadLibraryW not found in Kernel32.dll", "Error", MB_OK);

					return;
				}

				bool created = false;

				if (!created) // Create a remote thread that calls LoadLibraryW(DLLPathname)
					hThread = CreateRemoteThread(hProcess, NULL, 0, pfnThreadRtn, pszLibFileRemote, 0, NULL);

				if (hThread == NULL)
				{
					if (pszLibFileRemote != NULL)
						VirtualFreeEx(hProcess, pszLibFileRemote, 0, MEM_RELEASE);
					if (hProcess != NULL)
						CloseHandle(hProcess);

					//ShowMessage("Thrd error: " + IntToStr((int)GetLastError()));
					MessageBox(Handle, "Remote thread can't be created.", "Error", MB_OK);

					return;
				}

				// Wait for the remote thread to terminate
				WaitForSingleObject(hThread, INFINITE);
			}
			__finally
			{ // Now, we can clean everthing up

				// Free the remote memory that contained the DLL's pathname
				if (pszLibFileRemote != NULL)
					VirtualFreeEx(hProcess, pszLibFileRemote, 0, MEM_RELEASE);

				if (hThread != NULL)
					CloseHandle(hThread);

				if (hProcess != NULL)
					CloseHandle(hProcess);
			}

			CloseHandle(hp);
		}
		else
		{
			img_RefreshClick(img_Refresh);
			//MessageBox(Handle, "UO process not found!", "Error", MB_OK);
			return;
		}

		Sleep(500);
		dllWindow = FindWindow(("UOModWindow_" + IntToHex((int)hwnd, 8)).t_str(), NULL);
	}

	if (dllWindow != 0)
		SendMessage(dllWindow, PM_INFO, (DWORD)Handle, 0xFFFFFFFF);
}
//---------------------------------------------------------------------------
void __fastcall TPatcher::RuntimePatchClickProc(TObject *Sender)
{
	TCheckBox *box = (TCheckBox*)Sender;
	bool state = box->Checked;
	SetCheckStateNoProcess(box, false);

	HWND hwnd = m_ClientList[lb_ClientList->ItemIndex];
	HWND dllWindow = FindWindow(("UOModWindow_" + IntToHex((int)hwnd, 8)).t_str(), NULL);

	if (dllWindow == 0)
	{
		ShowMessage("UO patch window is not found!");
		return;
	}

	if (state)
		SendMessage(dllWindow, PM_ENABLE, (DWORD)Handle, box->Tag);
	else
		SendMessage(dllWindow, PM_DISABLE, (DWORD)Handle, box->Tag);
}
//---------------------------------------------------------------------------
void __fastcall TPatcher::TextLabelRuntimePatckClickProc(TObject *Sender)
{
	unsigned int index = ((TLabel*)Sender)->Tag - 1;

	if (index < PT_COUNT - 1 && m_CheckboxList[index] != NULL && m_CheckboxList[index]->Enabled)
		m_CheckboxList[index]->Checked = !m_CheckboxList[index]->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TPatcher::FileTextLabelRuntimePatckClickProc(TObject *Sender)
{
	unsigned int index = ((TLabel*)Sender)->Tag - 1;

	if (index < PT_COUNT - 1 && m_FileCheckboxList[index] != NULL && m_FileCheckboxList[index]->Enabled)
		m_FileCheckboxList[index]->Checked = !m_FileCheckboxList[index]->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TPatcher::tm_CreationTimer(TObject *Sender)
{
	int alpha = (int)AlphaBlendValue;
	alpha += 10;

	if (alpha >= 255)
	{
		alpha = 255;
		tm_Creation->Enabled = false;
		AlphaBlend = false;
	}

	AlphaBlendValue = (unsigned char)alpha;
}
//---------------------------------------------------------------------------
void __fastcall TPatcher::img_RefreshFilePatchesClick(TObject *Sender)
{
	DisableFilePatches();

	if (m_Dll == 0)
		return;

	GET_FILE_PATCHES_FUN *fun = (GET_FILE_PATCHES_FUN*)GetProcAddress(m_Dll, "GetFilePatches");

	if (fun != NULL)
	{
		DWORD patches = fun(eb_ClientPath->Text.t_str());

		for (int i = 1; i < PT_COUNT - 1; i++)
		{
			bool enabled = (patches & (1 << (i + 1)));

			if (m_FileCheckboxList[i] != NULL)
				m_FileCheckboxList[i]->Enabled = enabled;

			if (m_FileLabelsList[i] != NULL)
				m_FileLabelsList[i]->Font->Color = (enabled ? clWindowText : clGray);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TPatcher::bt_ClientPatchClick(TObject *Sender)
{
	if (m_Dll == 0)
		return;

	SET_FILE_PATCHES_FUN *fun = (SET_FILE_PATCHES_FUN*)GetProcAddress(m_Dll, "SetFilePatches");

	if (fun != NULL)
	{
		DWORD patches = 0;

		for (int i = 1; i < PT_COUNT - 1; i++)
		{
			if (m_FileCheckboxList[i] != NULL && m_FileCheckboxList[i]->Checked)
				patches |= (1 << (i + 1));
		}

		if (patches)
		{
			patches = fun(eb_ClientPath->Text.t_str(), patches);

			if (patches)
			{
				String str = "Installed patches:\r\n";

				for (int i = 1; i < PT_COUNT - 1; i++)
				{
					if (m_FileLabelsList[i] != NULL && (patches & (1 << (i + 1))))
						str += "+ " + m_FileLabelsList[i]->Caption + "\r\n";
				}

				str += "\r\n";

				String logPath = ExtractFilePath(Application->ExeName) + "\\path_log.txt";

				WORD fileMode = (FileExists(logPath) ? fmOpenReadWrite : fmCreate);

				TFileStream *fs = new TFileStream(logPath, fileMode, fmShareDenyWrite);

				if (fs != NULL)
				{
					fs->Position = fs->Size;

					SYSTEMTIME st;
					GetLocalTime(&st);

					String textData = "";
					textData.sprintf(L"Patch install %i.%i.%i %i:%i:%i:%i\r\n", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);

					fs->WriteBuffer(textData.t_str(), textData.Length());

					textData = "File:\r\n" + eb_ClientPath->Text + "\r\n";
					fs->WriteBuffer(textData.t_str(), textData.Length());

					fs->WriteBuffer(str.t_str(), str.Length());

					delete fs;
				}

				ShowMessage(str);
			}
		}
	}
}
//---------------------------------------------------------------------------

