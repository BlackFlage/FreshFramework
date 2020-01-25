#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	grid(step)
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
	if (!isOver)
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

		isOver = grid.IsOver();
	}
}

void Game::ComposeFrame()
{
	if (!isOver)
	{
		grid.Draw(gfx);
	}
}
