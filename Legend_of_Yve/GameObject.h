#pragma once
#include <string>
#include <vector>
class Component;

class GameObject
{

private:
	std::string m_name;
	std::vector<Component*> m_components;
public:

	GameObject(std::string t_name);
	~GameObject();
	std::vector<Component*> Components() { return m_components; };
	std::string Name() const { return  m_name; };

	template <typename T>
	void AddComponent();
	void AddComponent(Component* t_component);

	bool ContainsComponent(Component* t_component);
	template<typename T>
	bool ContainsComponent(T t_type);
};


