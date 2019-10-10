#pragma once
class Service
{
	Service();
	virtual ~Service() = default;
	virtual void initialize() = 0;
};

