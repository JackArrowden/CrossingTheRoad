#include "CGAME.h"

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
