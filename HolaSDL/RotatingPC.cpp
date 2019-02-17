#include "RotatingPC.h"



RotatingPC::RotatingPC(int angle)
{
	angle_ = angle;
}


RotatingPC::~RotatingPC()
{
}

void RotatingPC::update(Container * c, Uint32 time)
{
	c->setRotation(((int)c->getRotation() + angle_) % 360);
}
