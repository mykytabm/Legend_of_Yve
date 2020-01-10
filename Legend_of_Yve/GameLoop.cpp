#include "GameLoop.h"
#include "ServiceLocator.h"
#include "Component.h"
#include "Game.h"
#include "RenderManager.h"
#include "GameObject.h"
#include <algorithm>

void GameLoop::Update()
{

	for (auto gameObject : _gameObjects)
	{
		if (gameObject->Active())
		{
			gameObject->Update();
		}
	}

	for (auto component : _components)
	{
		if (component->Active())
		{
			component->Update();
		}
	}
}

GameLoop::GameLoop()
{
}

GameLoop::~GameLoop()
{
}

void GameLoop::Run(bool& t_gameRunning, Game& t_game, RenderManager& t_renderManager)
{
	while (t_game.GameRunning())
	{
		t_game.ProcessEvents();
		this->Update();
		t_renderManager.Render();
	}
}

void GameLoop::Register(Component* t_component)
{
	if (!Contains(t_component))
		_components.push_back(t_component);
}

void GameLoop::Register(GameObject* t_gameObject)
{
	if (!Contains(t_gameObject))
		_gameObjects.push_back(t_gameObject);
}

void GameLoop::DeRegister(GameObject* t_gameObject)
{
	if (Contains(t_gameObject))
		_gameObjects.erase(std::remove(_gameObjects.begin(), _gameObjects.end(), t_gameObject), _gameObjects.end());
}

void GameLoop::DeRegister(Component* t_component)
{
	if (Contains(t_component))
		_components.erase(std::remove(_components.begin(), _components.end(), t_component), _components.end());

}

bool GameLoop::Contains(GameObject* t_gameObject)
{
	if (std::find(_gameObjects.begin(), _gameObjects.end(), t_gameObject) != _gameObjects.end())
	{
		//contains
		return true;
	}
	else
	{
		//does not contain
		return false;
	}
}

bool GameLoop::Contains(Component* t_component)
{
	return false;
}

void GameLoop::Initialize()
{

}



