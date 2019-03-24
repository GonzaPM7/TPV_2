#include "Asteroid.h"


Asteroid::Asteroid()
{
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


