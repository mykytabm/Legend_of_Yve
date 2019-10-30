#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"
class TextComponent :
	public Component

{
private:
	sf::Text _text;
public:
	void Start() override;
	void update() override;
};

