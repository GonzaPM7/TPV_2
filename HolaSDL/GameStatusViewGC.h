#pragma once

#include "GraphicsComponent.h"

class GameStatusViewGC: public GraphicsComponent
{
public:
	GameStatusViewGC();
	~GameStatusViewGC();
	virtual void render(Container* c, Uint32 time);

};

