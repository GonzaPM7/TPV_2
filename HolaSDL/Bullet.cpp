#include "Bullet.h"



Bullet::Bullet()
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


