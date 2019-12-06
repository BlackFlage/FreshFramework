#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	snake({1, 5}, Colors::Blue)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	frameCounter++;

	if (wnd.kbd.KeyIsPressed('A'))
	{
		input = 'A';
	}
	else if (wnd.kbd.KeyIsPressed('D'))
	{
		input = 'D';
	}
	else if (wnd.kbd.KeyIsPressed('W'))
	{
		input = 'W';
	}
	else if (wnd.kbd.KeyIsPressed('S'))
	{
		input = 'S';
	}

	while (frameCounter >= step)
	{
		snake.GetInput(input);
		snake.Update();

		frameCounter -= step;
	}
}

void Game::ComposeFrame()
{
	Vector2 xd = { 300, 260 };
	grid.Draw(snake, gfx);
}
