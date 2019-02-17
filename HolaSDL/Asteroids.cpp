#include "Asteroids.h"



Asteroids::Asteroids(SDLGame* game, Vector2D position, double width, double height) :
	GameObjectPool(game), asteroidImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)),
	naturalMove_(), rotating_(5), showUpAtOpposideSide_()
{
	setWidth(width);
	setHeight(height);
	setPosition(position);
	// falta asignar componentes a cada asteroide
	assignComponentsToAsteroids(game);
}


Asteroids::~Asteroids()
{
}

void Asteroids::assignComponentsToAsteroids(SDLGame* game)
{
	vector<Asteroid*> asteroids = getAllObjects();

	for (int i = 0; asteroids.size(); i++)
	{
		asteroids[i] = Asteroid(game, asteroidImage_, naturalMove_, rotating_, showUpAtOpposideSide_);
	}
}
