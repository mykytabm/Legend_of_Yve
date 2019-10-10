#include "RenderManager.h"
#include "ImageComponent.h"
#include <iostream>


RenderManager::RenderManager() :m_renderComponents(nullptr)
{
}

void RenderManager::render(sf::Window& t_window)
{
	for (int i = 0; i < m_renderComponents->size(); ++i)
	{
		m_renderComponents->at(i).render(t_window);
	}
}

void RenderManager::initialize()
{
	std::cout << this->m_renderComponents << std::endl;
}
