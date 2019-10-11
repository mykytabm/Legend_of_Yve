#include "RenderManager.h"
#include "SpriteDrawableComponent.h"
#include "ServiceLocator.h"
#include <iostream>
#include "Game.h"
RenderManager::RenderManager(sf::RenderWindow* t_window)
	:m_renderComponents(std::vector<SpriteDrawableComponent*>(0)), m_gameWindowRef(t_window)
{
}

RenderManager::RenderManager() : m_gameWindowRef(nullptr), m_renderComponents(std::vector<SpriteDrawableComponent*>(0))
{
}

void RenderManager::Window(sf::RenderWindow* window)
{
	m_gameWindowRef = window;
}

void RenderManager::render()
{
	m_gameWindowRef->clear();

	for (int i = 0; i < m_renderComponents.size(); ++i)
	{
		m_renderComponents[i]->render(*m_gameWindowRef);
	}

	m_gameWindowRef->display();
}

void RenderManager::initialize()
{

}
