#pragma once
#ifndef GAMESTATESTART_H
#define GAMESTATESTART_H

#include<SFML/Graphics.hpp>

#include "GameState.h"

class GameStateStart : public GameState
{
private:
	sf::View view;
	void LoadGame();

public:
	virtual void Draw(const float dt);
	virtual void Update(const float dt);
	virtual void HandleInput();

	GameStateStart(Game* game);
};

#endif