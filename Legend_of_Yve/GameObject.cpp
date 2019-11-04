#include "GameObject.h"
#include "Component.h"
#include <typeinfo>
#include "GameLoop.h"
#include <iostream>



void GameObject::StartComponents()
{

	for (int i = 0; i < _components.size(); ++i)
	{
		_components[i]->Start();
	}
}

void GameObject::Start()
{
}

void GameObject::Update()
{

}

GameObject::GameObject(std::string t_name) : _name(t_name)
{

}

GameObject::~GameObject()
{

}



template<typename T>
void GameObject::AddComponent()
{
	if (ContainsComponent(T) == false)
	{
		auto* component = new T();
		static_cast<Component>(component).SetGameObject(this);
		_components.push_back(component);
	}
}


void GameObject::AddComponent(Component* t_component)
{
	if (ContainsComponent(t_component) == false)
	{
		_components.push_back(t_component);
	}
}

void GameObject::Register(GameLoop& t_gameLoop, RenderManager& t_renderManager)
{
	if (_isActive)
	{
		t_gameLoop.Register(this);
		for (int i = 0; i < _components.size(); ++i)
		{
			_components[i]->Register(t_gameLoop, t_renderManager);
		}
	}

}

void GameObject::DeRegister(GameLoop& t_gameLoop, RenderManager& t_renderManager)
{
	if (!_persistant)
	{
		t_gameLoop.DeRegister(this);
		while (!_components.empty())
		{
			_components.front()->DeRegister(t_gameLoop, t_renderManager);
			Component* temp = _components.front();
			std::cout << "Deleting component" << std::endl;
			//TODO: Delete component
			delete temp;
		}
	}
}



bool GameObject::ContainsComponent(Component* t_component) const
{
	for (auto component : _components)
	{
		if (typeid(t_component) == typeid(component))
		{
			return true;
		}
	}
	return false;
}
