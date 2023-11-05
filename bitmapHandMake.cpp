#include "bitmapHandMake.h"

bitmapHandMake::~bitmapHandMake()
{
	if (!memory) return;
	delete[] memory;
	height = 0;
	width = 0;
}

void bitmapHandMake::readBitmapFile(const std::string& path)
{
	std::ifstream file(path, std::ios::binary);

	if (!file.is_open()) {
		std::cerr << "Error: Could not open the BMP file" << std::endl;
		return;
	}

	BMPHeader bmpHeader;
	BMPInfoHeader bmpInfoHeader;

	// Read the BMP header
	file.read(reinterpret_cast<char*>(&bmpHeader), sizeof(BMPHeader));

	if (bmpHeader.signature != 0x4D42) {
		std::cerr << "Error: Not a valid BMP file" << std::endl;
		file.close();
		return;
	}

	// Read the BMP info header
	file.read(reinterpret_cast<char*>(&bmpInfoHeader), sizeof(BMPInfoHeader));

	// Check if the image is 24 bits per pixel (RGB)
	if (bmpInfoHeader.bitCount != 24) {
		std::cout << bmpInfoHeader.bitCount << '\n';
		std::cerr << "Error: Only 24-bit BMP files are supported" << std::endl;
		file.close();
		return;
	}

	// Calculate the size of the image data
	unsigned int imageSize = bmpInfoHeader.width * bmpInfoHeader.height * 3;
	height = bmpInfoHeader.height;
	width = bmpInfoHeader.width;
	if (memory != nullptr) delete[] memory;
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
}