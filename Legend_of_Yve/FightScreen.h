#pragma once
#include "Scene.h"
#include "Unit.h"

class FightScreen : public Scene
{
private:
	//Unit _player;
	//Unit _enemy;
public:
	FightScreen();
	FightScreen(const std::string t_id);
	~FightScreen();
	// Inherited via Scene
	virtual void SetupGameObjects() override;
};

