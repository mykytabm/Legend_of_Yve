#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"
#include "RenderComponent.h"

class TextComponent :
	public RenderComponent
{
private:
	sf::Text _text;
public:
	void Start() override;
	void Update() override;

	void Render(sf::RenderWindow& t_window) const override;
};

