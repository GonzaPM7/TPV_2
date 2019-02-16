#pragma once

#include "Container.h"
#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "ShowUpAtOpposideSidePC.h"
#include "RotationIC.h"
#include "ThrustIC.h"
#include "ReduceSpeedPC.h"
#include "GunIC.h"

class Fighter: public Container
{
public:
	Fighter(SDLGame* game, Vector2D position, double width, double height);
	virtual ~Fighter();
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
private:
	// components
	ImageGC fighterImage_;
	NaturalMovePC naturalMove_;
	ShowUpAtOpposideSidePC oppositeSide_;
	RotationIC rotation_;
	ThrustIC thrust_;
	ReduceSpeedPC reduceSpeed_;
	GunIC normalGun_;
};

