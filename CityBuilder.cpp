// CityBuilder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameStateStart.h"
#include "Game.h"



int main()
{
	Game game;

	game.PushState(new GameStateStart(&game));
	game.GameLoop();

	return 0;
}