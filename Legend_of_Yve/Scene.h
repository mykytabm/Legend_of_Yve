#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <iostream>
#include "ServiceLocator.h"

class GameLoop;
class RenderManager;

class Scene
{

protected:
	std::vector<GameObject*> _gameObjects;
	std::vector<GameObject*> _inactiveGameObjects;
	std::string _id;
public:
	virtual void Initialize() { std::cout << "Initializing " << _id << std::endl; SetupGameObjects(); };
	virtual void SetupGameObjects() = 0;

	Scene() { };
	virtual ~Scene() { };
	Scene(std::string t_id) { _id = t_id; };
	virtual void Start() { for (int i = 0; i < _gameObjects.size(); ++i) { _gameObjects[i]->Start(); _gameObjects[i]->StartComponents(); } };
	std::string Name() { return _id; };
	std::vector<GameObject*> const GameObjects() { return _gameObjects; };
	std::vector<GameObject*> const InactiveGameObjects() { return _inactiveGameObjects; };

	void AddGameObject(GameObject* t_GameObject)
	{
		std::cout << t_GameObject->Name() << " has been added to Scene " << this->_id << std::endl;
		_gameObjects.push_back(t_GameObject);
	}

	void RegisterGameObjects(RenderManager* t_renderManager, GameLoop* t_gameLoop)
	{
		for (auto go : _gameObjects)
		{
			go->Register(*t_gameLoop, *t_renderManager);
		}
	}
	void DeRegisterGameObjects(RenderManager* t_renderManager, GameLoop* t_gameLoop)
	{
		for (auto go : _gameObjects)
		{
			go->DeRegister(*t_gameLoop, *t_renderManager);
		}
	}

};

