#include "BitMap.h"

inline int clamp(int min, int val, int max) {
	if (val < min) return min;
	if (val > max) return max;
	return val;
}

bitmapHandMake::bitmapHandMake(const std::string& path) : memory(NULL), height(0), width(0)
{
	readBitmapFile(path);
}

bitmapHandMake::~bitmapHandMake()
{
		if (!memory) return;
		delete[] memory;
		height = 0;
		width = 0;
}

// return false if there are any error when read file
// if read file is fail, the bitmapHandMake object would have value {memory(NULL), height(0), width(0)}
// this function would clear the data of the old image if any.
bool bitmapHandMake::readBitmapFile(const std::string& path)
{
	std::ifstream file(path, std::ios::binary);

	if (!file.is_open()) {
		std::cerr << "Error: Could not open the BMP file" << std::endl;
		return false;
	}

	BMPHeader bmpHeader;
	BMPInfoHeader bmpInfoHeader;

	// Read the BMP header
	file.read(reinterpret_cast<char*>(&bmpHeader), sizeof(BMPHeader));

	if (bmpHeader.signature != 0x4D42) {
		std::cerr << "Error: Not a valid BMP file" << std::endl;
		file.close();
		return false;
	}

	// Read the BMP info header
	file.read(reinterpret_cast<char*>(&bmpInfoHeader), sizeof(BMPInfoHeader));

	// Check if the image is 24 bits per pixel (RGB)
	if (bmpInfoHeader.bitCount != 24) {
		std::cout << bmpInfoHeader.bitCount << '\n';
		std::cerr << "Error: Only 24-bit BMP files are supported" << std::endl;
		file.close();
		return false;
	}

	// Calculate the size of the image data
	unsigned int imageSize = bmpInfoHeader.width * bmpInfoHeader.height * 3;
	height = bmpInfoHeader.height;
	width = bmpInfoHeader.width;

	if (memory)
	{
		delete[] memory;
		memory = NULL;
	}
	memory = new u32[imageSize / 3];

	// Create a buffer to store the pixel data
	std::vector<char> imageData(imageSize);

	// Read the pixel data
	file.read(imageData.data(), imageSize);
	file.close();

	// Now, you can access the pixel data in the 'imageData' vector
	// Print the RGB values of each pixel
	for (size_t i = 0; i < imageSize; i += 3) {
		unsigned char blue = static_cast<unsigned char>(imageData[i]);
		unsigned char green = static_cast<unsigned char>(imageData[i + 1]);
		unsigned char red = static_cast<unsigned char>(imageData[i + 2]);
		//std::cout << "Pixel at position " << i / 3 << ": ";
		unsigned int ARGB = (static_cast<int>(red) << 16) | (static_cast<int>(green) << 8) | static_cast<int>(blue);
		memory[(int)i / 3] = ARGB;
		//std::cout << static_cast<int>(red) << "," << static_cast<int>(green) << "," << static_cast<int>(blue) << std::endl;
	}
	return true;
}

/////////////////////////////////////////////
Render_State:: Render_State() : memory(NULL), width(0), height(0) {
	bitmap_info.bmiHeader.biSize = sizeof(bitmap_info.bmiHeader);
	bitmap_info.bmiHeader.biWidth = width;
	bitmap_info.bmiHeader.biHeight = height;
	bitmap_info.bmiHeader.biPlanes = 1;
	bitmap_info.bmiHeader.biBitCount = 32;
	bitmap_info.bmiHeader.biCompression = BI_RGB;
}

const double Render_State::renderScale = 0.01;

Render_State::~Render_State()
{
	if (memory != 0)
	{
		VirtualFree(memory, 0, MEM_RELEASE);
		height = 0;
		width = 0;
	}
	/*for (int i = 0; i < 203; i++)
		delete letters[i];
	delete[] letters;*/
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

void Render_State::drawImage(const bitmapHandMake& image, int leftX, int bottomY, int perPixel, u32 backgroundColor)
{
	if (perPixel < 0) return;
	int startY = clamp(0, bottomY, height); 
	int startX = clamp(0, leftX, width);
	int lastX = clamp(0, image.width / perPixel + leftX, width);
	int lastY = clamp(0, image.height / perPixel + bottomY, height);
	for (int y = startY; y < lastY; y++)
	{
		u32* pixel = (u32*)memory + y * width + startX;
		u32 idxInImage = (y - bottomY) * image.width * perPixel + perPixel / 2 * (image.width + 1) + (startX - leftX) * perPixel;
		for (int x = startX; x < lastX; x++)
		{
			if (backgroundColor != image.memory[idxInImage]) *pixel = image.memory[idxInImage];
			pixel++;
			idxInImage += perPixel;
		}
	}

}

void Render_State::drawReverseImage(const bitmapHandMake& image, int leftX, int bottomY, int perPixel, u32 backgroundColor)
{
	if (perPixel < 0) return;
	int startY = clamp(0, bottomY, height);
	int startX = clamp(0, leftX, width);
	int lastX = clamp(0, image.width / perPixel + leftX, width);
	int lastY = clamp(0, image.height / perPixel + bottomY, height);
	for (int y = startY; y < lastY; y++)
	{
		u32* pixel = (u32*)memory + y * width + startX;
		u32 idxInImage = (y - bottomY) * image.width * perPixel + (perPixel / 2 + 1) * image.width - 1 - perPixel / 2 - (startX - leftX) * perPixel;
		for (int x = startX; x < lastX; x++)
		{
			if (backgroundColor != image.memory[idxInImage]) *pixel = image.memory[idxInImage];
			pixel++;
			idxInImage -= perPixel;
		}
	}

}

void Render_State::dynamicDrawReac(double dynamicCenterX, double dynamicCenterY, double dynamicHalfSizeX, double dynamicHalfSizeY, u32 color) {
	
	double centerX = dynamicCenterX * height * renderScale;
	double centerY = dynamicCenterY * height * renderScale;
	double halfSizeX = dynamicHalfSizeX * height * renderScale;
	double halfSizeY = dynamicHalfSizeY * height * renderScale;

	centerX += width / 2.0;
	centerY += height / 2.0;

	// Change to pixels
	int leftX = centerX - halfSizeX;
	int rightX = centerX + halfSizeX;
	int bottomY = centerY - halfSizeY;
	int topY = centerY + halfSizeY;

	drawReac2P(leftX, rightX, bottomY, topY, color);
}