#pragma once
#include "Service.h"
#include <SFML/Graphics.hpp>
#include <vector>
class SpriteDrawableComponent;

class RenderManager : public Service
{
private:
	sf::RenderWindow* m_gameWindowRef;
	std::vector<SpriteDrawableComponent*> m_renderComponents;
public:
	void Register(SpriteDrawableComponent* t_drawable) { m_renderComponents.push_back(t_drawable); };
	void UnRegister(SpriteDrawableComponent* t_drawable) { };
	RenderManager(sf::RenderWindow* t_window);
	RenderManager();
	void Window(sf::RenderWindow* window);
	void render();
	virtual void initialize() override;
};

