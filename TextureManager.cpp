#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

#include "TextureManager.h"

void TextureManager::LoadTexture(const std::string& name, const std::string& filename)
{
	//Load texture
	sf::Texture tex;
	tex.loadFromFile(filename);

	//Add to list of textures
	this->textures[name] = tex;

	return;
}

sf::Texture& TextureManager::getRef(const std::string& texture)
{
	return this->textures.at(texture);
}