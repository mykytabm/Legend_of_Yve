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
	Scene* CurrentScene() { return _currentScene; };
	void LoadScene(Scene* t_scene);
	void LoadScene(std::string t_sceneName);
	void AddScene(Scene* t_scene);
	void SetScenes(std::list<Scene*> t_scenes) { _scenes = t_scenes; };
	bool ContainsScene(Scene* t_scene);
	Scene* GetSceneByName(std::string t_sceneName);

	SceneManager();
	~SceneManager();

	// Inherited via Service
	virtual void Initialize() override;
};

