#include "RenderManager.h"
#include "ImageComponent.h"
#include <iostream>


RenderManager::RenderManager(sf::RenderWindow* t_window)
	:m_renderComponents(new std::vector<ImageComponent>(0)), m_gameWindowRef(t_window)
{
}

RenderManager::RenderManager() : m_gameWindowRef(nullptr), m_renderComponents(new std::vector<ImageComponent>(0))
{
}

void RenderManager::Window(sf::RenderWindow& window)
{
	m_gameWindowRef = &window;
}

void RenderManager::render()
{
	std::cout << "RENDER running" << std::endl;

	//m_gameWindowRef->clear();

	//for (int i = 0; i < m_renderComponents->size(); ++i)
	//{
	//	m_renderComponents->at(i).render(*m_gameWindowRef);
	//}

	//m_gameWindowRef->display();
}

void RenderManager::initialize()
{
}
