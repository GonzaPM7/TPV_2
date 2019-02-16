#pragma once

#include "Component.h"
#include "Container.h"
#include "sdl_includes.h"

class ThrustIC
{
private:
	SDL_Event thrustKey_;
	double thrust_;
	double speedLimit_;
public:
	ThrustIC(SDL_Event thrustKey, double thrust, double speedLimit);
	~ThrustIC();
	virtual void handleInput(Container* c, Uint32 time, const SDL_Event& event);
};

