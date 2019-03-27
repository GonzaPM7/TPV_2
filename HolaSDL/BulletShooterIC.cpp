#include "BulletShooterIC.h"
#include "InputHandler.h"


BulletShooterIC::BulletShooterIC(SDL_Keycode shootKey)
{
	shootKey_ = shootKey;
}


BulletShooterIC::~BulletShooterIC()
{
}

bool BulletShooterIC::handleInputEvent(Container * c, Uint32 time, const SDL_Event & event)
{
	if (InputHandler::getInstance()->isAnyKeyDown()) {
		if (InputHandler::getInstance()->isKeyDown(shootKey_)) {
			return true;
		}
		else return false;
	}
}
