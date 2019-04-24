#pragma once

#include "Container.h"
#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "ShowUpAtOpposideSidePC.h"
#include "RotationIC.h"
#include "ThrustIC.h"
#include "ReduceSpeedPC.h"
#include "GunIC.h"
#include "Messages_defs.h"

class Fighter: public Container
{
private:
	// components
	ImageGC fighterImage_;
	NaturalMovePC naturalMove_;
	ShowUpAtOpposideSidePC oppositeSide_;
	RotationIC rotation_;
	ThrustIC thrust_;
	ReduceSpeedPC reduceSpeed_;
	GunIC normalGun_;
public:
	Fighter(SDLGame* game);
	virtual ~Fighter();

	virtual void receive(const void* senderObj, const msg::Message& msg);

	void onGameStart(const msg::Message& msg);
	void onRoundStart();
	void onRoundOver();
};

