#include "RenderManager.h"
#include "RenderComponent.h"
#include "ServiceLocator.h"
#include <iostream>
#include "Game.h"


bool RenderManager::ComponentExists(RenderComponent* t_drawable) const
{
	for (int i = 0; i < _renderComponents.size(); ++i)
	{
		if (_renderComponents[i] == t_drawable)
		{
			return true;
		}
	}
	return false;
}

void RenderManager::Register(RenderComponent* t_drawable)
{
	if (!ComponentExists(t_drawable))
	{
		_renderComponents.push_back(t_drawable);
	}
}

void RenderManager::DeRegister(RenderComponent* t_drawable)
{
	_renderComponents.erase(std::remove(_renderComponents.begin(), _renderComponents.end(), t_drawable), _renderComponents.end());
}

RenderManager::RenderManager(sf::RenderWindow* t_window)
	:_renderComponents(std::vector<RenderComponent*>(0)), _gameWindowRef(t_window)
{
}

RenderManager::RenderManager() : _gameWindowRef(nullptr), _renderComponents(std::vector<RenderComponent*>(0))
{
}

RenderManager::~RenderManager()
{
}

void RenderManager::Window(sf::RenderWindow* window)
{
	_gameWindowRef = window;
}

void RenderManager::Render()
{
	_gameWindowRef->clear();

	for (int i = 0; i < _renderComponents.size(); ++i)
	{
		if (_renderComponents[i]->Active())
			_renderComponents[i]->Render(*_gameWindowRef);
	}

	_gameWindowRef->display();
}

void RenderManager::Initialize()
{

}
