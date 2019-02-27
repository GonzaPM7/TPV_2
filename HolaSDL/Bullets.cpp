#include "Bullets.h"


Bullets::Bullets(SDLGame * game):
	GameObjectPool(game), bulletImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::WhiteRect)),
	naturalMove_(), deactivate_(), bulletShooter_(SDLK_b)
{
	setWidth(20);
	setHeight(15);

	for (Bullet* b : getAllObjects())
	{
		b->addC(&bulletImage_);
		b->addC(&naturalMove_);
		b->addC(&deactivate_);
	}

	setActive(false);
}

Bullets::~Bullets()
{
}


void Bullets::spawnBullet()
{
	/*Bullet *b = getUnusedObject();
	b->setPosition(position);
	b->setVelocity(velocity);
	b->setWidth(getWidth());
	b->setHeight(getHeight());
	b->setActive(true);*/
}


