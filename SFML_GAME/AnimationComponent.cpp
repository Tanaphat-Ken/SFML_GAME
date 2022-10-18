#include "AnimationComponent.h"

void AnimationComponent::Animation::play(const float& dt)
{
	//Update timer
	this->timer += 100.f * dt;
	if (this->timer >= this->animationTimer)
	{
		//reset timer
		this->timer = 0.f;

		//animate
		if (this->currentRect != this->endRect)
		{
			this->currentRect.left += this->width;
		}
		else //reset
		{
			this->currentRect.left = this->startRect.left;
		}

		this->sprite.setTextureRect(this->currentRect);
	}
}

void AnimationComponent::Animation::reset()
{
	this->timer = 0.f;
	this->currentRect = this->startRect;
}

AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet)
	:sprite(sprite), textureSheet(texture_sheet), lastAnimation(NULL)
{

}

AnimationComponent::~AnimationComponent()
{
	for (auto &i : this->animations)
	{
		delete i.second;
	}
}

//Functions
void AnimationComponent::addAnimation(const std::string key, 
	float animation_timer,int start_frame_x, int start_frame_y, int frames_x, int frames_y, int width, int height)
{
	this->animations[key] = new Animation(this->sprite, this->textureSheet, animation_timer, start_frame_x, start_frame_y,
		frames_x, frames_y, width, height);
}

void AnimationComponent::play(const std::string key, const float& dt)
{
	if (this->lastAnimation != this->animations[key])
	{
		if(this->lastAnimation == NULL)
			this->lastAnimation = this->animations[key];
		else
		{
			this->lastAnimation->reset();
			this->lastAnimation = this->animations[key];
		}
	}
	this->animations[key]->play(dt);
}

