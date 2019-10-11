#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>

class ImageComponent : public Component
{
private:

public:
	void render(sf::Window& t_window);
	void update() override;
	void Register() override;
};

