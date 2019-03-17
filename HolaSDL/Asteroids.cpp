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

	setId(msg::AsteroidsID);
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
		// Bullet* b = static_cast<msg::BulletAsteroidCollision>(msg).bullet_;
		break;

	}
}


