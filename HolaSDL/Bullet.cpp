#include "Bullet.h"



Bullet::Bullet(): bulletImage_(), deactivate_(), naturalMove_()
{
	power_ = 10;
}


Bullet::~Bullet()
{
}

int Bullet::getPower()
{
	return power_;
}

void Bullet::setPower(int power)
{
	power_ = power;
}

void Bullet::setComponents(ImageGC bulletImage, NaturalMovePC naturalMove, DeactivateOnBorderExit deactivate)
{
	bulletImage_ = bulletImage;
	naturalMove_ = naturalMove;
	deactivate_ = deactivate;
}

void Bullet::setParameters(Vector2D position, Vector2D velocity, double width, double height)
{
	setPosition(position);
	setVelocity(velocity);
	setWidth(width);
	setHeight(height);
}

void Bullet::update(Uint32 time)
{
	naturalMove_.update(this, 1);
	deactivate_.update(this, 1);
}

void Bullet::render(Uint32 time)
{
	bulletImage_.render(this, 1);
}
