#include "GameObject.h"
#include "Component.h"
#include <typeinfo>





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
	if (_isActive)
	{
		for (int j = 0; j < _children.size(); ++j)
		{
			{
				_children[j].Start();
			}
		}
		for (int i = 0; i < _components.size(); ++i)
		{
			_components[i]->Start();
		}
	}
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
		//register component
	}
}

void GameObject::RegisterComponents(GameLoop& t_gameLoop, RenderManager& t_renderManager)
{
	if (_isActive)
	{
		for (int j = 0; j < _children.size(); ++j)
		{
			{
				_children[j].RegisterComponents(t_gameLoop, t_renderManager);
			}
		}
		for (int i = 0; i < _components.size(); ++i)
		{
			_components[i]->Register(t_gameLoop, t_renderManager);
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
