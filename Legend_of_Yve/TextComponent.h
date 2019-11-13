#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"
#include "RenderComponent.h"

class TextComponent :
	public RenderComponent
{
private:
	sf::Text _text;
	sf::Font _font;
public:
	TextComponent();
	~TextComponent();

	void Font(const std::string file);
	sf::Text& Text();
	void Start() override;
	void Update() override;
	void Render(sf::RenderWindow& t_window) const override;

};

