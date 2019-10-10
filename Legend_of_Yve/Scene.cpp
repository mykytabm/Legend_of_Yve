#include "Scene.h"
#include <iostream>

Scene::Scene(std::string t_id)
{
	m_id = t_id;
}

Scene::~Scene()
{
}

void Scene::AddGameObject(GameObject* t_GameObject)
{
	std::cout << t_GameObject->Name() << " has been added to Scene " << this->m_id << std::endl;
	m_gameObjects.push_back(t_GameObject);
}

void Scene::update()
{
	
}

void Scene::render(sf::RenderWindow& t_window)
{
}
