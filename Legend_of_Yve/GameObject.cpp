#include "GameObject.h"
#include "Component.h"
#include <typeinfo>





GameObject::GameObject(std::string t_name) : m_name(t_name)
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
		m_components.push_back(component);
	}
}


void GameObject::AddComponent(Component* t_component)
{
	if (ContainsComponent(t_component) == false)
	{
		m_components.push_back(t_component);
		//register component
	}
}



bool GameObject::ContainsComponent(Component* t_component)
{
	for (auto component : m_components)
	{
		if (typeid(t_component) == typeid(component))
		{
			return true;
		}
	}
	return false;
}

template<typename T>
bool GameObject::ContainsComponent(T t_type)
{
	for (auto component : m_components)
	{
		if (t_type == typeid(component))
		{
			return true;
		}
	}
	return false;
}
