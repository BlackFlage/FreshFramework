#pragma once

#include "Keyboard.h"
#include "Graphics.h"
#include "Vector2.h"
#include "Surface.h"
#include "Mouse.h"
#include "Snake.h"
#include "Grid.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	Grid grid;
	/********************************/
	/*  User Variables              */
	int frameCounter = 0;
	int step = 30;
	int scoreStep = 3;
	char input = 'W';
	Surface gameOver = Surface("GameOver.bmp", Colors::Magenta);
	/********************************/
};