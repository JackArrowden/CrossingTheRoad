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
void CGAME::clearGame() {
	delete mainChar;
	//delete playFrame;
	delete[]truck;
	delete[]car;
	delete[]train;
	delete[]bird;
	delete[]cat;
	delete[]mouse;
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
