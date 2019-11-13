#pragma once
#include "Scene.h"
#include "Service.h"
#include <list>
class SceneManager : public Service
{
private:
	Scene* _currentScene;
	std::list<Scene*> _scenes;

public:
	SceneManager();
	~SceneManager();

	Scene* CurrentScene();
	bool ContainsScene(Scene* t_scene) const;
	Scene* GetSceneByName( const std::string t_sceneName);

	void LoadScene(Scene* t_scene);
	void LoadScene(std::string t_sceneName);
	void AddScene(Scene* t_scene);
	void SetScenes(std::list<Scene*> t_scenes);

	virtual void Initialize() override;
};

