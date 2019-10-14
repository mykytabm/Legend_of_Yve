#include "Button.h"
#include "Collider.h"
Button::Button()
{
	this->m_components.push_back(new SpriteComponent());
	this->m_components.push_back(new Collider());
}

Button::~Button()
{
}

void Button::Start()
{
}
