#pragma once

#include "GameObjectPool.h"
#include "Asteroid.h"
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
	void createAsteroid();
};

