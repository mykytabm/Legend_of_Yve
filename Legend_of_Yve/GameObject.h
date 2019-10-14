#pragma once
#include <string>
#include <vector>
class Component;
class RenderManager;
class GameLoop;
class GameObject
{

private:

protected:
	bool m_isActive = true;
	std::vector<Component*> m_components;
	std::vector<GameObject> m_children;
	std::string m_name;
public:
	GameObject() {};
	virtual void Start();
	GameObject(std::string t_name);
	virtual ~GameObject();
	bool Active() { return m_isActive; };
	std::vector<Component*> Components() { return m_components; };
	std::string Name() const { return  m_name; };

	template <typename T>
	void AddComponent();
	void AddComponent(Component* t_component);
	void RegisterComponents(GameLoop* t_gameLoop, RenderManager* t_renderManager);
	bool ContainsComponent(Component* t_component);
	template<typename T>
	bool ContainsComponent(T t_type);
};


