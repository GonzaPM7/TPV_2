#include "BulletShooterIC.h"



BulletShooterIC::BulletShooterIC(SDL_Keycode shootKey)
{
	shootKey_ = shootKey;
}


BulletShooterIC::~BulletShooterIC()
{
}

bool BulletShooterIC::handleInputEvent(Container * c, Uint32 time, const SDL_Event & event)
{
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == shootKey_) {
			return true;
		}
		else return false;
	}
}
