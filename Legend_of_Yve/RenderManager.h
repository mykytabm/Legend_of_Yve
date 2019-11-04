#pragma once
#include "Service.h"
#include <SFML/Graphics.hpp>
#include <vector>
class RenderComponent;

class RenderManager : public Service
{
private:
	sf::RenderWindow* _gameWindowRef;
	std::vector<RenderComponent*> _renderComponents;
public:
	bool ComponentExists(RenderComponent* t_drawable) const;
	void Register(RenderComponent* t_drawable);
	void DeRegister(RenderComponent* t_drawable);
	RenderManager(sf::RenderWindow* t_window);
	RenderManager();
	~RenderManager();
	void Window(sf::RenderWindow* window);
	void Render();
	virtual void Initialize() override;
};

