#include "SpriteComponent.h"
#include "RenderManager.h"
#include "ServiceLocator.h"
#include "GameObject.h"

void SpriteComponent::Start()
{
}

void SpriteComponent::Update()
{

}

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
