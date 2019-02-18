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
	BulletShooterIC bulletShooter_;
public:
	Bullets(SDLGame* game);
	virtual ~Bullets();
	void assignComponentsToBullets(SDLGame* game);
	void spawnExampleBullet();
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
};

