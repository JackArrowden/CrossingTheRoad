#pragma once
#include "CANIMAL.h"

#define CAT_LINK_IMAGE "image\\gameWindow\\cat.bmp"
#define CAT_TOP 35
#define CAT_BOTTOM 10
#define CAT_LEFT 15
#define CAT_RIGHT 80
#define CAT_PER 1

class CAT final : public CANIMAL
{
public:
	static const bitmapHandMake image;
	CAT(int startX, int startY, int direction);
	CAT();
	void tell();
	void Move(int deltaX);
	void draw(Render_State& screen);
	int getRightX() const;
	int getLeftX() const;
};

