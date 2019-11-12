#pragma once
#include "GameObject.h"
#include "SpriteComponent.h"

class Unit : public GameObject
{
private:
	int _strength;
	int _agility;
	int _wits;

	int _health;
	int _sanity;
	SpriteComponent _sprite;
public:
};

