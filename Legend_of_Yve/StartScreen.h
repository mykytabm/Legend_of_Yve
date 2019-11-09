#pragma once
#include "Scene.h"
#include <string>

class StartScreen :public Scene
{
public:
	StartScreen(const std::string t_id) { _id = t_id; };
	~StartScreen();

	// Inherited via Scene
	virtual void SetupGameObjects();
};

