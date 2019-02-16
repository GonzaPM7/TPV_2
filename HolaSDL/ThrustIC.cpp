#include "ThrustIC.h"


ThrustIC::ThrustIC(SDL_Keycode thrustKey, double thrust, double speedLimit)
{
	thrustKey_ = thrustKey;
	thrust_ = thrust;
	speedLimit_ = speedLimit;
}

ThrustIC::~ThrustIC()
{
}

void ThrustIC::handleInput(Container * c, Uint32 time, const SDL_Event & event)
{
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == thrustKey_) {
			if (c->getVelocity().magnitude() < speedLimit_) {
				c->setVelocity(c->getVelocity() + (Vector2D(0, -1).rotate(c->getRotation())*thrust_));
			}
			else
			{
				c->setVelocity(c->getVelocity().normalize() * speedLimit_);
			}
		}
	}
}
