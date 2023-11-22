#include "CGAME.h"
#include <conio.h>
/*CGAME::CGAME()
{
	srand(time(NULL));
	resetGame(1);
}

Game::Game(int level)
{
	srand(time(NULL));
	resetGame(level);
}*/


CGAME::CGAME()
{
	mainChar = NULL;
	numOfCars = 0;
	car = NULL;
	numOfTrucks = 0;
	truck = NULL;
	numOfTrains = 0;
	train = NULL;

	numOfBirds = 0;
	bird = NULL;
	numOfCats = 0;
	cat = NULL;
	numOfMouses = 0;
	mouse = NULL;
	m_isRunning = 0;
	m_currentLevel = 0;
	CurrentScore = 0;
	NameOfPlayer = "";
}

CGAME::CGAME(const std::string& file)
{

}

bool CGAME::readFile(const std::string& file)
{
	ifstream ifs(file);
	if (!ifs.is_open()) return false;
	clear();
	getline(ifs, NameOfPlayer);
	ifs >> CurrentScore;
	mainChar = new CPEOPLE();
	ifs >> *mainChar;

	ifs >> numOfCars;
	if (numOfCars > 0) car = new CAR[numOfCars];
	for (int i = 0; i < numOfCars; i++)
	{
		CVEHICLE* it = dynamic_cast<CVEHICLE*> (&car[i]);
		ifs >> *it;
	}

	ifs >> numOfTrucks;
	if (numOfTrucks > 0) truck = new CTRUCK[numOfTrucks];
	for (int i = 0; i < numOfTrucks; i++)
	{
		CVEHICLE* it = dynamic_cast<CVEHICLE*> (&truck[i]);
		ifs >> *it;
	}

	ifs >> numOfTrains;
	if (numOfTrains > 0) train = new CTRAIN[numOfTrains];
	for (int i = 0; i < numOfCars; i++) ifs >> train[i];

	ifs >> numOfBirds;
	if (numOfBirds > 0) bird = new CBIRD[numOfBirds];
	for (int i = 0; i < numOfBirds; i++)
	{
		CANIMAL* it = dynamic_cast<CANIMAL*> (&bird[i]);
		ifs >> *it;
	}

	ifs >> numOfCats;
	if (numOfCats > 0) cat = new CAT[numOfCats];
	for (int i = 0; i < numOfCats; i++)
	{
		CANIMAL* it = dynamic_cast<CANIMAL*> (&cat[i]);
		ifs >> *it;
	}

	ifs >> numOfMouses;
	if (numOfMouses > 0) mouse = new CMOUSE[numOfMouses];
	for (int i = 0; i < numOfMouses; i++)
	{
		CANIMAL* it = dynamic_cast<CANIMAL*> (&mouse[i]);
		ifs >> *it;
	}

	ifs.close();
	return true;
}

void CGAME::clear()
{
	m_isRunning = 0;
	m_currentLevel = 0;
	CurrentScore = 0;
	NameOfPlayer.clear();

	if (mainChar) {
		delete mainChar;
		mainChar = NULL;
	}
	if (numOfCars) {
		delete[] car;
		numOfCars = 0;
		car = NULL;
	}
	if (numOfTrucks) {
		delete[] truck;
		numOfTrucks = 0;
		truck = NULL;
	}
	if (numOfTrains) {
		delete[] train;
		numOfTrains = 0;
		train = NULL;
	}

	if (numOfBirds) {
		delete[] bird;
		numOfBirds = 0;
		bird = NULL;
	}
	if (numOfCats) {
		delete[] cat;
		numOfCats = 0;
		cat = NULL;
	}
	if (numOfMouses) {
		delete[] mouse;
		numOfMouses = 0;
		mouse = NULL;
	}
}

void CGAME::tell()
{
	if (PlaySound(TEXT("Sound\\BACKGROUND.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC)) 
	{
		// Sound started playing successfully
		// You can add additional code here if needed
		//getch();
		//PlaySound(0, 0, 0);
		//getch();
	}
	else {
		// Error handling
		DWORD error = GetLastError();
		if (error != MMSYSERR_NOERROR) {
			// Handle the error
			// You can print an error message or perform other actions
		}
	}

}

void CGAME::Draw()
{

}
