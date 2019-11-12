#include "TextComponent.h"
#include <iostream>;




TextComponent::TextComponent()
{
	_text.setFont(_font);
}

TextComponent::~TextComponent()
{ }

void TextComponent::Font(std::string file)
{
	_font.loadFromFile(file);
}

void TextComponent::Start()
{ }

void TextComponent::Update()
{ }


void TextComponent::Render(sf::RenderWindow& t_window) const
{
	t_window.draw(_text);
}
