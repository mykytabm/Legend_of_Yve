#include "Button.h"
#include "Collider.h"
Button::Button()
{
	_spriteComponent = SpriteComponent();
	_collider = Collider();
	this->_components.push_back(&_spriteComponent);
	this->_components.push_back(&_collider);
}

Button::~Button()
{
}

void Button::Start()
{
	_spriteComponent.SetPosition(&_position);
	_collider.SetPosition(&_position);
}

void Button::Update()
{
	
}
