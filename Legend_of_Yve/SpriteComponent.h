#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>
#include <iostream>
class SpriteComponent : public Component
{
private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;

public:
	void SetSprite(std::string t_imagePath) { m_texture.loadFromFile(t_imagePath); m_sprite.setTexture(m_texture); };
	sf::Sprite& Sprite() { return m_sprite; };

	SpriteComponent();
	~SpriteComponent();

	void render(sf::RenderWindow& t_window) const;
	void Register(GameLoop& t_gameLoop, RenderManager& t_renderManager) override;
};

