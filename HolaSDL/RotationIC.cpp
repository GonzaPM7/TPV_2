#include "RotationIC.h"
#include "InputHandler.h"

RotationIC::RotationIC(SDL_Keycode left, SDL_Keycode right, int angle)
{
	angle_ = angle;
	left_ = left;
	right_ = right;
}


RotationIC::~RotationIC()
{
}

void RotationIC::handleInput(Container * c, Uint32 time)
{
	if (InputHandler::getInstance()->isAnyKeyDown()) {
		if (InputHandler::getInstance()->isKeyDown(right_)) {

			// rotate fighter to right
			c->setRotation(((int)c->getRotation() + angle_) % 360);
			c->setVelocity(c->getVelocity().rotate(angle_));
		}
		if (InputHandler::getInstance()->isKeyDown(left_)) {
			// rotate fighter to left
			c->setRotation(((int)c->getRotation() + 360 - angle_) % 360);
			c->setVelocity(c->getVelocity().rotate(-angle_));
		}
	}
}
	

