#pragma once

#include "GameObjectPool.h"
#include "Asteroid.h"
#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "RotatingPC.h"
#include "ShowUpAtOpposideSidePC.h"
#include <vector>

class Asteroids: public GameObjectPool<Asteroid, 50>
{
private:
	ImageGC asteroidImage_;
	NaturalMovePC naturalMove_;
	RotatingPC rotating_;
	ShowUpAtOpposideSidePC showUpAtOpposideSide_;
public:
	Asteroids(SDLGame* game);
	~Asteroids();
	void assignComponentsToAsteroids(SDLGame* game);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
};

