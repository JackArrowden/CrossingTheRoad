#pragma once
#include "CANIMAL.h"

#define BIRD_TOP 35
#define BIRD_BOTTOM 5
#define BIRD_LEFT 15
#define BIRD_RIGHT 50
#define BIRD_PER 2
#define BIRD_LINK_IMAGE "image\\gameWindow\\bird.bmp"

class CBIRD final : public CANIMAL
{
public:
	static const bitmapHandMake image;
	CBIRD(int startX, int startY, int direction);
	void tell();
	void Move(int deltaX);
	void draw(Render_State& screen);
	int getRightX() const;
	int getLeftX() const;
	//void DropShit(); // Thả shit tác động người chơi
};

