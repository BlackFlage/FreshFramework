#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Grid.h"
#include "Vector2.h"

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
	Vector2 vec1 = {100, 200};
	Vector2 vec2 = Vector2(300, 400);
	/********************************/
	/*  User Variables              */
	/********************************/
};