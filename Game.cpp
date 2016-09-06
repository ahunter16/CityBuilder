
#include "stdafx.h"
#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Game.h"
#include "GameState.h"
#include "TextureManager.h"

void Game::LoadTextures()
{
	textureManager.LoadTexture("background", "media/background.png");
}

void Game::PushState(GameState* state)
{
	this->states.push(state);
	return;
}

void Game::PopState()
{
	delete this->states.top();
	this->states.pop();

	return;
}

void Game::ChangeState(GameState* state)
{
	if (!this->states.empty())
	{
		PopState();
	}
	PushState(state);

	return;
}

GameState* Game::PeekState() 
{
	if (this->states.empty()) { return nullptr; }
	return this->states.top();
}

void Game::GameLoop() 
{
	sf::Clock clock;

	while (this->window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		if (PeekState() == nullptr) { continue; }
		PeekState()->HandleInput();
		PeekState()->Update(dt);
		this->window.clear(sf::Color::Black);
		PeekState()->Draw(dt);
		this->window.display();
	}
}

Game::Game()
{
	this->LoadTextures();

	this->window.create(sf::VideoMode(800, 600), "City Builder");
	this->window.setFramerateLimit(60);

	this->background.setTexture(this->textureManager.getRef("background"));
}

Game::~Game()
{
	while (!this->states.empty()) { PopState(); }
}