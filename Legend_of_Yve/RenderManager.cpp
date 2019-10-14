#include "RenderManager.h"
#include "SpriteComponent.h"
#include "ServiceLocator.h"
#include <iostream>
#include "Game.h"


bool RenderManager::ComponentExists(SpriteComponent* t_drawable) const
{
	for (int i = 0; i < m_renderComponents.size(); ++i)
	{
		if (m_renderComponents[i] == t_drawable)
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
		m_renderComponents.push_back(t_drawable);
	}
}

void RenderManager::UnRegister(SpriteComponent* t_drawable)
{
	for (int i = 0; i < m_renderComponents.size(); ++i)
	{
		if (m_renderComponents[i] == t_drawable)
		{
			m_renderComponents.erase(m_renderComponents.begin() + i);
			break;
		}
	}
}

RenderManager::RenderManager(sf::RenderWindow* t_window)
	:m_renderComponents(std::vector<SpriteComponent*>(0)), m_gameWindowRef(t_window)
{
}

RenderManager::RenderManager() : m_gameWindowRef(nullptr), m_renderComponents(std::vector<SpriteComponent*>(0))
{
}

RenderManager::~RenderManager()
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
