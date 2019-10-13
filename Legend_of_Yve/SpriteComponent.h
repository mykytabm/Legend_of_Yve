#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>

class SpriteComponent : public Component
{
private:
	sf::RectangleShape m_rectangle;

public:
	SpriteComponent();
	~SpriteComponent();
	void render(sf::RenderWindow& t_window);
	void update() override;
	void Register(GameLoop* t_gameLoop, RenderManager* t_renderManager) override;
};

