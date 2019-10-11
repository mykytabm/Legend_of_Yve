#include "SpriteDrawableComponent.h"
#include "RenderManager.h"
#include "ServiceLocator.h"
SpriteDrawableComponent::SpriteDrawableComponent()
{
	m_rectangle = sf::RectangleShape::RectangleShape(sf::Vector2f(100, 100));
}
SpriteDrawableComponent::~SpriteDrawableComponent()
{

}
void SpriteDrawableComponent::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_rectangle);
}

void SpriteDrawableComponent::update()
{
}

void SpriteDrawableComponent::Register()
{
	ServiceLocator::instance()->GetService<RenderManager>()->Register(this);
	Component::Register();
}


