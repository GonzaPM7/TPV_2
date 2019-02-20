#pragma once

#include "Component.h"
#include "Container.h"
#include "sdl_includes.h"
#include "InputComponent.h"

class GameCtrlIC: public InputComponent
{
public:
	GameCtrlIC();
	~GameCtrlIC();
	virtual void handleInput(Container* c, Uint32 time, const SDL_Event& event);
};

