#include "SpriteComponent.h"
#include "RenderManager.h"
#include "ServiceLocator.h"
#include "GameObject.h"

void SpriteComponent::Sprite(std::string t_imagePath)
{
	_texture.loadFromFile(t_imagePath);
	_sprite.setTexture(_texture);
}

sf::Sprite& SpriteComponent::Sprite()
{
	return _sprite;
}
sf::Vector2f SpriteComponent::Position() const
{
	return _sprite.getPosition();
}


void SpriteComponent::Start()
{
}

void SpriteComponent::Update()
{

}

void SpriteComponent::SetPosition(const sf::Vector2f t_newPosition)
{
	_sprite.setPosition(t_newPosition);
}

void SpriteComponent::SetPosition(sf::Vector2f* t_newPosition)
{
	_sprite.setPosition(*t_newPosition);
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
