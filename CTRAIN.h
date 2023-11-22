#pragma once
#include "CVEHICLE.h"
#include "CTRAFFIC_LIGHT.h"
#include <wincrypt.h>

#define TRAIN_TOP 10
#define TRAIN_BOTTOM 1
#define TRAIN_LEFT 1

#define LOCOMOTIVE_WIDTH 20
#define LOCOMOTIVE_LINK_IMAGE "image\\train.bmp"

#define CARRIGE_WIDTH 20
#define CARRIGE_LINK_IMAGE "image\\train.bmp"

class CTRAIN final : public CVEHICLE
{
	int numCarriges;
	static const bitmapHandMake imageCarrige;
	static const bitmapHandMake imageLocomotive;
public:
	CTRAIN(int startX, int startY, int direction, int numCarriges);
	void tell();
	void Move(int deltaX);
	void draw(Render_State& screen);
	int getRightX() const;
	int getLeftX() const;
};

