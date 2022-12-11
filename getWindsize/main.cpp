#include"function.h"

using namespace std;

//參考
//https://stackoverflow.com/questions/22259936/c-move-mouse-in-windows-using-setcursorpos
//https://stackoverflow.com/questions/14989062/set-a-window-to-be-topmost
// https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getwindowtexta

// Created by Zodiac
// Discord: Hippo#6524

int main()
{
	HWND window = FindWindow(NULL, GetActiveWindowTitle().c_str());
	if (checkwindow(window)!= false)
	{
		getRefreshrate();
	}

	while (checkwindow(window)!= false)
	{
			SetConsoleTitle(Randomtitle(26).c_str()); //cast into const
			system("cls");
			CenterCMD(window);
			GetScreenResolution();
			std::cout << "Current Tab Name: " << GetActiveWindowTitle() << std::endl;
			std::cout << "Current Process ID: " << GetPID() << std::endl;
			GetCurrentWZ();
			GetAccess();
			Sleep(refresh);
	}

	return 0;
}

