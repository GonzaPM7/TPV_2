#pragma once

#include "Component.h"
#include "sdl_includes.h"
#include "InputComponent.h"

class BulletShooterIC: public InputComponent
{
private:
	SDL_Keycode shootKey_;
public:
	BulletShooterIC(SDL_Keycode shootKey);
	~BulletShooterIC();
	virtual void handleInput(Container* c, Uint32 time) {};
	virtual bool handleInputEvent(Container* c, Uint32 time, const SDL_Event& event);
};

