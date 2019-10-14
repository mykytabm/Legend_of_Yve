#include "GameLoop.h"
#include "ServiceLocator.h"
#include "Component.h"
#include "Game.h"
#include "RenderManager.h"

void GameLoop::update()
{
	for (int i = 0; i < m_components.size(); ++i)
	{
		m_components[i]->update();
	}
}

GameLoop::GameLoop()
{
}

GameLoop::~GameLoop()
{
}

 void GameLoop::run( bool& t_gameRunning)
{
	while (t_gameRunning)
	{
		m_game->ProcessEvents();
		this->update();
		m_renderManager->render();
	}

}

void GameLoop::Register(Component* t_component)
{
	m_components.push_back(t_component);
}

void GameLoop::initialize()
{
	m_renderManager = ServiceLocator::instance()->GetService<RenderManager>();
	m_game = ServiceLocator::instance()->GetService<Game>();
}



