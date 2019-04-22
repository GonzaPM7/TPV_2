#include "BlackHoleBulletCollision.h"
#include "GameManager.h"
#include "Messages_defs.h"
#include "Collisions.h"



BlackHoleBulletCollision::BlackHoleBulletCollision()
{
}


BlackHoleBulletCollision::~BlackHoleBulletCollision()
{
}

void BlackHoleBulletCollision::update(Container * c, Uint32 time)
{
	GameManager* gm = static_cast<GameManager*>(c);

	if (bullets_ != nullptr && blackHoles_ != nullptr) {
		if (gm->isRunning()) {
			for (int i = 0; i < bullets_->size(); i++) {
				for (int j = 0; j < blackHoles_->size(); j++) {
					Bullet* bullet = bullets_->at(i);
					BlackHole* blackhole = blackHoles_->at(j);
					if (bullet->isActive() && blackhole->isActive() && Collisions::collidesWithRotation(bullet, blackhole))
					{
						c->globalSend(this, msg::BlackholeBulletCollisionMsg(msg::None, msg::Broadcast, bullet, blackhole));
					}
				}
			}
		}
	}
}

void BlackHoleBulletCollision::receive(Container * c, const msg::Message & msg)
{
	switch (msg.type_)
	{
	case msg::BLACKHOLES_INFO:
	{
		blackHoles_ = static_cast<const msg::BlackholesInfo&>(msg).blackholes_;
	}
	break;
	case msg::BULLETS_INFO:
		bullets_ = static_cast<const msg::BulletsInfoMsg&>(msg).bullets_;
		break;
	}
}
