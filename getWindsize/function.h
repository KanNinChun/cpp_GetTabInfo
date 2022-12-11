#pragma once
#include "wtypes.h"
#include <windows.h>
#include<string>
#include <iostream>

bool keypress;
double refresh;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


std::string Randomtitle(const size_t length)
{
	std::string r;
	static const char bet[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890" };
	srand((unsigned)time(NULL) * 5);
	for (int i = 0; i < length; ++i)
	{
		r += bet[rand() % (sizeof(bet) - 1)];
	}
	return r;
}

std::string GetActiveWindowTitle()
{
	char wnd_title[256];
	HWND hwnd = GetForegroundWindow(); // get handle of currently active window
	GetWindowText(hwnd, wnd_title, sizeof(wnd_title));
	return wnd_title;
}

DWORD GetPID()
{
	HWND hwnd = FindWindowA(0, GetActiveWindowTitle().c_str()); // GET the current window title
	DWORD ProcessID = NULL;

	if (GetWindowThreadProcessId(hwnd, &ProcessID) != NULL) // using current window therefore we can get each process pid 
	{

		return ProcessID;
		return 1;
	}
	else
	{
		system("cls");
		SetConsoleTextAttribute(hConsole, 91);
		std::cout << "Can't get ProcessID!";
		return -1; // return error
		std::cout << "Exit in 1 second";
		Sleep(1000);
		exit(-1); // Error exit
	}

	return -1;
}

void GetAccess()
{
	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GetPID());

	if (handle == INVALID_HANDLE_VALUE || GetPID() < 0)
	{
		system("cls");
		SetConsoleTextAttribute(hConsole, 91);
		std::cout << "Cannot obtain process!------> Access Denied !" << std::endl;
		std::cout << "EXE will be auto terminate in 1 second!" << std::endl;
		Sleep(1000);
		exit(-1);
	}
	else
	{
		std::cout << "Current Access state (R/W): Success" << std::endl;

	}

}

// Get the horizontal and vertical screen sizes in pixel
void GetScreenResolution()
{
	int horizontal = 0;
	int vertical = 0;
	RECT desktop;							  // RECT 存储一个矩形框的左上角坐标、宽度和高度

	const HWND hDesktop = GetDesktopWindow(); // Get a handle to the desktop window

	GetWindowRect(hDesktop, &desktop);		 // Get the size of screen to the variable desktop
	horizontal = desktop.right;				// The top left corner will have coordinates (0,0)
	vertical = desktop.bottom;				// and the bottom right corner will have coordinates

	std::cout << "Current Screen Weigth and height: " << horizontal << " x " << vertical << std::endl;
}

void GetCurrentWZ()

{
	int width = 0;
	int height = 0;
	RECT rect;
	HWND window = FindWindow(NULL, GetActiveWindowTitle().c_str());
	if (GetWindowRect(window, &rect))
	{
		width = rect.right - rect.left;
		height = rect.bottom - rect.top;
		std::cout << "Current Tab Resolution: " << height << " x " << width << std::endl;
	}
}

int getRefreshrate()
{
	system("cls");
	std::cout << "Enter refresh rate: Recommand (1)" << std::endl;
	std::cout << "Input: ";
	std::cin >> refresh;
	refresh *= 100;
	return refresh;
}

bool checkwindow(HWND& window)
{
	if (!window)
	{
		SetConsoleTextAttribute(hConsole, 91);
		system("cls");
		std::cout << "Window Not Found!" << std::endl;
		std::cout << "Program terminated in 1 second!" << std::endl;
		Sleep(1000);
		exit(-1);
		return false;
	}
	return true;
}

void CenterCMD(HWND& window)
{
	SetWindowPos(window, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE); // set the exe to top most ,so it wouldn't disappear when you click on other window
}
