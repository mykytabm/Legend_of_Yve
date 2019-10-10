#pragma once
#include "Service.h"
#include <SFML/Graphics.hpp>
#include <vector>
class ImageComponent;

class RenderManager : public Service
{
private:
	std::vector<ImageComponent>* m_renderComponents;
public:
	RenderManager();
	void render(sf::Window& t_window);
	virtual void initialize() override;
};

