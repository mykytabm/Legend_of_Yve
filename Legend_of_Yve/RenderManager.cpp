#include "RenderManager.h"
#include "SpriteComponent.h"
#include "ServiceLocator.h"
#include <iostream>
#include "Game.h"


bool RenderManager::ComponentExists(SpriteComponent* t_drawable) const
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

void RenderManager::Register(SpriteComponent* t_drawable)
{
	if (!ComponentExists(t_drawable))
	{
		_renderComponents.push_back(t_drawable);
	}
}

void RenderManager::UnRegister(SpriteComponent* t_drawable)
{
	for (int i = 0; i < _renderComponents.size(); ++i)
	{
		if (_renderComponents[i] == t_drawable)
		{
			_renderComponents.erase(_renderComponents.begin() + i);
			break;
		}
	}
}

RenderManager::RenderManager(sf::RenderWindow* t_window)
	:_renderComponents(std::vector<SpriteComponent*>(0)), _gameWindowRef(t_window)
{
}

RenderManager::RenderManager() : _gameWindowRef(nullptr), _renderComponents(std::vector<SpriteComponent*>(0))
{
}

RenderManager::~RenderManager()
{
}

void RenderManager::Window(sf::RenderWindow* window)
{
	_gameWindowRef = window;
}

void RenderManager::render()
{
	_gameWindowRef->clear();

	for (int i = 0; i < _renderComponents.size(); ++i)
	{
		_renderComponents[i]->render(*_gameWindowRef);
	}

	_gameWindowRef->display();
}

void RenderManager::initialize()
{

}
