#pragma once
#include "Service.h"
class GameLoop :public Service
{
private:
	void start();
	void update();


public:
	GameLoop();
	~GameLoop();
	void run();


	// Inherited via Service
	virtual void initialize() override;

};

