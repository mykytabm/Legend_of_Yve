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
	Scene(std::string t_id);
	virtual ~Scene() { };

	std::string Name() { return _id; };
	GameObject* GetGameObject(std::string t_name);
	std::vector<GameObject*> GameObjects();

	void AddGameObject(GameObject* t_GameObject);
	void RegisterGameObjects(RenderManager* t_renderManager, GameLoop* t_gameLoop);
	void DeRegisterGameObjects(RenderManager* t_renderManager, GameLoop* t_gameLoop);

	virtual void Initialize();
	virtual void Start();
	virtual void SetupGameObjects() = 0;
};

