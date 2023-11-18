#pragma once
#include "CANIMAL.h"

#define BIRD_TOP 10
#define BIRD_BOTTOM 1
#define BIRD_WIDTH 20
#define BIRD_LINK_IMAGE "bird.bmp"

class CBIRD final : public CANIMAL
{
	static const bitmapHandMake image;
public:
	CBIRD(int startX, int startY, int direction);
	void tell();
	void Move(int deltaX);
	void draw(Render_State& screen);
	//void DropShit(); // Thả shit tác động người chơi
};

