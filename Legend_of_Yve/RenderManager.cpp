#include "RenderManager.h"
#include "ImageComponent.h"
#include <iostream>


RenderManager::RenderManager() :m_renderComponents(nullptr), m_gameWindow(nullptr)
{
}

void RenderManager::render()
{
	std::cout << "RENDER running" << std::endl;

	m_gameWindow->clear();

	for (int i = 0; i < m_renderComponents->size(); ++i)
	{
		m_renderComponents->at(i).render(*m_gameWindow);
	}

	m_gameWindow->display();
}

void RenderManager::initialize()
{
	m_gameWindow = new sf::RenderWindow(sf::VideoMode(1280, 720), "Legend Of Yve");
}
