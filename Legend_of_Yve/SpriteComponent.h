#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>

class SpriteComponent : public Component
{
private:
	sf::Sprite* m_sprite;

public:
	SpriteComponent();
	~SpriteComponent();
	void SetSprite(sf::Sprite t_sprite) { *m_sprite = t_sprite; };
	sf::Sprite* Sprite() { return m_sprite; };
	void render(sf::RenderWindow& t_window);
	void update() override;
	void Register(GameLoop* t_gameLoop, RenderManager* t_renderManager) override;
};

