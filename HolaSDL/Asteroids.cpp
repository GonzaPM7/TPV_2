#include "Asteroids.h"



Asteroids::Asteroids(SDLGame* game) :
	GameObjectPool(game), asteroidImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)),
	naturalMove_(), rotating_(5), showUpAtOpposideSide_()
{
	setWidth(20);
	setHeight(20);
	double velX = game->getServiceLocator()->getRandomGenerator()->nextInt(1, 5);
	double velY = game->getServiceLocator()->getRandomGenerator()->nextInt(1, 5);
	setVelocity(Vector2D{ velX, velY });
	double posX = game->getServiceLocator()->getRandomGenerator()->nextInt(0, game->getWindowWidth());
	double posY = game->getServiceLocator()->getRandomGenerator()->nextInt(0, game->getWindowHeight());
	setPosition(Vector2D(posX, posY));

	for (Asteroid* b : getAllObjects())
	{
		addC(&naturalMove_);
		addC(&asteroidImage_);
		addC(&rotating_);
		addC(&showUpAtOpposideSide_);
	}

	createAsteroid();

	setActive(false);
}


Asteroids::~Asteroids()
{
}


void Asteroids::createAsteroid()
{
	Asteroid *a = getUnusedObject();
	a->setPosition(getPosition());
	a->setVelocity(getVelocity());
	a->setWidth(getWidth());
	a->setHeight(getHeight());
	a->setActive(true);
}


