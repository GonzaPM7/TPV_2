#pragma once

#include "Component.h"
#include "Container.h"
#include "sdl_includes.h"

class RotationIC
{
public:
	RotationIC();
	~RotationIC();
	virtual void handleInput(Container* c, Uint32 time, const SDL_Event& event);
};

