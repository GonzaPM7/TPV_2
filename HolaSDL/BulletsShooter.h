#pragma once

#include "Bullet.h"
#include "GameObject.h"
#include "ObjectPool.h"

/*
 *
 */
class BulletsShooter: public ObjectPool<Bullet, 100> {
public:
	BulletsShooter(SDLGame* game);
	virtual ~BulletsShooter();
	virtual void addBullet(Vector2D pos, Vector2D vel);
};

