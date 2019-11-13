#pragma once
#include "Component.h"
#include <SFML/System.hpp>
class Collider :
	public Component
{

private:
	sf::Vector2f _size;
	sf::Vector2f _position;

public:
	~Collider();

	sf::Vector2f Size() const;
	sf::Vector2f Position() const;

	void SetSize(const sf::Vector2f t_size);
	void SetPosition(const sf::Vector2f t_position);
	void SetPosition(sf::Vector2f* t_position);
	void Start() override;
	void Update() override;




};

