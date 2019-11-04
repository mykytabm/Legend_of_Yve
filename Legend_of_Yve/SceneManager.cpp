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

void SceneManager::RegisterGameObjects(Scene* t_scene)
{
	RenderManager& renderManagerRef = *ServiceLocator::Instance()->GetService<RenderManager>();
	GameLoop& gameLoopRef = *ServiceLocator::Instance()->GetService<GameLoop>();

	for (int i = 0; i < t_scene->GameObjects().size(); ++i)
	{
		t_scene->GameObjects()[i]->Register(gameLoopRef, renderManagerRef);
	}
}

void SceneManager::DeRegisterGameObjects(Scene* t_scene)
{
	RenderManager& renderManagerRef = *ServiceLocator::Instance()->GetService<RenderManager>();
	GameLoop& gameLoopRef = *ServiceLocator::Instance()->GetService<GameLoop>();
	std::vector<GameObject*> temp = t_scene->GameObjects();
	for (int i = 0; i < temp.size(); ++i)
	{
		temp[i]->DeRegister(gameLoopRef, renderManagerRef);
	}
}

void SceneManager::LoadScene(Scene* t_scene)
{
	if (_currentScene != nullptr)
	{
		//close previous scene;
		std::cout << "Deleting previous scene" << std::endl;
		DeRegisterGameObjects(_currentScene);
	}
	_currentScene = t_scene;
	_currentScene->Initialize();
	_currentScene->Start();
	RegisterGameObjects(t_scene);
}

void SceneManager::LoadScene(std::string t_sceneName)
{
	Scene* s = GetSceneByName(t_sceneName);
	if (_currentScene != nullptr)
	{
		//close previous scene;
		std::cout << "Deleting previous scene" << std::endl;
		DeRegisterGameObjects(_currentScene);
	}
	_currentScene = s;
	_currentScene->Initialize();
	_currentScene->Start();
	RegisterGameObjects(s);
}

void SceneManager::AddScene(Scene* t_scene)
{
	if (!ContainsScene(t_scene))
	{
		_scenes.push_back(t_scene);
	}
}

bool SceneManager::ContainsScene(Scene* t_scene)
{
	for (auto& s : _scenes)
	{
		if (s == t_scene) return true;
	}
	return false;
}

Scene* SceneManager::GetSceneByName(std::string t_sceneName)
{
	for (auto& iter : _scenes)
	{
		if (iter->Name() == t_sceneName) return iter;
	}
	return nullptr;
}



