#pragma once

#pragma comment(lib, "winmm.lib")
#include <Windows.h>
#include <string>
#include <sstream>
#include <conio.h>
#include <thread>
#include <fstream>
#include <mmsystem.h>
#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>
#include <map>
#include <vector>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <time.h>
#include <functional>

using namespace std;
#define ColorCode_Black			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15

#define default_ColorCode		7

#define key_Enter		13
#define Ctrl_V			22
#define key_Backspace	8
#define key_DownArrow	80
#define key_UpArrow		72
#define key_LeftArrow	75
#define key_RightArrow	77
#define VK_0			0x30
#define VK_1			0x31
#define VK_2			0x32
#define VK_3			0x33
#define VK_4			0x34
#define VK_5			0x35
#define VK_6			0x36
#define VK_7			0x37
#define VK_8			0x38
#define VK_9			0x39
#define VK_A			0x41
#define VK_B			0x42
#define VK_C			0x43
#define VK_D			0x44
#define VK_D			0x44
#define VK_E			0x45
#define VK_F			0x46
#define VK_G			0x47
#define VK_H			0x48
#define VK_I			0x49
#define VK_J			0x4A
#define VK_K			0x4B
#define VK_L			0x4C
#define VK_M			0x4D
#define VK_N			0x4E
#define VK_O			0x4F
#define VK_P			0x50
#define VK_Q			0x51
#define VK_R			0x52
#define VK_S			0x53
#define VK_T			0x54
#define VK_U			0x55
#define VK_V			0x56
#define VK_W			0x57
#define VK_X			0x58
#define VK_Y			0x59
#define VK_Z			0x5A
#define VK_DOC			0xBE
#define VK_SEMICOLON	0xBA
#define VK_SLASH		0xBF
//////////////////////////
#define IDS_APP_TITLE			103

#define IDR_MAINFRAME			128
#define IDD_WINDOWSPROJECT2_DIALOG	102
#define IDD_ABOUTBOX			103
#define IDM_ABOUT				104
#define IDM_EXIT				105
#define IDI_WINDOWSPROJECT2			107
#define IDI_SMALL				108
#define IDC_WINDOWSPROJECT2			109
#define IDC_MYICON				2
#ifndef IDC_STATIC
#define IDC_STATIC				-1
#endif
// Next default values for new objects
//
#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS

#define _APS_NO_MFC					130
#define _APS_NEXT_RESOURCE_VALUE	129
#define _APS_NEXT_COMMAND_VALUE		32771
#define _APS_NEXT_CONTROL_VALUE		1000
#define _APS_NEXT_SYMED_VALUE		110
#endif
#endif

class ConsoleHandle
{
public:
	static const int getSizeHelper = 1000;
	static const int rightShift = 20;
//private:
//	int m_width;
//	int m_height;
//
	void resizeConsole(int, int);
//	int getSize();
//	string getClipboardText();
//	void printString(string, int, int, int, size_t, size_t);
public:
//	ConsoleHandle();
//	ConsoleHandle(int, int);
//	~ConsoleHandle();
	void textcolor(int x);
	void fixConsoleWindow();
//	void gotoXY(int x, int y);
//	void clrscr();
//	void hideCursor();
//	void showCursor();
//	int width() { return m_width; }
//	int height() { return m_height; }
//	int midVertical() const;
//	int midHorizontal() const;
//	string textEdit(int row, int begin, int end);
};