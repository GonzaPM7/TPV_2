#include "EggsShooter.h"

EggsShooter::EggsShooter(SDLGame* game) :
		ObjectPool(game) {
	
}

EggsShooter::~EggsShooter() {
}


void EggsShooter::addEgg(Vector2D pos, Vector2D vel, Vector2D acc) {
	Egg* e = getUnusedObject();
	if (e != nullptr) {
		int h = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, 5);
		e->setWidth(24+h*0.8);
		e->setHeight(30+h);
		e->setVelocity(vel);
		e->setAcceleration(acc);
		e->setPosition(pos);
		e->setActive(true);
		getGame()->getServiceLocator()->getAudios()->playChannel(Resources::Explosion, 0);

	}

}


