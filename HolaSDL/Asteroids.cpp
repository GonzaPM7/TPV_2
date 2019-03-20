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
		b->addC(&naturalMove_);
		b->addC(&asteroidImage_);
		b->addC(&rotating_);
		b->addC(&showUpAtOpposideSide_);
	}

	createAsteroid();

	setId(msg::AsteroidsID);
	setActive(true);
}


Asteroids::~Asteroids()
{
}


void Asteroids::createAsteroid()
{
	Asteroid *a = getUnusedObject();
	a->setPosition(Vector2D(100, 100));
	a->setVelocity(Vector2D(1.0, 1.0));
	a->setWidth(10.0);
	a->setHeight(10.5);
	a->setActive(true);
}

void Asteroids::receive(const void * senderObj, const msg::Message & msg)
{
	Container::receive(senderObj, msg);

	switch (msg.type_)
	{
	case msg::GAME_START:
		// enviar mensaje
		globalSend(this, msg::AsteroidsInfo(msg::AsteroidsID, msg::Broadcast, &getAllObjects()));
		break;
	case msg::ROUND_START:
		for (int i = 0; i < 10; i++)
		{
			// 0 = left side, 1 = top side, 2 = right side, 3 = bottom side
			int x;
			int y;
			int side = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, 4);
			switch (side)
			{
			case 0:
				x = 0;
				y = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowHeight());
				break;
			case 1:
				x = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowWidth());
				y = 0;
				break;
			case 2:
				x = getGame()->getWindowWidth();
				y = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowHeight());
				break;
			case 3:
				x = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowWidth());
				y = getGame()->getWindowHeight();
				break;
			default:
				break;
			}
			Vector2D p = Vector2D(x, y);
			Vector2D c = Vector2D(getGame()->getWindowWidth() / 2, getGame()->getWindowHeight() / 2);
			Vector2D v = (c - p).normalize() * (getGame()->getServiceLocator()->getRandomGenerator()->nextInt(1, 10) / 20.0);
			Asteroid *a = getUnusedObject();

			a->setWidth(10.0);
			a->setHeight(10.0);
			a->setPosition(p);
			a->setVelocity(v);
			a->setActive(true);
		}
		break;
	case msg::ROUND_OVER:
		deactiveAllObjects();
		setActive(false);
		break;
	case msg::BULLET_ASTEROID_COLLISION:
		Asteroid* x = static_cast<const msg::BulletAsteroidCollision&>(msg).asteroid_; // asteroide destruido
		x->setActive(false); 

		globalSend(this, msg::AsteroidDestroyed(msg::AsteroidsID, msg::Broadcast, 4 - x->getGenerations()));

		if (x->getGenerations() > 1)
		{
			for (int i = 0; i < 2; i++)
			{
				Asteroid *a = getUnusedObject();
				a->setGenerations(x->getGenerations() - 1);
				a->setWidth(x->getWidth()*0.75);
				a->setHeight(x->getHeight()*0.75);
				a->setVelocity(Vector2D(x->getVelocity()*1.1));
				a->setRotation(x->getRotation() + (i+1) * 30);
				a->setPosition(x->getPosition() + a->getVelocity());
				a->setActive(true);
			}
		}

		int remainingAsteroids = 0;
		for (Asteroid* ast : getAllObjects())
		{
			if (ast->isActive())
				remainingAsteroids++;
		}
		if(remainingAsteroids == 0)
			globalSend(this, msg::Message(msg::NO_MORE_ASTEROIDS, msg::AsteroidsID, msg::Broadcast));

		getGame()->getServiceLocator()->getAudios()->playChannel(Resources::Explosion, 0, -1);

		break;

	}
}


