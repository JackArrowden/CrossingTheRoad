#pragma once
#include "CANIMAL.h"

#define CAT_TOP 10
#define CAT_BOTTOM 1
#define CAT_WIDTH 20
#define CAT_LINK_IMAGE "cat.bmp"

class CAT final : protected CANIMAL
{
	static const bitmapHandMake image;
public:
	CAT(int startX, int startY, int direction);
	void tell();
	void Move(int deltaX);
	void draw(Render_State& screen);
};

