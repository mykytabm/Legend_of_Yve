#pragma once
#include "Scene.h"
#include "Unit.h"

class FightScreen : public Scene
{
private:
	//Unit _player;
	//Unit _enemy;
public:
	FightScreen(int str, int agi, int wit);

	
	// Inherited via Scene
	virtual void SetupGameObjects() override;
};

