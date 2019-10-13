#include "SpriteComponent.h"
#include "RenderManager.h"
#include "ServiceLocator.h"

SpriteComponent::SpriteComponent()
{
	m_rectangle = sf::RectangleShape::RectangleShape(sf::Vector2f(100, 100));
}
SpriteComponent::~SpriteComponent()
{

}
void SpriteComponent::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_rectangle);
}

void SpriteComponent::update()
{

}

void SpriteComponent::Register(GameLoop* t_gameLoop, RenderManager* t_renderManager)
{
	t_renderManager->Register(this);
	Component::Register(t_gameLoop, t_renderManager);
}


