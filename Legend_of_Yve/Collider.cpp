#include "Collider.h"



sf::Vector2f Collider::Size() const
{
	return _size;
}

void Collider::SetSize(const sf::Vector2f t_size)
{
	_size = t_size;
}

sf::Vector2f Collider::Position() const
{
	return _position;
}

void Collider::SetPosition(const sf::Vector2f t_position)
{
	_position = t_position;
}

void Collider::SetPosition(sf::Vector2f* t_position)
{
	_position = *t_position;
};

Collider::~Collider()
{
}

void Collider::Start()
{
}

void Collider::Update()
{
}
