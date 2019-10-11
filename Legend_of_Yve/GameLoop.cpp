#include "GameLoop.h"
#include "ServiceLocator.h"
#include "Component.h"
#include "Game.h"
#include "RenderManager.h"

void GameLoop::update()
{
	std::cout << "UPDATE running" << std::endl;
	for (int i = 0; i < m_components->size(); ++i)
	{
		m_components->at(i).update();
	}
}

GameLoop::GameLoop() :m_components(new std::vector<Component>(0)), m_game(nullptr)
{
}

GameLoop::~GameLoop()
{
}

void GameLoop::run(bool& t_gameRunning)
{
	while (t_gameRunning)
	{
		m_game->ProcessEvents();
		this->update();
		m_renderManager->render();
	}

}

void GameLoop::initialize()
{
	m_renderManager = ServiceLocator::instance()->GetService<RenderManager>();
	m_game = ServiceLocator::instance()->GetService<Game>();
}



