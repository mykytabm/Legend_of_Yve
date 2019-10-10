#pragma once
#include "Scene.h"

class SceneManager
{
private:
	Scene* m_currentScene;
public:
	void LoadScene(Scene* t_scene);
	SceneManager();
	~SceneManager();
};

