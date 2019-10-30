#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>
#include <iostream>
class SpriteComponent : public Component
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;

public:
	void SetSprite(std::string t_imagePath) { _texture.loadFromFile(t_imagePath); _sprite.setTexture(_texture); };
	sf::Sprite& Sprite() { return _sprite; };

	SpriteComponent();
	~SpriteComponent();

	void render(sf::RenderWindow& t_window) const;
	void Register(GameLoop& t_gameLoop, RenderManager& t_renderManager) override;
};

