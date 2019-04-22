#include "BlackHoleAsteroidCollision.h"
#include "Collisions.h"
#include "GameManager.h"
#include "Messages_defs.h"

BlackHoleAsteroidCollision::BlackHoleAsteroidCollision() {}

BlackHoleAsteroidCollision::~BlackHoleAsteroidCollision() {}

void BlackHoleAsteroidCollision::update(Container *c, Uint32 time) {
  GameManager *gm = static_cast<GameManager *>(c);

  if (asteroids_ != nullptr && blackHoles_ != nullptr) {
    if (gm->isRunning()) {
      for (int i = 0; i < asteroids_->size(); i++) {
        for (int j = 0; j < blackHoles_->size(); j++) {
          Asteroid *asteroid = asteroids_->at(i);
          BlackHole *blackhole = blackHoles_->at(j);
          if (asteroid->isActive() && blackhole->isActive() &&
              Collisions::collidesWithRotation(asteroid, blackhole)) {
            c->globalSend(this,
                          msg::BlackholeAsteroidCollisionMsg(
                              msg::None, msg::Broadcast, asteroid, blackhole));
          }
        }
      }
    }
  }
}

void BlackHoleAsteroidCollision::receive(Container *c,
	const msg::Message &msg) {
	switch (msg.type_) {
	case msg::BLACKHOLES_INFO:
		blackHoles_ = static_cast<const msg::BlackholesInfo &>(msg).blackholes_;
		break;
	case msg::ASTEROIDS_INFO:

		asteroids_ = static_cast<const msg::AsteroidsInfo &>(msg).asteroids_;

		break;
	}
}
