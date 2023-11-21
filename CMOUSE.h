#pragma once
#include "CANIMAL.h"

#define	MOUSE_TOP 10
#define	MOUSE_BOTTOM 1
#define	MOUSE_RIGHT 20
#define MOUSE_LEFT 10
#define MOUSE_PER 1
#define	MOUSE_LINK_IMAGE "image\\gameWindow\\mouse.bmp"

class CMOUSE final : protected CANIMAL
{
public:
	static const bitmapHandMake image;
	CMOUSE(int startX, int startY, int direction);
	void tell();
	void Move(int deltaX);
	void draw(Render_State& screen);
};

