#include "Button.h"
#include "Collider.h"
Button::Button()
{
	m_spriteComponent = SpriteComponent();
	m_collider = Collider();
	this->m_components.push_back(&m_spriteComponent);
	this->m_components.push_back(&m_collider);
}

Button::~Button()
{
}

void Button::Start()
{
}
