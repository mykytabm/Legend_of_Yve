#pragma once
#include <string>
#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
class Component;
class RenderManager;
class GameLoop;
class GameObject
{

public:
	void StartComponents();
protected:
	bool _isActive = true;
	bool _persistant = false;
	std::vector<Component*> _components;
	std::vector<GameObject> _children;
	std::string _name;
	sf::Vector2f _position;

public:
	GameObject() { };
	virtual void Start();
	virtual void Update();
	//virtual void HandleEvent(const sf::Event& t_event) { };
	GameObject(const std::string t_name);
	virtual ~GameObject();
	bool Active() const { return _isActive; };
	std::vector<Component*> Components() { return _components; };
	std::string Name() const { return  _name; };
	sf::Vector2f Position() const { return _position; };
	void SetPosition(const sf::Vector2f t_newPosition) { _position = t_newPosition; };
	template <typename T>
	void AddComponent();
	void DoNotDestroyOnLoad(bool value) { _persistant = value; };
	bool DoNotDestroyOnLoad() { return _persistant; };
	template<typename T>
	bool ContainsComponent(T t_type) const;

	template <typename T>
	T& GetComponent() const;

	void AddComponent(Component* t_component);
	void Register(GameLoop& t_gameLoop, RenderManager& t_renderManager);
	void DeRegister(GameLoop& t_gameLoop, RenderManager& t_renderManager);
	bool ContainsComponent(Component* t_component) const;

};


template<typename T>
T& GameObject::GetComponent() const
{
	for (auto& component : _components)
	{

		T* castComponent = dynamic_cast<T*>(component);
		if (castComponent != nullptr)
		{

			return *castComponent;
		}
	}
}

template<typename T>
bool GameObject::ContainsComponent(T t_type) const
{
	for (auto component : _components)
	{
		if (t_type == typeid(component))
		{

			return true;
		}
	}
	return false;
}
