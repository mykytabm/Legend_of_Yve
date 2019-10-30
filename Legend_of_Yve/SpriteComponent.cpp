#include "SpriteComponent.h"
#include "RenderManager.h"
#include "ServiceLocator.h"

SpriteComponent::SpriteComponent()
{

}
SpriteComponent::~SpriteComponent()
{

}
void SpriteComponent::render(sf::RenderWindow& t_window) const
{
	t_window.draw(_sprite);
}


void SpriteComponent::Register(GameLoop& t_gameLoop, RenderManager& t_renderManager)
{
	t_renderManager.Register(this);
	Component::Register(t_gameLoop, t_renderManager);
}


