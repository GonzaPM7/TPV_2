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
	Fighter(SDLGame* game);
	virtual ~Fighter();
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

