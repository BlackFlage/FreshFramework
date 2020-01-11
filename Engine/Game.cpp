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
	timePassed += t.GetDeltaTime();
	
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

	while (timePassed >= step)
	{
		grid.Update(input);
		timePassed -= step;
	}
}

void Game::ComposeFrame()
{
	grid.Draw(gfx);
}
