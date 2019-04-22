#include "BlackHoleFighterCollision.h"
#include "GameManager.h"
#include "Messages_defs.h"
#include "Collisions.h"



BlackHoleFighterCollision::BlackHoleFighterCollision()
{
}


BlackHoleFighterCollision::~BlackHoleFighterCollision()
{
}

void BlackHoleFighterCollision::update(Container * c, Uint32 time)
{
	GameManager* gm = static_cast<GameManager*>(c);

	bool collision = false;

	if (gm->isRunning())
	{
		if (fighter_ != nullptr && blackHoles_ != nullptr)
		{
			auto it = blackHoles_->begin();

			while (it != blackHoles_->end() && !collision)
			{
				if (fighter_->isActive() && (*it)->isActive() && Collisions::collidesWithRotation(fighter_, (*it)))
				{
					// enviar mensaje
					c->globalSend(this, msg::BlackholeFighterCollisionMsg(msg::None, msg::Broadcast, fighter_, (*it)));
					collision = true;
				}
				it++;
			}
		}
	}
}

void BlackHoleFighterCollision::receive(Container * c, const msg::Message & msg)
{
	switch (msg.type_)
	{
	case msg::BLACKHOLES_INFO:
	{
		blackHoles_ = static_cast<const msg::BlackholesInfo&>(msg).blackholes_;
	}
	break;
	case msg::FIGHTER_INFO:
		fighter_ = static_cast<const msg::FighterInfo&>(msg).fighter_;
		break;

	}
}
