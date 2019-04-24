#include "Bullets.h"


Bullets::Bullets(SDLGame * game):
	GameObjectPool(game), bulletImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::WhiteRect)),
	naturalMove_(), deactivate_()
{

	for (Bullet* b : getAllObjects())
	{
		b->addC(&bulletImage_);
		b->addC(&naturalMove_);
		b->addC(&deactivate_);
	}

	setId(msg::BulletsID);
	setActive(false);
}

Bullets::~Bullets()
{
}


void Bullets::receive(const void * senderObj, const msg::Message & msg)
{
	Container::receive(senderObj, msg);

	switch (msg.type_)
	{
		case msg::GAME_START:
			onGameStart(msg);
			break;
		case msg::ROUND_START:
			onRoundStart();
			break;
		case msg::ROUND_OVER:
			onRoundOver();
			break;
		case msg::BULLET_ASTEROID_COLLISION:
			destroyBulletWithAsteroid(msg);
			break;
		case msg::BLACKHOLE_BULLET_COLLISION:
			destroyBulletWithBlackhole(msg);
			break;
		case msg::FIGHTER_SHOOT:
			fighterShoot(msg);
			break;
	}

}

void Bullets::onGameStart(const msg::Message & msg)
{
	globalSend(this, msg::BulletsInfoMsg(msg::BulletsID, msg::Broadcast, &getAllObjects()));
}

void Bullets::onRoundStart()
{
	setActive(true);
}

void Bullets::onRoundOver()
{
	deactiveAllObjects();
	setActive(false);
}

void Bullets::destroyBulletWithAsteroid(const msg::Message & msg)
{
	Bullet* x = static_cast<const msg::BulletAsteroidCollision&>(msg).bullet_; // bala destruido
	x->setActive(false);
}

void Bullets::destroyBulletWithBlackhole(const msg::Message & msg)
{
	Bullet* x = static_cast<const msg::BlackholeBulletCollisionMsg&>(msg).bullet_; // bala destruido
	x->setActive(false);
}

void Bullets::fighterShoot(const msg::Message & msg)
{
	msg::Shoot shoot = static_cast<const msg::Shoot&>(msg);

	Bullet *b = getUnusedObject();
	if (b != nullptr)
	{
		b->setWidth(1);
		b->setHeight(5);
		b->setPosition(shoot.pos_ - Vector2D(b->getWidth() / 2, b->getHeight()));
		b->setVelocity(Vector2D(shoot.dir_ * 5));
		b->setRotation(Vector2D(0, -1).angle(shoot.dir_));
		b->setActive(true);

		getGame()->getServiceLocator()->getAudios()->playChannel(Resources::GunShot, 0, -1);
	}
}


