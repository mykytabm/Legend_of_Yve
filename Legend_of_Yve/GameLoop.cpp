#include "GameLoop.h"
#include "ServiceLocator.h"
#include "RenderManager.h"
#include "Component.h"
#include "Game.h"

void GameLoop::update()
{
	std::cout << "UPDATE running" << std::endl;
	for (int i = 0; i < m_components->size(); ++i)
	{
		m_components->at(i).update();
	}
}

GameLoop::GameLoop() :m_components(nullptr), m_renderManager(nullptr), m_game(nullptr)
{
}

GameLoop::~GameLoop()
{
}

void GameLoop::run(bool& t_gameRunning)
{
	while (t_gameRunning)
	{
		update();
		//m_renderManager->render();
		//m_game->ProcessEvents();
	}

}

void GameLoop::initialize()
{
	//m_renderManager = ServiceLocator::instance()->GetService<RenderManager>();
	//m_game = ServiceLocator::instance()->GetService<Game>();
}



