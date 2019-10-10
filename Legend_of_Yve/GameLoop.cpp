#include "GameLoop.h"
#include "ServiceLocator.h"
#include "RenderManager.h"
#include "Component.h"


void GameLoop::update()
{
	for (int i = 0; i < m_components->size(); ++i)
	{
		m_components->at(i).update();
	}
}

GameLoop::GameLoop() :m_components(nullptr), m_renderManager(nullptr)
{
}

GameLoop::~GameLoop()
{
}

void GameLoop::run(sf::Window& t_window)
{

	update();
	m_renderManager->render(t_window);
	//ProcessEvents();

}

void GameLoop::initialize()
{
	m_renderManager = ServiceLocator::instance()->GetService<RenderManager>();
}



