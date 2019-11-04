#include "SpriteComponent.h"
#include "RenderManager.h"
#include "ServiceLocator.h"

SpriteComponent::SpriteComponent()
{

}
SpriteComponent::~SpriteComponent()
{

}
void SpriteComponent::Render(sf::RenderWindow& t_window) const
{
	t_window.draw(_sprite);
}
