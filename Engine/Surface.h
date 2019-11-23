#pragma once
#include <string>
#include <fstream>
#include <Windows.h>
#include "Colors.h"

class Surface
{
public:
	Surface() = delete;
	Surface( int width, int height );
	Surface(std::string filePath);
	Surface( std::string filePath, Color chroma );
	Surface( Surface& s );
	Surface& operator=( const Surface&s );
	~Surface();
	int GetWidth() const;
	int GetHeight() const;
	void ChangePixel(int x, int y, Color c);
	void FillSurface(Color c);
	Color GetPixel( int x, int y ) const;
	Color GetChroma() const;
private:
	int width;
	int height;
	Color chroma;
	Color* pPixels = nullptr;
};