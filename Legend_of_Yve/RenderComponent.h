#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"
class RenderComponent :
	public Component
{
public:
	virtual void render(sf::RenderWindow& t_window) const {};
	void Register(GameLoop& t_gameLoop, RenderManager& t_renderManager) override;
	void DeRegister(GameLoop& t_gameLoop, RenderManager& t_renderManager) override;


};

