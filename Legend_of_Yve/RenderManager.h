#pragma once
#include "Service.h"
#include <SFML/Graphics.hpp>
#include <vector>
class ImageComponent;

class RenderManager : public Service
{
private:
	sf::RenderWindow* m_gameWindow;
	std::vector<ImageComponent>* m_renderComponents;
public:
	sf::RenderWindow* GameWindow() const { return m_gameWindow; };
	RenderManager();
	void render();
	virtual void initialize() override;
};

