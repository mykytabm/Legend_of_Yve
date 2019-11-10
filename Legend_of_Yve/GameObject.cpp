#include "GameObject.h"
#include <typeinfo>
#include "GameLoop.h"
#include <iostream>

void GameObject::Start() { }

void GameObject::Update() { }


GameObject::GameObject(std::string t_name) : _name(t_name) { }

GameObject::~GameObject()
{
	//TODO: fix because this triggers breakpoint

	//for (auto component : _components)
	//{
	//	delete component;
	//}
}

void GameObject::SetActive(bool value)
{
	this->_active = value;
	for (auto child : _children)
	{
		child->SetActive(value);
	}

	for (auto component : _components)
	{
		component->SetActive(value);
	}
}

void GameObject::AddChild(GameObject* t_child)
{
	_children.push_back(t_child);
}

void GameObject::AddComponent(Component* t_component)
{
	if (!ContainsComponent(t_component))
	{
		_components.push_back(t_component);
	}
}

void GameObject::Register(GameLoop& t_gameLoop, RenderManager& t_renderManager)
{
	if (_active)
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
		for (auto comp : _components)
		{
			comp->DeRegister(t_gameLoop, t_renderManager);
			//TODO: Delete component
		}
	}
}

void GameObject::StartComponents()
{
	for (int i = 0; i < _components.size(); ++i)
	{
		_components[i]->Start();
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

