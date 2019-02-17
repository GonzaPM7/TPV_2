#include "Asteroids.h"



Asteroids::Asteroids(SDLGame* game) :
	GameObjectPool(game), asteroidImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)),
	naturalMove_(), rotating_(5), showUpAtOpposideSide_()
{
	setWidth(20);
	setHeight(20);
	setVelocity(Vector2D{ 2.0, 2.0 });
	setPosition(Vector2D( 45.0, 45.0));
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
