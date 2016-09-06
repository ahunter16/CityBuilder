
#ifndef GAME_H
#define GAME_H

#include <stack>
#include <SFML/Graphics.hpp>

#include "TextureManager.h"

class GameState;

class Game {
private:
	void LoadTextures();
public:
	std::stack<GameState*> states;
	
	sf::RenderWindow window;
	TextureManager textureManager;
	sf::Sprite background;

	void PushState(GameState* state);
	void PopState();
	void ChangeState(GameState* state);
	GameState* PeekState();

	void GameLoop();

	Game();
	~Game();
};
#endif /*GAME_H*/