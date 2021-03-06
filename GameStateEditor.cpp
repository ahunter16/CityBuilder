#include "stdafx.h"

#include<SFML/Graphics.hpp>

#include "GameState.h"
#include "GameStateEditor.h"

void GameStateEditor::Draw(const float dt)
{
	this->game->window.clear(sf::Color::Black);
	this->game->window.draw(this->game->background);

	return;
}

void GameStateEditor::Update(const float dt)
{
	return;
}

void GameStateEditor::HandleInput()
{
	sf::Event event;

	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
		{
			this->game->window.close();
			break;
		}
		case sf::Event::Resized:
		{
			gameView.setSize(event.size.width, event.size.height);
			guiView.setSize(event.size.width, event.size.height);

			this->game->background.setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, 0), this->guiView));
			this->game->background.setScale(
				float(event.size.width) /
				float(this->game->background.getTexture()->getSize().x),
				float(event.size.height) /
				float(this->game->background.getTexture()->getSize().y));
			break;
		}
		default: break;

		}
	}
	return;
}

GameStateEditor::GameStateEditor(Game* game)
{
	this->game = game;
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->guiView.setSize(pos);
	this->gameView.setSize(pos);
	pos *= 0.5f;
	this->guiView.setCenter(pos);
	this->gameView.setCenter(pos);
}