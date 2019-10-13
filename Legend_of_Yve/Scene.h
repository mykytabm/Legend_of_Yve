#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <iostream>

class Scene
{

protected:
	std::vector<GameObject*> m_gameObjects;
	std::vector<GameObject*> m_inactiveGameObjects;
	std::string m_id;
public:

	virtual void initialize() = 0;
	virtual void update() = 0;
	virtual void render(sf::RenderWindow& t_window) = 0;
	virtual void Start() { for (int i = 0; i < m_gameObjects.size(); ++i)m_gameObjects[i]->Start(); };

	std::vector<GameObject*> const GameObjects() { return m_gameObjects; };
	std::vector<GameObject*> const InactiveGameObjects() { return m_inactiveGameObjects; };
	void AddGameObject(GameObject* t_GameObject)
	{
		std::cout << t_GameObject->Name() << " has been added to Scene " << this->m_id << std::endl;
		m_gameObjects.push_back(t_GameObject);
	}
	void RemoveGameObject(GameObject* t_gameObject)
	{
	}

};

