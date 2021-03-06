#include "ThrustIC.h"
#include "InputHandler.h"


ThrustIC::ThrustIC(SDL_Keycode thrustKey, double thrust, double speedLimit)
{
	thrustKey_ = thrustKey;
	thrust_ = thrust;
	speedLimit_ = speedLimit;
}

ThrustIC::~ThrustIC()
{
}

void ThrustIC::handleInput(Container * c, Uint32 time)
{
	if (InputHandler::getInstance()->isAnyKeyDown()) {
		if (InputHandler::getInstance()->isKeyDown(thrustKey_)) {
			c->setVelocity(c->getVelocity() + (Vector2D(0, -1).rotate(c->getRotation())*thrust_));
			if (c->getVelocity().magnitude() > speedLimit_) 
			{
				c->setVelocity(c->getVelocity().normalize() * speedLimit_);
			}
		}
	}
}
