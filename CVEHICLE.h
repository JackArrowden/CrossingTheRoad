#pragma once
#pragma comment(lib, "winmm.lib")
#include <Windows.h>
#include <string>
#include <sstream>
#include <conio.h>
#include <thread>
#include <sstream>
#include <fstream>
#include <mmsystem.h>
#include <iostream>

class CVEHICLE
{
private:
	int mX, mY;
public:
	//virtual void Move(int, int) = 0;
	virtual void tell();

};


