#pragma once

#include "Component.h"
#include "Container.h"
#include "sdl_includes.h"
#include "InputComponent.h"

class ThrustIC: public InputComponent
{
private:
	SDL_Keycode thrustKey_;
	double thrust_;
	double speedLimit_;
public:
	ThrustIC(SDL_Keycode thrustKey, double thrust, double speedLimit);
	~ThrustIC();
	virtual void handleInput(Container* c, Uint32 time);
};

