#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"
class RenderComponent :
	public Component
{
	virtual void render(sf::RenderWindow& t_window) const;
};

