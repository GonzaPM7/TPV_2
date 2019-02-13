#pragma once

#include "Container.h"
#include "ImageGC.h"
#include "NaturalMovePC.h"

class Fighter: public Container
{
public:
	Fighter(SDLGame* game);
	virtual ~Fighter();
private:
	// components
	Texture* fighterTexture_;
	SDL_Rect clip_;
	ImageGC fighterImage_;
	NaturalMovePC naturalMove_;
	//ShowUpAtOppositeSidePC oppositeSide_;
	//RotationIC rotation_;
	//ThrustIC thrust_;
	//ReduceSpeedPC reduceSpeed_;
	//GunIC normalGun_;
};

