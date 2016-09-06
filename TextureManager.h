#pragma once
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextureManager
{
private:
	//Array of textures used
	std::map<std::string, sf::Texture> textures;

public:

	//Add texture from file
	void LoadTexture(const std::string& name, const std::string& filename);

	//Translate an id into a reference
	sf::Texture& getRef(const std::string& texture);

	//Constructor
	TextureManager()
	{

	}
};


#endif // !TEXTUREMANAGER_H