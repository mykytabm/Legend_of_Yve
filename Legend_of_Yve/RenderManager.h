#pragma once
#include "Service.h"
#include <SFML/Graphics.hpp>
#include <vector>
class SpriteComponent;

class RenderManager : public Service
{
private:
	sf::RenderWindow* _gameWindowRef;
	std::vector<SpriteComponent*> _renderComponents;
public:
	bool ComponentExists(SpriteComponent* t_drawable) const;
	void Register(SpriteComponent* t_drawable);
	void UnRegister(SpriteComponent* t_drawable);
	RenderManager(sf::RenderWindow* t_window);
	RenderManager();
	~RenderManager();
	void Window(sf::RenderWindow* window);
	void render();
	virtual void initialize() override;
};

