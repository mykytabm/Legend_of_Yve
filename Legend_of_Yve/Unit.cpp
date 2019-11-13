#include "Unit.h"

void Unit::Strength(const int t_strength)
{
	_strength = t_strength;
}

int Unit::Strength() const
{
	return _strength;
}

void Unit::Agility(const int t_agility)
{
	_agility = t_agility;
}

int Unit::Agility() const
{
	return _agility;
}

void Unit::Wits(const int t_wits)
{
	_wits = t_wits;
}

int Unit::Wits() const
{
	return _wits;
}
