#include "Screen.h"

Screen::Screen()
{
	windowState = 1;
	curState = 0;
	gameSound = objectSound = true;
	backClick = gameSoundClick_temp = gameStage1Clicked = false;
	buttonState = 0; // set all button to false (all bits to zero)
	game = nullptr;
}

void Screen::drawMenuWindow()
{
	//render_state.drawImage(background1, 0, 0, 1);
	//render_state.drawImage(nameGamePic, 120, 470, 4, DEFAULT_BACKGROUND_COLOR);

	for (int i = 0; i < listButton.size(); i++)
		if ((buttonState >> i) & 1)
			listButton[i].draw(render_state);
}

void Screen::drawGameWindow()
{
	if (!game) return;
	game->Draw(render_state);
}



void Screen::render(HDC& hdc)
{
	StretchDIBits(hdc, 0, 0, render_state.width, render_state.height, 0, 0, render_state.width, render_state.height, render_state.memory, &render_state.bitmap_info, DIB_RGB_COLORS, SRCCOPY);
}
