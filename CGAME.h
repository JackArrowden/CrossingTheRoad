#pragma once

#include "ConsoleHandle.h"
#include "CPEOPLE.h"
#include "CANIMAL.h"
#include "CVEHICLE.h"
#include "CTRAFFIC_LIGHT.h"
#include "CAR.h"
#include "CTRUCK.h"
#include "CTRAIN.h"
#include "CBIRD.h"
#include "CAT.h"
#include "CMOUSE.h"
using namespace std;

class CGAME
{
private:
	CPEOPLE* mainChar;
	int numOfCars;
	CAR* car;
	int numOfTrucks;
	CTRUCK* truck;
	int numOfTrains;
	CTRAIN* train;

	int numOfBirds;
	CBIRD* bird;
	int numOfCats;
	CAT* cat;
	int numOfMouse;
	CMOUSE* mouse;
	int m_isRunning;
	int m_currentLevel;

	//void copyGame(const CGAME&);
	void clearGame();

	//static void drawRectangle(ConsoleHandle*, int, int, int, int);//Vẽ hình chữ nhật bao quanh 2 đỉnh tham số (trái trên, phải dưới)
	//static void removeRectangle(ConsoleHandle*, int, int, int, int);
	//void soundSetting(ConsoleHandle*, bool&);
	//int levelSetting(ConsoleHandle*, int);
	//int crashPos(CANIMAL, int);
	//int crashPos(CVEHICLE*, int);
	//int crashPos();
public:
	//Tọa độ khung game
	static const int MAX_LEVEL;
	static const int LEFT;
	static const int RIGHT;
	static const int TOP;
	static const int BOTTOM;
	//----------------------------
	static const char TITLE[][82];
	static const string MENU[];
	static const string INSTRUCTIONS[];
	static const string SETTINGS[];

	virtual void tell();
};

