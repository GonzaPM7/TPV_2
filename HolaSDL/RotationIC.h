#pragma once

#include "Component.h"
#include "Container.h"
#include "sdl_includes.h"

class RotationIC
{
private:
	int angle_;
	SDL_Event left_;
	SDL_Event right_;
public:
	RotationIC(SDL_Event left, SDL_Event right, int angle);
	~RotationIC();
	virtual void handleInput(Container* c, Uint32 time, const SDL_Event& event);
};
