#pragma once
#include "Scene.h"
#include "Service.h"
class SceneManager : public Service
{
private:
	Scene* m_currentScene;
	void RegisterGameObjects(Scene* t_scene);
public:
	void LoadScene(Scene* t_scene);
	SceneManager();
	~SceneManager();

	// Inherited via Service
	virtual void initialize() override;
};

