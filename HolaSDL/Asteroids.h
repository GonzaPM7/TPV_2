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

	virtual void receive(const void* senderObj, const msg::Message& msg);

	void onGameStart(const msg::Message& msg);
	void onRoundStart();
	void onRoundOver();
	void onCollisionWithBullet(const msg::Message& msg);
	void onCollisionWithBlackhole(const msg::Message& msg);
};

