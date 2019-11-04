#include "Button.h"
#include "Collider.h"
#include "ServiceLocator.h"
#include "Game.h"

bool Button::MouseClick(int button)
{
	bool value = false;
	sf::Mouse::Button btn;
	switch (button)
	{
	default:
		btn = sf::Mouse::Button::Left;
		break;
	case 0:
		btn = sf::Mouse::Button::Left;
		break;
	case 1:
		btn = sf::Mouse::Button::Middle;
		break;
	case 2:
		btn = sf::Mouse::Button::Right;
		break;
	}
	if (sf::Mouse::isButtonPressed(btn))
	{
		value = false;
		if (_pressed == false)
		{
			_pressed = true;
			value = true;
		}
	}
	else
	{
		_pressed = false;
	}
	return value;
}

Button::Button()
{
	this->_components.push_back(&_spriteComponent);
	this->_components.push_back(&_collider);
	this->_components.push_back(&_textComponent);
}

Button::~Button()
{
}

void Button::Start()
{
	_collider.SetSize((sf::Vector2f)_spriteComponent.Sprite().getTexture()->getSize());
	_spriteComponent.SetPosition(&_position);
	_collider.SetPosition(&_position);
	_textComponent.Text().setPosition(_position);
}

void Button::Update()
{


	int x = sf::Mouse::getPosition(ServiceLocator::Instance()->GetService<Game>()->Window()).x;
	int y = sf::Mouse::getPosition(ServiceLocator::Instance()->GetService<Game>()->Window()).y;
	bool xCheck = (x >= _collider.Position().x) && (x < _collider.Position().x + _collider.Size().x);
	bool yCheck = (y > _collider.Position().y) && (y < _collider.Position().y + _collider.Size().y);


	if (MouseClick(0) && xCheck && yCheck)
	{
		onClick();
	}
}
