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
	assignComponentsToAsteroids(game);

	Asteroid *a = getUnusedObject();
	a->setActive(true);
}


Asteroids::~Asteroids()
{
}

void Asteroids::assignComponentsToAsteroids(SDLGame* game)
{
	vector<Asteroid*> asteroids = getAllObjects();

	for (int i = 0; i < asteroids.size(); i++)
	{
		asteroids[i]->setComponents(asteroidImage_, naturalMove_, rotating_, showUpAtOpposideSide_);
		asteroids[i]->setParameters(getPosition(), getVelocity(), getWidth(), getHeight());
	}
}

void Asteroids::update(Uint32 time)
{
	vector<Asteroid*> asteroids = getAllObjects();

	for (int i = 0; i < asteroids.size(); i++)
	{
		if (asteroids[i]->isActive())
		{
			asteroids[i]->update(time);
		}
	}
}

void Asteroids::render(Uint32 time)
{
	vector<Asteroid*> asteroids = getAllObjects();

	for (int i = 0; i < asteroids.size(); i++)
	{
		if (asteroids[i]->isActive())
		{
			asteroids[i]->render(time);
		}
	}
}
