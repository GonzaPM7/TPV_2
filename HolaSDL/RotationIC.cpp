#include "RotationIC.h"



RotationIC::RotationIC()
{
}


RotationIC::~RotationIC()
{
}

void RotationIC::handleInput(Container * c, Uint32 time, const SDL_Event & event)
{
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_RIGHT:
			// rotate fighter to right
			c->setRotation(((int)c->getRotation() + 5) % 360);
			c->setVelocity(c->getVelocity().rotate(5));
			break;
		case SDLK_LEFT:
			// rotate fighter to left
			c->setRotation(((int)c->getRotation() + 360 - 5) % 360);
			c->setVelocity(c->getVelocity().rotate(-5));
			break;
		default:
			break;
		}
	}
}
