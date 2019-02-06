#pragma once

#include "GameObject.h"
#include "Egg.h"
#include "ObjectPool.h"

/*
 *
 */
class EggsShooter: public ObjectPool<Egg, 20> {
public:
	EggsShooter(SDLGame* game);
	virtual ~EggsShooter();
	virtual void addEgg(Vector2D pos, Vector2D vel, Vector2D acc);
};

