#pragma once
#include "GameObject.h"
#include "SpriteComponent.h"

class Unit : public GameObject
{

private:
	SpriteComponent _sprite;

	int _strength;
	int _agility;
	int _wits;

	int _health;
	int _sanity;

	

public:

	Unit() {};
	Unit(int t_strength, int t_agility, int t_wits);
	~Unit();

	int Strength() const;
	int Agility() const;
	int Wits() const;

	void Strength(const int t_strength);
	void Agility(const int t_agility);
	void Wits(const int t_wits);

	void Attack();
	void Hit(int t_damage);
	void Heal(int t_healAmount);
	void Die();

	void Start() override;
	void Update() override;
};

