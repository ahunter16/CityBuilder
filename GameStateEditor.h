#pragma once
#ifndef GAMESTATEEDITOR_H
#define GAMESTATEEDITOR_H

#include <SFML/Graphics.hpp>

#include "GameState.h"

class GameStateEditor : public GameState
{
private:
	sf::View gameView;
	sf::View guiView;

public:
	virtual void Draw(const float dt);
	virtual void Update(const float dt);
	virtual void HandleInput();

	GameStateEditor(Game* game);
};
#endif // !GAMESTATEEDITOR_H