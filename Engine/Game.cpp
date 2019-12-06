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
	if (!grid.GameOver())
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
			grid.Update(input);

			frameCounter -= step;
		}
	}
}

void Game::ComposeFrame()
{
	if (!grid.GameOver())
	{
		grid.Draw(gfx);
	}
	else
	{
		gfx.DrawSpriteChroma(130, 150, gameOver, Colors::Magenta);
	}
}
