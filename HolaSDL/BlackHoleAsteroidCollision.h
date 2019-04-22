#pragma once
#include "Asteroid.h"
#include "BlackHole.h"
#include "Messages_defs.h"
#include "PhysicsComponent.h"

class BlackHoleAsteroidCollision : public PhysicsComponent {
private:
  const vector<BlackHole *> *blackHoles_ = nullptr;
  const vector<Asteroid *> *asteroids_ = nullptr;

public:
  BlackHoleAsteroidCollision();
  ~BlackHoleAsteroidCollision();
  virtual void update(Container *c, Uint32 time);

  virtual void receive(Container *c, const msg::Message &msg);
};
