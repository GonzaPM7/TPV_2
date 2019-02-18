#pragma once

#include "PhysicsComponent.h"

class DeactivateOnBorderExit: public PhysicsComponent
{
public:
	DeactivateOnBorderExit();
	~DeactivateOnBorderExit();
	virtual void update(Container* c, Uint32 time);

};

