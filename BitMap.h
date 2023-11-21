#pragma once
#include "ConsoleHandle.h"
using namespace std;
typedef unsigned int u32;
typedef unsigned char u8;

#ifndef DEFAULT_BACKGROUND_COLOR
#define DEFAULT_BACKGROUND_COLOR 16777215
#endif // !DEFAULT_BACKGROUND_COLOR
#ifndef UNCOLOR_NUMBER
#define UNCOLOR_NUMBER 2147483648
#endif // !UNCOLOR_NUMBER


#pragma pack(2)
struct BMPHeader {
	unsigned short signature; // "BM" for a valid BMP file
	unsigned int fileSize;   // Size of the BMP file
	unsigned int reserved;   // Reserved value (unused)
	unsigned int dataOffset; // Offset to the beginning of the pixel data
};

#pragma pack(2)
struct BMPInfoHeader {
	unsigned int headerSize;       // Size of the info header (should be 40 bytes)
	int width;                     // Width of the image in pixels
	int height;                    // Height of the image in pixels
	unsigned short planes;         // Number of color planes (should be 1)
	unsigned short bitCount;       // Number of bits per pixel (e.g., 24 bits)
	unsigned int compression;      // Compression method (0 for uncompressed)
	unsigned int dataSize;         // Size of the raw image data
	int hResolution;               // Horizontal resolution (pixels per meter)
	int vResolution;               // Vertical resolution (pixels per meter)
	unsigned int colors;          // Number of colors in the color palette (0 for full color)
	unsigned int importantColors; // Number of important colors (usually ignored)
};

class bitmapHandMake {
public:
	int height;
	int width;
	u32* memory;
	bitmapHandMake() : memory(NULL), height(0), width(0) {}
	bitmapHandMake(const std::string& path);
	~bitmapHandMake();
	bool readBitmapFile(const std::string& path);
};


class Render_State {
	
public:
	static const double renderScale;	
	int height, width;
	void* memory;
	BITMAPINFO bitmap_info;

	Render_State(); 
	~Render_State();

	void resize(int, int);
	void drawReac2P(int leftX, int rightX, int bottomY, int topY, u32 color);
	void clearScreen(u32 color);
	void drawImage(const bitmapHandMake& image, int leftX, int bottomY, int perPixel, u32 backgrouundColor = UNCOLOR_NUMBER);
	void drawReverseImage(const bitmapHandMake& image, int leftX, int bottomY, int perPixel, u32 backgrouundColor = UNCOLOR_NUMBER);
	void dynamicDrawReac(double dynamicLeftX, double dynamicBottomY, double dynamicHalfSizeX, double dynamicHalfSizeY, u32 color);

	void draw_text(const char* text, float x, float y, float size, u32 color);
	void draw_number(int number, float x, float y, float size, u32 color);
};


