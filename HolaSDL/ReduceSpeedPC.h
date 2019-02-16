#pragma once

#include "PhysicsComponent.h"

class ReduceSpeedPC
{
private:
	double factor_;
public:
	ReduceSpeedPC(double factor);
	~ReduceSpeedPC();
	virtual void update(Container* c, Uint32 time);

};

