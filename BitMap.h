#pragma once
#include "ConsoleHandle.h"
using namespace std;
typedef unsigned int u32;
typedef unsigned char u8;

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
	~bitmapHandMake();
	/*{
		if (!memory) return;
		delete[] memory;
		height = 0;
		width = 0;
	}*/
};



class Render_State {
public:
	int height, width;
	void* memory;
	BITMAPINFO bitmap_info;

	Render_State(); /*{
		bitmap_info.bmiHeader.biSize = sizeof(bitmap_info.bmiHeader);
		bitmap_info.bmiHeader.biWidth = width;
		bitmap_info.bmiHeader.biHeight = height;
		bitmap_info.bmiHeader.biPlanes = 1;
		bitmap_info.bmiHeader.biBitCount = 32;
		bitmap_info.bmiHeader.biCompression = BI_RGB;
	}*/
	~Render_State();
	/*{
		if (memory != 0)
		{
			VirtualFree(memory, 0, MEM_RELEASE);
			height = 0;
			width = 0;
		}
	}*/

	void resize(int, int);
	

	void drawReac2P(int leftX, int rightX, int bottomY, int topY, u32 color);
	//{
	//	//check and fix the input data
	//	leftX = clamp(0, leftX, width);
	//	rightX = clamp(0, rightX, width);
	//	bottomY = clamp(0, bottomY, height);
	//	topY = clamp(0, topY, height);

	//	for (int y = bottomY; y < topY; y++)
	//	{
	//		u32* pixel = (u32*)memory + y * width + leftX;
	//		for (int x = leftX; x < rightX; x++)
	//		{
	//			*pixel = color;
	//			pixel++;
	//		}
	//	}
	//}

	void clearScreen(u32 color);
	/*{
		for (int y = 0; y < height; y++)
		{
			u32* pixel = (u32*)memory + y * width;
			for (int x = 0; x < width; x++)
			{
				*pixel = color;
				pixel++;
			}
		}
	}*/

	void drawImageLT(const bitmapHandMake& image, int leftX, int bottomY, int perPixel);
	/*{
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

	}*/

	void drawImageC(const bitmapHandMake& image, int centerX, int centerY, int perPixel)
	{
		//for(int y = )


	}

	void drawReac(int centerX, int centerY, const double& halfHeight, const double& halfWidth, u32 color)
	{

	}
};


bitmapHandMake readBitmapFile(const std::string& path);
//{
//	std::ifstream file(path, std::ios::binary);
//
//	bitmapHandMake res;
//	if (!file.is_open()) {
//		std::cerr << "Error: Could not open the BMP file" << std::endl;
//		return res;
//	}
//
//	BMPHeader bmpHeader;
//	BMPInfoHeader bmpInfoHeader;
//
//	// Read the BMP header
//	file.read(reinterpret_cast<char*>(&bmpHeader), sizeof(BMPHeader));
//
//	if (bmpHeader.signature != 0x4D42) {
//		std::cerr << "Error: Not a valid BMP file" << std::endl;
//		file.close();
//		return res;
//	}
//
//	// Read the BMP info header
//	file.read(reinterpret_cast<char*>(&bmpInfoHeader), sizeof(BMPInfoHeader));
//
//	// Check if the image is 24 bits per pixel (RGB)
//	if (bmpInfoHeader.bitCount != 24) {
//		std::cout << bmpInfoHeader.bitCount << '\n';
//		std::cerr << "Error: Only 24-bit BMP files are supported" << std::endl;
//		file.close();
//		return res;
//	}
//
//	// Calculate the size of the image data
//	unsigned int imageSize = bmpInfoHeader.width * bmpInfoHeader.height * 3;
//	res.height = bmpInfoHeader.height;
//	res.width = bmpInfoHeader.width;
//	res.memory = new u32[imageSize / 3];
//
//	// Create a buffer to store the pixel data
//	std::vector<char> imageData(imageSize);
//
//	// Read the pixel data
//	file.read(imageData.data(), imageSize);
//	file.close();
//
//	// Now, you can access the pixel data in the 'imageData' vector
//	// Print the RGB values of each pixel
//	for (size_t i = 0; i < imageSize; i += 3) {
//		unsigned char blue = static_cast<unsigned char>(imageData[i]);
//		unsigned char green = static_cast<unsigned char>(imageData[i + 1]);
//		unsigned char red = static_cast<unsigned char>(imageData[i + 2]);
//		//std::cout << "Pixel at position " << i / 3 << ": ";
//		unsigned int ARGB = (static_cast<int>(red) << 16) | (static_cast<int>(green) << 8) | static_cast<int>(blue);
//		res.memory[(int)i / 3] = ARGB;
//		//std::cout << static_cast<int>(red) << "," << static_cast<int>(green) << "," << static_cast<int>(blue) << std::endl;
//	}
//
//	return res;
//}