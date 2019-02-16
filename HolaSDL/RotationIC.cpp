#include "RotationIC.h"



RotationIC::RotationIC(SDL_Event left, SDL_Event right, int angle)
{
	angle_ = angle;
	left_ = left;
	right_ = right;
}


RotationIC::~RotationIC()
{
}

void RotationIC::handleInput(Container * c, Uint32 time, const SDL_Event & event)
{
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == right_.key.keysym.sym) {

			// rotate fighter to right
			c->setRotation(((int)c->getRotation() + angle_) % 360);
			c->setVelocity(c->getVelocity().rotate(angle_));
		}
		if (event.key.keysym.sym == left_.key.keysym.sym) {
			// rotate fighter to left
			c->setRotation(((int)c->getRotation() + 360 - angle_) % 360);
			c->setVelocity(c->getVelocity().rotate(-angle_));
		}
	}
}
	
