#include "RenderState.h"

inline int Render_State::clamp(int min, int val, int max)
{
	if (val < min) return min;
	if (val > max) return max;
	return val;
}

Render_State::Render_State() : memory(NULL), height(0), width(0) {
	bitmap_info.bmiHeader.biSize = sizeof(bitmap_info.bmiHeader);
	bitmap_info.bmiHeader.biWidth = width;
	bitmap_info.bmiHeader.biHeight = height;
	bitmap_info.bmiHeader.biPlanes = 1;
	bitmap_info.bmiHeader.biBitCount = 32;
	bitmap_info.bmiHeader.biCompression = BI_RGB;
}

Render_State::~Render_State()
{
	if (memory != 0)
	{
		VirtualFree(memory, 0, MEM_RELEASE);
		height = 0;
		width = 0;
	}
}

void Render_State::resize(int newHeight, int newWidth)
{
	height = newHeight;
	width = newWidth;
	int size = width * height * sizeof(u32);
	if (memory) VirtualFree(memory, 0, MEM_RELEASE);
	memory = VirtualAlloc(0, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	bitmap_info.bmiHeader.biSize = sizeof(bitmap_info.bmiHeader);
	bitmap_info.bmiHeader.biWidth = width;
	bitmap_info.bmiHeader.biHeight = height;
}

void Render_State::drawReac2P(int leftX, int rightX, int bottomY, int topY, u32 color)
{
	//check and fix the input data
	leftX = clamp(0, leftX, width);
	rightX = clamp(0, rightX, width);
	bottomY = clamp(0, bottomY, height);
	topY = clamp(0, topY, height);

	for (int y = bottomY; y < topY; y++)
	{
		u32* pixel = (u32*)memory + y * width + leftX;
		for (int x = leftX; x < rightX; x++)
		{
			*pixel = color;
			pixel++;
		}
	}
}

void Render_State::clearScreen(u32 color)
{
	for (int y = 0; y < height; y++)
	{
		u32* pixel = (u32*)memory + y * width;
		for (int x = 0; x < width; x++)
		{
			*pixel = color;
			pixel++;
		}
	}
}

void Render_State::drawImageLB(const bitmapHandMake& image, int leftX, int bottomY, int perPixel = 1)
{
	if (perPixel < 0) return;
	int y0 = max(0, bottomY);
	int x0 = max(0, leftX);
	for (int y = y0; y < min(height, image.height / perPixel + bottomY); y++)
	{
		u32* pixel = (u32*)memory + y * width + x0;
		u32 idxInImage = (y - bottomY) * image.width * perPixel + perPixel / 2 * (image.width + 1) + (x0 - leftX) * perPixel;
		for (int x = x0; x < min(width, image.width / perPixel + leftX); x++)
		{
			*pixel = image.memory[idxInImage];
			pixel++;
			idxInImage += perPixel;
		}
	}

}

void Render_State::drawImageC(const bitmapHandMake& image, int centerX, int centerY, int perPixel = 1)
{
	//x *= render_state.height * render_scale;
	//y *= render_state.height * render_scale;
	//half_size_x *= render_state.height * render_scale;
	//half_size_y *= render_state.height * render_scale;

	//x += render_state.width / 2.f;
	//y += render_state.height / 2.f;

	//// Change to pixels
	//int x0 = x - half_size_x;
	//int x1 = x + half_size_x;
	//int y0 = y - half_size_y;
	//int y1 = y + half_size_y;

	//drawRect2P(x0, y0, x1, y1, color);




}

void Render_State::drawReac(int centerX, int centerY, const double& halfHeight, const double& halfWidth, u32 color)
{
}

