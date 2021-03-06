#pragma once

#include "Component.h"
#include "Container.h"
#include "sdl_includes.h"
#include "InputComponent.h"

class RotationIC: public InputComponent
{
private:
	int angle_;
	SDL_Keycode left_;
	SDL_Keycode right_;
public:
	RotationIC(SDL_Keycode left, SDL_Keycode right, int angle);
	~RotationIC();
	virtual void handleInput(Container* c, Uint32 time);
};

