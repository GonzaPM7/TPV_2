#include "BulletsAsteroidsCollision.h"
#include "GameManager.h"
#include "Messages_defs.h"
#include "Collisions.h"

BulletsAsteroidsCollision::BulletsAsteroidsCollision()
{
}


BulletsAsteroidsCollision::~BulletsAsteroidsCollision()
{
}

void BulletsAsteroidsCollision::update(Container * c, Uint32 time)
{
	GameManager* gm = static_cast<GameManager*>(c);

	bool collision = false;

	if (gm->isRunning())
	{
		if (bullets_ != nullptr && asteroids_ != nullptr)
		{
			auto asteroidIt = asteroids_->begin();
			auto bulletIt = bullets_->begin();

			while (asteroidIt != asteroids_->end() && !collision)
			{
				while (bulletIt != bullets_->end() && !collision)
				{
					if ((*bulletIt)->isActive() && (*asteroidIt)->isActive() && Collisions::collidesWithRotation((*bulletIt), (*asteroidIt)))
					{
						// enviar mensaje
						msg::BulletAsteroidCollision(msg::None, msg::Broadcast, (*bulletIt), (*asteroidIt));
						collision = true;
					}
					bulletIt++;
				}
				
				asteroidIt++;
			}
		}
	}
}
