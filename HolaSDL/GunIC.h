#pragma once

#include "Component.h"
#include "Container.h"
#include "sdl_includes.h"

class GunIC
{
private:
	SDL_Keycode shootKey_;
public:
	GunIC(SDL_Keycode shootKey);
	~GunIC();
	virtual void handleInput(Container* c, Uint32 time, const SDL_Event& event);

};

