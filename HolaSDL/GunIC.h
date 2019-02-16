#pragma once

#include "Component.h"
#include "Container.h"
#include "sdl_includes.h"

class GunIC
{
private:
	SDL_Event shootKey_;
public:
	GunIC(SDL_Event shootKey);
	~GunIC();
	virtual void handleInput(Container* c, Uint32 time, const SDL_Event& event);

};

