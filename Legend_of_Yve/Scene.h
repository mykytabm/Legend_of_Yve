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
	std::string _id;
public:
	Scene() { };
	virtual ~Scene() { };
	Scene(std::string t_id) { _id = t_id; };

	virtual void Initialize() { std::cout << "Initializing " << _id << std::endl; SetupGameObjects(); };
	virtual void SetupGameObjects() = 0;
	virtual void Start() { for (int i = 0; i < _gameObjects.size(); ++i) { _gameObjects[i]->Start(); _gameObjects[i]->StartComponents(); } };

	std::string Name() { return _id; };
	GameObject* GetGameObject(std::string t_name);
	std::vector<GameObject*> GameObjects() { return _gameObjects; };
	void AddGameObject(GameObject* t_GameObject);
	void RegisterGameObjects(RenderManager* t_renderManager, GameLoop* t_gameLoop);
	void DeRegisterGameObjects(RenderManager* t_renderManager, GameLoop* t_gameLoop);



};

