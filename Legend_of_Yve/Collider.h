#pragma once
#include "Component.h"
#include <SFML/System.hpp>
class Collider :
	public Component
{

private:
	sf::Vector2f m_size;
	sf::Vector2f m_position;

public:

	sf::Vector2f size() const { return m_size; };
	void SetSize(sf::Vector2f t_size) { m_size = t_size; };
	sf::Vector2f position() const { return m_position; };
	void SetPosition(sf::Vector2f t_position) { m_position = t_position; };

	Collider() {};	
	~Collider();

	void Start() override;
	void update() override;




};

