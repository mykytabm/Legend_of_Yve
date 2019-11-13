#include "SceneManager.h"
#include "Component.h"
#include "ServiceLocator.h"
#include "RenderManager.h"
#include "GameLoop.h"
SceneManager::SceneManager()
{
	_currentScene = nullptr;
}

SceneManager::~SceneManager()
{
}

void SceneManager::Initialize()
{

}

void SceneManager::LoadScene(Scene* t_scene)
{
	RenderManager* renderManagerRef = ServiceLocator::Instance()->GetService<RenderManager>();
	GameLoop* gameLoopRef = ServiceLocator::Instance()->GetService<GameLoop>();
	if (_currentScene != nullptr)
	{
		//close previous scene;
		std::cout << "Deleting previous scene" << std::endl;
		_currentScene->DeRegisterGameObjects(renderManagerRef, gameLoopRef);
	}

	_currentScene = t_scene;
	_currentScene->Initialize();
	_currentScene->Start();
	_currentScene->RegisterGameObjects(renderManagerRef, gameLoopRef);
}

void SceneManager::LoadScene(std::string t_sceneName)
{

	RenderManager* renderManagerRef = ServiceLocator::Instance()->GetService<RenderManager>();
	GameLoop* gameLoopRef = ServiceLocator::Instance()->GetService<GameLoop>();
	if (_currentScene != nullptr)
	{
		std::cout << "Closing previous scene..." << std::endl;
		_currentScene->DeRegisterGameObjects(renderManagerRef, gameLoopRef);
	}
	_currentScene = GetSceneByName(t_sceneName);
	_currentScene->Initialize();
	_currentScene->Start();
	_currentScene->RegisterGameObjects(renderManagerRef, gameLoopRef);
}

void SceneManager::AddScene(Scene* t_scene)
{
	if (!ContainsScene(t_scene))
	{
		_scenes.push_back(t_scene);
	}
}

void SceneManager::SetScenes(std::list<Scene*> t_scenes)
{
	_scenes = t_scenes;
}

Scene* SceneManager::CurrentScene()
{
	return _currentScene;
}

bool SceneManager::ContainsScene(Scene* t_scene) const
{
	for (auto& s : _scenes)
	{
		if (s == t_scene) return true;
	}
	return false;
}

Scene* SceneManager::GetSceneByName(const std::string t_sceneName)
{
	for (auto& iter : _scenes)
	{
		if (iter->Name() == t_sceneName) return iter;
	}
	return nullptr;
}



