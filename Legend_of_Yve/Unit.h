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

	void SetHP();
	void SetSanity();

public:

	Unit() {};
	Unit(int t_strength, int t_agility, int t_wits);
	~Unit();
	void Start() override;
	void Update() override;

	void Strength(const int t_strength) { _strength = t_strength; };
	int Strength() const { return _strength; };

	void Agility(const int t_agility) { _agility = t_agility; };
	int Agility() const { return _agility; };

	void Wits(const int t_wits) { _wits = t_wits; };
	int Wits() const { return _wits; };

	void Attack();
	void Hit(int t_damage);
	void Heal(int t_healAmount);

	void Die();
};

