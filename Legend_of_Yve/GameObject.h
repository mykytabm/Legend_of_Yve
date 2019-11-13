#pragma once
#include <string>
#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include "Component.h"


class RenderManager;
class GameLoop;
class GameObject
{

public:
	void StartComponents();
protected:
	bool _active = true;
	bool _persistant = false;
	std::vector<Component*> _components;
	std::vector<GameObject*> _children;
	std::string _name;
	sf::Vector2f _position = sf::Vector2f(0, 0);
	GameObject() { };

public:
	GameObject(const std::string t_name);
	virtual ~GameObject();
	virtual void Start();
	virtual void Update();
	bool Active() const { return _active; };
	void SetActive(bool value);
	std::vector<Component*> Components() { return _components; };
	std::string GetName() const { return  _name; };
	sf::Vector2f& GetPosition() { return _position; };


	void SetPosition(const sf::Vector2f t_newPosition);

	void DoNotDestroyOnLoad(bool value) { _persistant = value; };
	bool DoNotDestroyOnLoad() { return _persistant; };

	void AddChild(GameObject* t_child);
	void AddComponent(Component* t_component);
	void Register(GameLoop& t_gameLoop, RenderManager& t_renderManager);
	void DeRegister(GameLoop& t_gameLoop, RenderManager& t_renderManager);
	bool ContainsComponent(Component* t_component) const;

	template <typename T>
	T* GetComponent();

	template<typename T>
	bool ContainsComponent() const;

	template <typename T>
	T* AddComponent();
};


template<typename T>
T* GameObject::GetComponent()
{
	for (int i = 0; i < _components.size(); ++i)
	{
		T* castComponent = dynamic_cast<T*>(_components[i]);
		if (castComponent != nullptr)
		{
			return castComponent;
		}
	}
	return nullptr;
}

template<typename T>
bool GameObject::ContainsComponent() const
{
	for (auto component : _components)
	{
		if (typeid(T) == typeid(component))
		{
			return true;
		}
	}
	return false;
}

template<typename T>
T* GameObject::AddComponent()
{
	auto* component = new T();
	if (!ContainsComponent<T>())
	{
		dynamic_cast<Component*>(component)->SetGameObject(this);
		_components.push_back(component);
		return component;
	}
	return nullptr;
}
