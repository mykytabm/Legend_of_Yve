#include "TextComponent.h"
#include <iostream>;
void TextComponent::Start()
{
}
void TextComponent::Update()
{

}


void TextComponent::Render(sf::RenderWindow& t_window) const
{
	t_window.draw(_text);
}
