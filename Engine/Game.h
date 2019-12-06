#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Grid.h"
#include "Vector2.h"
#include "Snake.h"

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
	int step = 25;
	char input = 'W';
	int counter = 0;
	int steppy = 10;
	Snake snake;
	/********************************/
};