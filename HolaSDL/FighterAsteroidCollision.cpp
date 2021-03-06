#include "FighterAsteroidCollision.h"
#include "GameManager.h"
#include "Collisions.h"
#include "Messages_defs.h"

FighterAsteroidCollision::FighterAsteroidCollision()
{
}


FighterAsteroidCollision::~FighterAsteroidCollision()
{
}

void FighterAsteroidCollision::update(Container * c, Uint32 time)
{
	GameManager* gm = static_cast<GameManager*>(c);

	bool collision = false;

	if (gm->isRunning())
	{
		if (fighter_ != nullptr && asteroids_ != nullptr)
		{
			auto it = asteroids_->begin();

			while (it != asteroids_->end() && !collision)
			{
				if (fighter_->isActive() && (*it)->isActive() && Collisions::collidesWithRotation(fighter_, (*it)))
				{
					// enviar mensaje
					c->globalSend(this, msg::FighterAsteroidCollisionMsg(msg::None, msg::Broadcast, fighter_, (*it)));
					collision = true;
				}
				it++;
			}
		}
	}
}

void FighterAsteroidCollision::receive(Container * c, const msg::Message & msg)
{
	switch (msg.type_)
	{
		case msg::ASTEROIDS_INFO:
		{
			asteroids_ = static_cast<const msg::AsteroidsInfo&>(msg).asteroids_;
		}
			break;
		case msg::FIGHTER_INFO:
			fighter_ = static_cast<const msg::FighterInfo&>(msg).fighter_;
			break;

	}
}
