#include <SFML/Graphics.hpp>

#include "GameStateStart.h"
#include "GameStateEditor.h"
#include "GameState.h"

void GameStateStart::Draw(const float dt)
{
	this->game->window.setView(this->view);

	this->game->window.clear(sf::Color::Black);
	this->game->window.draw(this->game->background);

	return;
}

void GameStateStart::Update(const float dt)
{

}

void GameStateStart::HandleInput()
{
	sf::Event event;

	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
			//close the window
		case sf::Event::Closed:
			{
				game->window.close();
				break;
			}

			//Resize the Window
			case sf::Event::Resized:
			{
				this->view.setSize(event.size.width, event.size.height);
				
				this->game->background.setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, 0)));
				this->game->background.setScale(
					float(event.size.width) /
					float(this->game->background.getTexture()->getSize().x),
					float(event.size.height) /
					float(this->game->background.getTexture()->getSize().y));
				break;
			}

			case sf::Event::KeyPressed:
			{
				if (event.key.code == sf::Keyboard::Escape) { this->game->window.close(); }
				break;
			}
			default: break;
		}
	}
	return;
}