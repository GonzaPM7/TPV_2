#include "Asteroid.h"


Asteroid::Asteroid(SDLGame* game, ImageGC asteroidImage, NaturalMovePC naturalMove, RotatingPC rotating, ShowUpAtOpposideSidePC showUpAtOpposideSide): Container(game)
{
	generations_ = 3;
	asteroidImage_ = asteroidImage;
	naturalMove_ = naturalMove;
	rotating_ = rotating;
	showUpAtOpposideSide_ = showUpAtOpposideSide;
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
