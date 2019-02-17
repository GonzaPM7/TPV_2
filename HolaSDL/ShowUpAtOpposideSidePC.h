#pragma once

#include "PhysicsComponent.h"

class ShowUpAtOpposideSidePC: public PhysicsComponent
{
public:
	ShowUpAtOpposideSidePC();
	~ShowUpAtOpposideSidePC();
	virtual void update(Container* c, Uint32 time);
};

