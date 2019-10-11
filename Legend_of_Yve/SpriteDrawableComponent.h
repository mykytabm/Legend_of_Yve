#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>

class SpriteDrawableComponent : public Component
{
private:
	sf::RectangleShape m_rectangle;

public:
	SpriteDrawableComponent();
	~SpriteDrawableComponent();
	void render(sf::RenderWindow& t_window);
	void update() override;
	void Register() override;
};

