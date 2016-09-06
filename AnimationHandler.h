#pragma once
#ifndef ANIMATIONHANDLER_H
#define ANIMATIONHANDLER_H

#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
public:
	unsigned int startFrame;
	unsigned int endFrame;

	float duration;

	Animation(unsigned int startFrame, unsigned int endFrame, float duration)
	{
		this->startFrame = startFrame;
		this->endFrame = endFrame;
		this->duration = duration;
	}
	unsigned int GetLength() { return endFrame - startFrame + 1; }
};

class AnimationHandler
{
private:

	//Array of animations
	std::vector<Animation> animations;

	//Current time since animation loop started
	float t;

	int currentAnim;

public:

	//Add a new animation
	void AddAnim(Animation& anim);

	//Update current frame of animation. dt = time since update
	//last called (i.e. frame execution time)
	void Update(const float dt);

	//change the animation, & reset t
	void ChangeAnim(unsigned int animNum);

	//Current section of texture to display
	sf::IntRect bounds;

	//Pixel dimensions of each individual frame
	sf::IntRect frameSize;

	//constructor
	AnimationHandler()
	{
		this->t = 0.0f;
		this->currentAnim = -1;
	}
	AnimationHandler(const sf::IntRect& frameSize)
	{
		this->frameSize = frameSize;

		this->t = 0.0f;
		this->currentAnim = -1;
	}
};
#endif // !ANIMATIONHANDLER_H