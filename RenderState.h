#pragma once

#include "bitmapHandMake.h"
#include "CGAME.h"

class Render_State {
	inline int clamp(int min, int val, int max);
public:
	int height, width;
	void* memory;
	BITMAPINFO bitmap_info;

	Render_State();

	~Render_State();

	void resize(int newHeight, int newWidth);

	void drawReac2P(int leftX, int rightX, int bottomY, int topY, u32 color);

	void clearScreen(u32 color);

	void drawImageLB(const bitmapHandMake& image, int leftX, int bottomY, int perPixel);

	void drawImageC(const bitmapHandMake& image, int centerX, int centerY, int perPixel);

	void drawReac(int centerX, int centerY, const double& halfHeight, const double& halfWidth, u32 color);
};