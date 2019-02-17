#include "Asteroid.h"


Asteroid::Asteroid(): asteroidImage_(), naturalMove_(), rotating_(), showUpAtOpposideSide_()
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

void Asteroid::setComponents(ImageGC asteroidImage, NaturalMovePC naturalMove, RotatingPC rotating, ShowUpAtOpposideSidePC showUpAtOpposideSide)
{
	asteroidImage_ = asteroidImage;
	naturalMove_ = naturalMove;
	rotating_ = rotating;
	showUpAtOpposideSide_ = showUpAtOpposideSide;
}

void Asteroid::setParameters(Vector2D position, Vector2D velocity, double width, double height)
{
	setPosition(position);
	setVelocity(velocity);
	setWidth(width);
	setHeight(height);
}

void Asteroid::update(Uint32 time)
{
	naturalMove_.update(this, 1);
	showUpAtOpposideSide_.update(this, 1);
	rotating_.update(this, 1);
}

void Asteroid::render(Uint32 time)
{
	asteroidImage_.render(this, 1);
}
