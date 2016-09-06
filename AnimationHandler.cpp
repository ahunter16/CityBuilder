#include "stdafx.h"

#include <SFML/Graphics.hpp>
#include <vector>

#include "AnimationHandler.h"

void AnimationHandler::Update(const float dt)
{
	if (currentAnim >= this->animations.size() || currentAnim < 0) { return; }

	float duration = this->animations[currentAnim].duration;

	//Check if animation has changed to next frame,
	//if so, change to next frame
	if (int((t + dt) / duration) > int(t / duration))
	{
		//Calculate the frame number
		int frame = int((t + dt) / duration);

		//Adjust for looping
		frame %= this->animations[currentAnim].GetLength();

		//Set sprite to the new frame
		sf::IntRect rect = this->frameSize;
		rect.left = rect.width*frame;
		rect.top = rect.height * this->currentAnim;
		this->bounds = rect;
	}

	//Increment the time elapsed
	this->t += dt;
	//Adjust for looping
	if (this->t > duration * this->animations[currentAnim].GetLength())
	{
		this->t = 0.0f;
	}

	return;
}

void AnimationHandler::ChangeAnim(unsigned int animID)
{
	//Do not change the animation if it is currently active,
	//or the new animation does not exist
	if(this->currentAnim == animID || 
		animID >= this->animations.size() ||
		animID < 0) 
	{
		return;
	}

	//set the current animation
	this->currentAnim = animID;

	//Update the animation bounds
	sf::IntRect rect = this->frameSize;
	rect.top = rect.height * animID;
	this->bounds = rect;
	this->t = 0.0;
	return;
}