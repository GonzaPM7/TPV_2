#include "Asteroid.h"


Asteroid::Asteroid()
{
	setId(msg::Asteroid);

	generations_ = 3;
}


Asteroid::~Asteroid()
{
}

int Asteroid::getGenerations()
{
	return generations_;
}

void Asteroid::setGenerations(int generations)
{
	generations_ = generations;
}

void Asteroid::receive(const void * senderObj, const msg::Message & msg)
{
	Container::receive(senderObj, msg);

	switch (msg.type_)
	{
	}
}
