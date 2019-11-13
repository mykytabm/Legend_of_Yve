#include "Scene.h"

Scene::Scene(std::string t_id)
{
	_id = t_id;
}

GameObject* Scene::GetGameObject(std::string t_name)
{
	for (auto* object : _gameObjects)
	{
		if (object->Name() == t_name) return object;
	}
}

std::vector<GameObject*> Scene::GameObjects()
{
	return _gameObjects;
}

void Scene::AddGameObject(GameObject* t_GameObject)
{
	std::cout << t_GameObject->Name() << " has been added to Scene " << this->_id << std::endl;
	_gameObjects.push_back(t_GameObject);
}

void Scene::RegisterGameObjects(RenderManager* t_renderManager, GameLoop* t_gameLoop)
{
	for (auto go : _gameObjects)
	{
		go->Register(*t_gameLoop, *t_renderManager);
	}
}

void Scene::DeRegisterGameObjects(RenderManager* t_renderManager, GameLoop* t_gameLoop)
{
	for (auto go : _gameObjects)
	{
		go->DeRegister(*t_gameLoop, *t_renderManager);
	}
}

void Scene::Initialize()
{
	std::cout << "Initializing " << _id << std::endl;
	SetupGameObjects();
}

void Scene::Start()
{
	for (int i = 0; i < _gameObjects.size(); ++i)
	{
		_gameObjects[i]->Start(); _gameObjects[i]->StartComponents();
	}
}
