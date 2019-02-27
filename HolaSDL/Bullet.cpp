#include "Bullet.h"



Bullet::Bullet()
{
	setId(msg::Bullet);

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

void Bullet::receive(const void * senderObj, const msg::Message & msg)
{
	Container::receive(senderObj, msg);

	switch (msg.type_)
	{
	}

}
