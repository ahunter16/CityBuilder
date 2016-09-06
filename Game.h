
#ifndef GAME_H
#define GAME_H

#include <stack>
#include <SFML/Graphics.hpp>

class GameState;

class Game {
public:
	std::stack<GameState*> states;
	sf::RenderWindow window;

	void PushState(GameState* state);
	void PopState();
	void ChangeState(GameState* state);
	GameState* PeekState();

	void GameLoop();

	Game();
	~Game();
};
#endif /*GAME_H*/