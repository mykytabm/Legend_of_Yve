#include "SceneManager.h"
#include "Component.h"
#include "ServiceLocator.h"
class Gameloop;
class RenderManager;
SceneManager::SceneManager() :m_currentScene(nullptr)
{

}

SceneManager::~SceneManager()
{
}

void SceneManager::initialize()
{

}

void SceneManager::RegisterGameObjects(Scene* t_scene)
{


	for (int i = 0; i < t_scene->GameObjects().size(); ++i)
	{
		for (int j = 0; j < t_scene->GameObjects()[i]->Components().size(); ++j)
		{
			t_scene->GameObjects()[i]->Components()[j]->Register();
		}
	}
}

void SceneManager::LoadScene(Scene* t_scene)
{
	if (m_currentScene != nullptr)
	{
		//close previous scene;
	}
	m_currentScene = t_scene;
	m_currentScene->initialize();
	RegisterGameObjects(t_scene);
}


