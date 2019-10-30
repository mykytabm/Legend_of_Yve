#include "Button.h"
#include "Collider.h"
#include "ServiceLocator.h"
#include "Game.h"
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
	_collider.SetSize((sf::Vector2f)_spriteComponent.Sprite().getTexture()->getSize());
	std::cout << _collider.size().x << " " << _collider.size().y << std::endl;
}

void Button::Update()
{
	sf::Vector2i  windowSize = ServiceLocator::instance()->GetService<Game>()->Window().getPosition();

	int x = sf::Mouse::getPosition().x - windowSize.x;
	int y = sf::Mouse::getPosition().y - windowSize.y;

	bool xCheck = x > _collider.position().x&& x < _collider.position().x + _collider.size().x;
	bool yCheck = y > _collider.position().y&& y < _collider.position().y + _collider.size().y;


	if (xCheck && yCheck && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		onClick();
	}
}
