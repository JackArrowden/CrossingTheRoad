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
		u32 idxInImage = (y - bottomY + 1) * image.width * perPixel + perPixel / 2 * (image.width - 1) - (startX - leftX) * perPixel - 1;
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

const char* letters[][7] = {
	" 00",
	"0  0",
	"0  0",
	"0000",
	"0  0",
	"0  0",
	"0  0",

	"000",
	"0  0",
	"0  0",
	"000",
	"0  0",
	"0  0",
	"000",

	" 000",
	"0",
	"0",
	"0",
	"0",
	"0",
	" 000",

	"000",
	"0  0",
	"0  0",
	"0  0",
	"0  0",
	"0  0",
	"000",

	"0000",
	"0",
	"0",
	"000",
	"0",
	"0",
	"0000",

	"0000",
	"0",
	"0",
	"000",
	"0",
	"0",
	"0",

	" 000",
	"0",
	"0",
	"0 00",
	"0  0",
	"0  0",
	" 000",

	"0  0",
	"0  0",
	"0  0",
	"0000",
	"0  0",
	"0  0",
	"0  0",

	"000",
	" 0",
	" 0",
	" 0",
	" 0",
	" 0",
	"000",

	" 000",
	"   0",
	"   0",
	"   0",
	"0  0",
	"0  0",
	" 000",

	"0  0",
	"0  0",
	"0 0",
	"00",
	"0 0",
	"0  0",
	"0  0",

	"0",
	"0",
	"0",
	"0",
	"0",
	"0",
	"0000",

	"00 00",
	"0 0 0",
	"0 0 0",
	"0   0",
	"0   0",
	"0   0",
	"0   0",

	"00  0",
	"0 0 0",
	"0 0 0",
	"0 0 0",
	"0 0 0",
	"0 0 0",
	"0  00",

	"0000",
	"0  0",
	"0  0",
	"0  0",
	"0  0",
	"0  0",
	"0000",

	" 000",
	"0  0",
	"0  0",
	"000",
	"0",
	"0",
	"0",

	" 000 ",
	"0   0",
	"0   0",
	"0   0",
	"0 0 0",
	"0  0 ",
	" 00 0",

	"000",
	"0  0",
	"0  0",
	"000",
	"0  0",
	"0  0",
	"0  0",

	" 000",
	"0",
	"0 ",
	" 00",
	"   0",
	"   0",
	"000 ",

	"000",
	" 0",
	" 0",
	" 0",
	" 0",
	" 0",
	" 0",

	"0  0",
	"0  0",
	"0  0",
	"0  0",
	"0  0",
	"0  0",
	" 00",

	"0   0",
	"0   0",
	"0   0",
	"0   0",
	"0   0",
	" 0 0",
	"  0",

	"0   0 ",
	"0   0",
	"0   0",
	"0 0 0",
	"0 0 0",
	"0 0 0",
	" 0 0 ",

	"0   0",
	"0   0",
	" 0 0",
	"  0",
	" 0 0",
	"0   0",
	"0   0",

	"0   0",
	"0   0",
	" 0 0",
	"  0",
	"  0",
	"  0",
	"  0",

	"0000",
	"   0",
	"  0",
	" 0",
	"0",
	"0",
	"0000",

	"",
	"",
	"",
	"",
	"",
	"",
	"0",

	"   0",
	"  0",
	"  0",
	" 0",
	" 0",
	"0",
	"0",
};


void Render_State::draw_text(const char* text, float x, float y, float size, u32 color) {
	float half_size = size * .5f;
	float original_y = y;

	while (*text) {
		if (*text != 32) {
			const char** letter;
			if (*text == 47) letter = letters[27];
			else if (*text == 46) letter = letters[26];
			else letter = letters[*text - 'A'];
			float original_x = x;

			for (int i = 0; i < 7; i++) {
				const char* row = letter[i];
				while (*row) {
					if (*row == '0') {
						dynamicDrawReac(x, y, half_size, half_size, color);
					}
					x += size;
					row++;
				}
				y -= size;
				x = original_x;
			}
		}
		text++;
		x += size * 6.f;
		y = original_y;
	}
}

void Render_State::draw_number(int number, float x, float y, float size, u32 color) {
	float half_size = size * .5f;

	bool drew_number = false;
	while (number || !drew_number) {
		drew_number = true;

		int digit = number % 10;
		number = number / 10;

		switch (digit) {
		case 0: {
			dynamicDrawReac(x - size, y, half_size, 2.5f * size, color);
			dynamicDrawReac(x + size, y, half_size, 2.5f * size, color);
			dynamicDrawReac(x, y + size * 2.f, half_size, half_size, color);
			dynamicDrawReac(x, y - size * 2.f, half_size, half_size, color);
			x -= size * 4.f;
		} break;

		case 1: {
			dynamicDrawReac(x + size, y, half_size, 2.5f * size, color);
			x -= size * 2.f;
		} break;

		case 2: {
			dynamicDrawReac(x, y + size * 2.f, 1.5f * size, half_size, color);
			dynamicDrawReac(x, y, 1.5f * size, half_size, color);
			dynamicDrawReac(x, y - size * 2.f, 1.5f * size, half_size, color);
			dynamicDrawReac(x + size, y + size, half_size, half_size, color);
			dynamicDrawReac(x - size, y - size, half_size, half_size, color);
			x -= size * 4.f;
		} break;

		case 3: {
			dynamicDrawReac(x - half_size, y + size * 2.f, size, half_size, color);
			dynamicDrawReac(x - half_size, y, size, half_size, color);
			dynamicDrawReac(x - half_size, y - size * 2.f, size, half_size, color);
			dynamicDrawReac(x + size, y, half_size, 2.5f * size, color);
			x -= size * 4.f;
		} break;

		case 4: {
			dynamicDrawReac(x + size, y, half_size, 2.5f * size, color);
			dynamicDrawReac(x - size, y + size, half_size, 1.5f * size, color);
			dynamicDrawReac(x, y, half_size, half_size, color);
			x -= size * 4.f;
		} break;

		case 5: {
			dynamicDrawReac(x, y + size * 2.f, 1.5f * size, half_size, color);
			dynamicDrawReac(x, y, 1.5f * size, half_size, color);
			dynamicDrawReac(x, y - size * 2.f, 1.5f * size, half_size, color);
			dynamicDrawReac(x - size, y + size, half_size, half_size, color);
			dynamicDrawReac(x + size, y - size, half_size, half_size, color);
			x -= size * 4.f;
		} break;

		case 6: {
			dynamicDrawReac(x + half_size, y + size * 2.f, size, half_size, color);
			dynamicDrawReac(x + half_size, y, size, half_size, color);
			dynamicDrawReac(x + half_size, y - size * 2.f, size, half_size, color);
			dynamicDrawReac(x - size, y, half_size, 2.5f * size, color);
			dynamicDrawReac(x + size, y - size, half_size, half_size, color);
			x -= size * 4.f;
		} break;

		case 7: {
			dynamicDrawReac(x + size, y, half_size, 2.5f * size, color);
			dynamicDrawReac(x - half_size, y + size * 2.f, size, half_size, color);
			x -= size * 4.f;
		} break;

		case 8: {
			dynamicDrawReac(x - size, y, half_size, 2.5f * size, color);
			dynamicDrawReac(x + size, y, half_size, 2.5f * size, color);
			dynamicDrawReac(x, y + size * 2.f, half_size, half_size, color);
			dynamicDrawReac(x, y - size * 2.f, half_size, half_size, color);
			dynamicDrawReac(x, y, half_size, half_size, color);
			x -= size * 4.f;
		} break;

		case 9: {
			dynamicDrawReac(x - half_size, y + size * 2.f, size, half_size, color);
			dynamicDrawReac(x - half_size, y, size, half_size, color);
			dynamicDrawReac(x - half_size, y - size * 2.f, size, half_size, color);
			dynamicDrawReac(x + size, y, half_size, 2.5f * size, color);
			dynamicDrawReac(x - size, y + size, half_size, half_size, color);
			x -= size * 4.f;
		} break;
		}

	}
}