#pragma once

#include "GameObjectPool.h"
#include "Bullet.h"
#include "BulletShooterIC.h"
#include <vector>

class Bullets: public GameObjectPool<Bullet, 10>
{
private:
	NaturalMovePC naturalMove_;
	DeactivateOnBorderExit deactivate_;
	ImageGC bulletImage_;
public:
	Bullets(SDLGame* game);
	virtual ~Bullets();

	virtual void receive(const void* senderObj, const msg::Message& msg);
};

