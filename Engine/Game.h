#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Grid.h"
#include "Vector2.h"
#include "Timer.h"

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
	Timer t;
	Grid grid;
	char input = 'W';
	float timePassed = 0.0f;
	float step = 0.3f;
	/********************************/
	/*  User Variables              */
	/********************************/
};