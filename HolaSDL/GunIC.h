#pragma once

#include "Component.h"
#include "Container.h"
#include "sdl_includes.h"
#include "InputComponent.h"

class GunIC: public InputComponent
{
private:
	SDL_Keycode shootKey_;
public:
	GunIC(SDL_Keycode shootKey);
	~GunIC();
	virtual void handleInput(Container* c, Uint32 time);

};

