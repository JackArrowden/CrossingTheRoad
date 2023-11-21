#pragma once
#include "CANIMAL.h"

#define BIRD_TOP 10
#define BIRD_BOTTOM 1
#define BIRD_LEFT 10
#define BIRD_RIGHT 20
#define BIRD_PER 1
#define BIRD_LINK_IMAGE "image\\gameWindow\\bird.bmp"

class CBIRD final : public CANIMAL
{
public:
	static const bitmapHandMake image;
	CBIRD(int startX, int startY, int direction);
	void tell();
	void Move(int deltaX);
	void draw(Render_State& screen);
	//void DropShit(); // Thả shit tác động người chơi
};

