#pragma once
#include "CANIMAL.h"

#define CAT_LINK_IMAGE "image\\gameWindow\\cat.bmp"
#define CAT_TOP 50
#define CAT_BOTTOM 10
#define CAT_LEFT 15
#define CAT_RIGHT 90
#define CAT_PER 1

class CAT final : protected CANIMAL
{
public:
	static const bitmapHandMake image;
	CAT(int startX, int startY, int direction);
	void tell();
	void Move(int deltaX);
	void draw(Render_State& screen);
	int getRightX();
	int getLeftX();
};

