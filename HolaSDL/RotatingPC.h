#pragma once

#include "PhysicsComponent.h"

class RotatingPC: public PhysicsComponent
{
private:
	int angle_;
public:
	RotatingPC();
	RotatingPC(int angle);
	~RotatingPC();
	virtual void update(Container* c, Uint32 time);

};

