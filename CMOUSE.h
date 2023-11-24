#pragma once
#include "CANIMAL.h"

#define	MOUSE_TOP 35
#define	MOUSE_BOTTOM 1
#define	MOUSE_RIGHT 40
#define MOUSE_LEFT 10
#define MOUSE_PER 3
#define	MOUSE_LINK_IMAGE "image\\gameWindow\\mouse.bmp"

class CMOUSE final : public CANIMAL
{
public:
	static const bitmapHandMake image;
	CMOUSE(int startX, int startY, int direction);
	CMOUSE();
	void tell();
	void Move(int deltaX);
	void draw(Render_State& screen);
	int getRightX() const;
	int getLeftX() const;
};

