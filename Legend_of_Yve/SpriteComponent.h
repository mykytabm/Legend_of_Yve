#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "RenderComponent.h"
class SpriteComponent : public RenderComponent
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	bool _CenterAllignment = true;

public:
	SpriteComponent();
	~SpriteComponent();

	sf::Sprite& Sprite();
	sf::Vector2f Position() const;

	void Sprite(std::string t_imagePath);
	void Start() override;
	void Update() override;
	void SetPosition(const sf::Vector2f t_newPosition);
	void SetPosition(sf::Vector2f* t_newPosition);
	void Render(sf::RenderWindow& t_window) const override;
};

