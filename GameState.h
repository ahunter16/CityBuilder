#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Game.h"

class GameState
{
public:
	Game* game;

	virtual void Draw(const float dt) = 0;
	virtual void Update(const float dt) = 0;
	virtual void HandleInput() = 0;
};
#endif // !GAMESTATE_H