#include "SceneManager.h"
#include "Component.h"
#include "ServiceLocator.h"
#include "RenderManager.h"
#include "GameLoop.h"
SceneManager::SceneManager() :_currentScene(nullptr)
{

}

SceneManager::~SceneManager()
{
}

void SceneManager::initialize()
{

}

void SceneManager::RegisterGameObjects(Scene* t_scene) const
{
	RenderManager& renderManagerRef = *ServiceLocator::instance()->GetService<RenderManager>();
	GameLoop& gameLoopRef = *ServiceLocator::instance()->GetService<GameLoop>();

	for (int i = 0; i < t_scene->GameObjects().size(); ++i)
	{
		t_scene->GameObjects()[i]->RegisterComponents(gameLoopRef, renderManagerRef);
	}
}

void SceneManager::LoadScene(Scene* t_scene)
{
	if (_currentScene != nullptr)
	{
		//close previous scene;
	}
	_currentScene = t_scene;
	_currentScene->initialize();
	_currentScene->Start();
	RegisterGameObjects(t_scene);
}



