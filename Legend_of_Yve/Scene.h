#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <iostream>



class Scene
{

protected:
	std::vector<GameObject*> _gameObjects;
	std::vector<GameObject*> _inactiveGameObjects;
	std::string _id;
public:
	virtual void initialize() = 0;
	virtual void update() = 0;
	virtual void render(sf::RenderWindow& t_window) = 0;
	virtual void Start() { for (int i = 0; i < _gameObjects.size(); ++i) { _gameObjects[i]->Start(); _gameObjects[i]->StartComponents(); } };

	std::vector<GameObject*> const GameObjects() { return _gameObjects; };
	std::vector<GameObject*> const InactiveGameObjects() { return _inactiveGameObjects; };
	void AddGameObject(GameObject* t_GameObject)
	{
		std::cout << t_GameObject->Name() << " has been added to Scene " << this->_id << std::endl;
		_gameObjects.push_back(t_GameObject);
	}
	void RemoveGameObject(GameObject* t_gameObject)
	{
	}

};

