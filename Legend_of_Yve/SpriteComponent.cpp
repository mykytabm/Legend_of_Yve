#include "SpriteComponent.h"
#include "RenderManager.h"
#include "ServiceLocator.h"

SpriteComponent::SpriteComponent() : m_sprite(nullptr), m_texture(nullptr)
{
	m_sprite = new sf::Sprite();
	m_texture = new sf::Texture();
}
SpriteComponent::~SpriteComponent()
{

}
void SpriteComponent::render(sf::RenderWindow& t_window)
{
	t_window.draw(*m_sprite);
}


void SpriteComponent::Register(GameLoop* t_gameLoop, RenderManager* t_renderManager)
{
	t_renderManager->Register(this);
	Component::Register(t_gameLoop, t_renderManager);
}


