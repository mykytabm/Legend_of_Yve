#include "GameLoop.h"
#include "ServiceLocator.h"
#include "Component.h"
#include "Game.h"
#include "RenderManager.h"

void GameLoop::update()
{
	for (int i = 0; i < _components.size(); ++i)
	{
		_components[i]->update();
	}
}

GameLoop::GameLoop()
{
}

GameLoop::~GameLoop()
{
}

void GameLoop::run(bool& t_gameRunning, Game& t_game, RenderManager& t_renderManager)
{
	while (t_game.GameRunning())
	{
		t_game.ProcessEvents();
		this->update();
		t_renderManager.render();
	}

}

void GameLoop::Register(Component* t_component)
{
	_components.push_back(t_component);
}

void GameLoop::initialize()
{

}



