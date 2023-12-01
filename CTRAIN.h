#pragma once
#include "CVEHICLE.h"
#include "CTRAFFIC_LIGHT.h"
#include <wincrypt.h>

#define TRAIN_RIGHT 0
#define TRAIN_TOP 70
#define TRAIN_BOTTOM 20
#define TRAIN_LEFT 1
#define TRAIN_PER 2

#define LOCOMOTIVE_LINK_IMAGE "image\\gameWindow\\train_h.bmp"
#define CARRIGE_LINK_IMAGE "image\\gameWindow\\train_e.bmp"

class CTRAIN final : public CVEHICLE
{
	int numCarriges;
	static const bitmapHandMake imageCarrige;
	static const bitmapHandMake imageLocomotive;
public:
	CTRAIN(int startX, int startY, int direction, int numCarriges);
	CTRAIN();
	bool setCarriges(int numCarriges);
	void tell();
	void Move(int deltaX);
	void draw(Render_State& screen);
	int getRightX() const;
	int getLeftX() const;

	friend istream& operator>>(istream& in, CTRAIN& x);
	friend ostream& operator<<(ostream& out, const CTRAIN& x);
};

