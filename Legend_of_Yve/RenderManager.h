#pragma once
#include "Service.h"
#include <SFML/Graphics.hpp>
#include <vector>
class ImageComponent;

class RenderManager : public Service
{
private:
	sf::RenderWindow* m_gameWindowRef;
	std::vector<ImageComponent>* m_renderComponents;
public:
	RenderManager(sf::RenderWindow* t_window);
	RenderManager();
	void Window(sf::RenderWindow* window);
	void render();
	virtual void initialize() override;
};

