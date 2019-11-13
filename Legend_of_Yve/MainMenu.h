#pragma once
#include "Scene.h"
class MainMenu :
	public Scene
{
public:
	MainMenu(const std::string t_id);
	~MainMenu() { };

	virtual void Update();
	virtual void SetupGameObjects();

};

