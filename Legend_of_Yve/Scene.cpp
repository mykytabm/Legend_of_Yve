#include "Scene.h"

GameObject* Scene::GetGameObject(std::string t_name)
{
	for (auto* object : _gameObjects)
	{
		if (object->GetName() == t_name) return object;
	}
}

void Scene::AddGameObject(GameObject* t_GameObject)
{
	std::cout << t_GameObject->GetName() << " has been added to Scene " << this->_id << std::endl;
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
