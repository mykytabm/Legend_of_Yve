#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Scene
{
private:
	std::string m_id;
	std::vector<GameObject*> m_gameObjects;
public:
	Scene(std::string t_id);
	~Scene();
	void update();
	void render(sf::RenderWindow& t_window);
	void AddGameObject(GameObject* t_GameObject);
};

