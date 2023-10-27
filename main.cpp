#include "CGAME.h"
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <bit>
#define PI 3.14
int main() {

	//::ReleaseDC(m_hWnd, hdc);
	cout << "HI" << endl;
	/*CBIRD* bird = new CBIRD;
	CAT* cat = new CAT;
	CMOUSE* mouse = new CMOUSE;
	CTRUCK* truck = new CTRUCK;
	CAR* car = new CAR;
	CTRAIN* train = new CTRAIN;*/
	
	/*bird->tell();
	Sleep(300);
	cat->tell();
	Sleep(300);
	mouse->tell();
	Sleep(400);
	truck->tell();
	Sleep(300);*/
	//car->tell();
	//Sleep(300);
	//train->tell();
	CGAME* game = new CGAME;
	game->tell();

	
	/**delete bird;
	delete cat;
	delete mouse;
	delete car;
	delete train;
	delete truck;*/
	PlaySound(TEXT("Sound\\BACKGROUND.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	cout << "Hello"; 
	// _getch();
	//PlaySound(0, 0, 0);
	char ch = _getch();
	cout << ch;
	delete game;

	return 1;
}