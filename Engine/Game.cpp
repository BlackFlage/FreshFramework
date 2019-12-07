#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
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
	counter++;
	if (wnd.kbd.KeyIsPressed('W'))
	{
		input = 'W';
	}
	else if (wnd.kbd.KeyIsPressed('S'))
	{
		input = 'S';
	}
	else if (wnd.kbd.KeyIsPressed('A'))
	{
		input = 'A';
	}
	else if (wnd.kbd.KeyIsPressed('D'))
	{
		input = 'D';
	}
	if (counter >= step)
	{
		grid.Update(input);
		counter = 0;
	}
}

void Game::ComposeFrame()
{
	grid.Draw(gfx);
}
