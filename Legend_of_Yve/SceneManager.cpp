#include "SceneManager.h"

SceneManager::SceneManager() :m_currentScene(nullptr)
{

}

SceneManager::~SceneManager()
{
}

void SceneManager::initialize()
{

}

void SceneManager::LoadScene(Scene* t_scene)
{
	if (m_currentScene != nullptr)
	{
		//close previous scene;
	}
	m_currentScene = t_scene;
	m_currentScene->initialize();
}


