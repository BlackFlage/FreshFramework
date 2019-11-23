#include "Surface.h"
#include <assert.h>

Surface::Surface(int width, int height)
	:
	width(width),
	height(height),
	pPixels(new Color[width * height])
{
}

Surface::Surface(std::string filePath)
{
	std::ifstream file(filePath, std::ios::binary);

	assert(file.good());

	BITMAPFILEHEADER bFileHeader;
	BITMAPINFOHEADER bInfoHeader;

	file.read(reinterpret_cast<char*>(&bFileHeader), sizeof(bFileHeader));
	file.read(reinterpret_cast<char*>(&bInfoHeader), sizeof(bInfoHeader));

	int yStart;
	int yEnd;
	int di;

	if (bInfoHeader.biHeight < 0)
	{
		height = -bInfoHeader.biHeight;
		yStart = 0;
		yEnd = height;
		di = 1;
	}
	else
	{
		height = bInfoHeader.biHeight;
		yStart = height - 1;
		yEnd = -1;
		di = -1;
	}

	width = bInfoHeader.biWidth;
	height = bInfoHeader.biHeight;

	pPixels = new Color[width * height];

	auto offBits = bFileHeader.bfOffBits;
	auto bitCount = bInfoHeader.biBitCount;
	const int padding = (4 - (width * 3) % 4) % 4;

	assert(bitCount == 24 || bitCount == 32); 
	const bool b32 = bInfoHeader.biBitCount == 32;

	file.seekg(0, file.beg);
	file.seekg(offBits, file.beg);

	for (int i = height - 1; i >= 0; i += di)
	{
		for (int j = 0; j < width; j++)
		{
			unsigned char r;
			unsigned char g;
			unsigned char b;

			file.read(reinterpret_cast<char*>(&r), sizeof(char));
			file.read(reinterpret_cast<char*>(&g), sizeof(char));
			file.read(reinterpret_cast<char*>(&b), sizeof(char));

			pPixels[i * width + j] = Color{ b, g, r };

			if (b32)
			{
				file.seekg(1, std::ios::cur);
			}
		}

		if (!b32)
		{
			file.seekg(padding, std::ios::cur);
		}
	}
}

Surface::Surface(std::string filePath, Color chroma)
	:
	chroma(chroma)
{
	std::ifstream file(filePath, std::ios::binary);

	assert(file.good());

	BITMAPFILEHEADER bFileHeader;
	BITMAPINFOHEADER bInfoHeader;

	file.read(reinterpret_cast<char*>(&bFileHeader), sizeof(bFileHeader));
	file.read(reinterpret_cast<char*>(&bInfoHeader), sizeof(bInfoHeader));

	int yStart;
	int yEnd;
	int di;

	if (bInfoHeader.biHeight < 0)
	{
		height = -bInfoHeader.biHeight;
		yStart = 0;
		yEnd = height;
		di = 1;
	}
	else
	{
		height = bInfoHeader.biHeight;
		yStart = height - 1;
		yEnd = -1;
		di = -1;
	}

	width = bInfoHeader.biWidth;
	height = bInfoHeader.biHeight;

	pPixels = new Color[width * height];

	auto offBits = bFileHeader.bfOffBits;
	auto bitCount = bInfoHeader.biBitCount;
	const int padding = (4 - (width * 3) % 4) % 4;

	assert(bitCount == 24 || bitCount == 32);
	const bool b32 = bInfoHeader.biBitCount == 32;

	file.seekg(0, file.beg);
	file.seekg(offBits, file.beg);

	for (int i = height - 1; i >= 0; i += di)
	{
		for (int j = 0; j < width; j++)
		{
			unsigned char r;
			unsigned char g;
			unsigned char b;

			file.read(reinterpret_cast<char*>(&r), sizeof(char));
			file.read(reinterpret_cast<char*>(&g), sizeof(char));
			file.read(reinterpret_cast<char*>(&b), sizeof(char));

			pPixels[i * width + j] = Color{ b, g, r };

			if (b32)
			{
				file.seekg(1, std::ios::cur);
			}
		}

		if (!b32)
		{
			file.seekg(padding, std::ios::cur);
		}
	}
}

Surface::Surface(Surface & s)
{
	width = s.width;
	height = s.height;

	pPixels = new Color[width * height];

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			pPixels[i * width + j] = s.pPixels[i * width + j];
		}
	}

}

Surface& Surface::operator=(const Surface &s)
{
	width = s.width;
	height = s.height;

	delete[] pPixels;

	pPixels = new Color[width * height];

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			pPixels[i * width + j] = s.pPixels[i * width + j];
		}
	}

	return *this;
}

Surface::~Surface()
{
	delete[] pPixels;
	pPixels = nullptr;
}

int Surface::GetWidth() const
{
	return width;
}

int Surface::GetHeight() const
{
	return height;
}

void Surface::ChangePixel(int x, int y, Color c)
{
	pPixels[y * width + x] = c;
}

void Surface::FillSurface(Color c)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			pPixels[i * height + j] = c;
		}
	}
}

Color Surface::GetPixel(int x, int y) const
{
	return pPixels[y * width + x];
}

Color Surface::GetChroma() const
{
	return chroma;
}
