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
	vec1 + vec2;
	vec1 - vec2;
	vec1 * vec2;
	vec1 / vec2;
	vec1 += vec2;
	vec1 -= vec2;
	vec1 *= vec2;
	vec1 /= vec2;
	vec1 == vec2;
	vec1 != vec2;
	vec1 = vec2;
}

void Game::ComposeFrame()
{
	grid.Draw(gfx);
}
