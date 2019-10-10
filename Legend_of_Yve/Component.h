#pragma once
#include "GameObject.h"

class Component
{
private:
	GameObject* m_owner;

public:
	void SetGameObject(GameObject* t_gameObject)
	{
		if (t_gameObject != nullptr) m_owner = t_gameObject;
	};

	virtual void update() {};
	virtual void Register() {};
};

