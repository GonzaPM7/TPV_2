#pragma once

#include "Container.h"
#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "RotatingPC.h"
#include "ShowUpAtOpposideSidePC.h"


class Asteroid: public Container
{
private:
	int generations_;
	ImageGC asteroidImage_;
	NaturalMovePC naturalMove_;
	RotatingPC rotating_;
	ShowUpAtOpposideSidePC showUpAtOpposideSide_;
public:
	Asteroid(SDLGame* game, ImageGC asteroidImage, NaturalMovePC naturalMove, RotatingPC rotating, ShowUpAtOpposideSidePC showUpAtOpposideSide);
	~Asteroid();
	int getGenerations();
	void setGenerations(int generations);
};

