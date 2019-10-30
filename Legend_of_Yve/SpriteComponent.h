#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>
#include <iostream>
class SpriteComponent : public Component
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	bool _CenterAllignment = true;

public:
	void SetSprite(std::string t_imagePath) { _texture.loadFromFile(t_imagePath); _sprite.setTexture(_texture); };
	sf::Sprite& Sprite() { return _sprite; };
	sf::Vector2f Position() const { return _sprite.getPosition(); };
	void SetPosition(sf::Vector2f t_newPosition) { _sprite.setPosition(t_newPosition); };
	void SetPosition(sf::Vector2f* t_newPosition) { _sprite.setPosition(*t_newPosition); };
	SpriteComponent();
	~SpriteComponent();

	void render(sf::RenderWindow& t_window) const;
	void Register(GameLoop& t_gameLoop, RenderManager& t_renderManager) override;
};

