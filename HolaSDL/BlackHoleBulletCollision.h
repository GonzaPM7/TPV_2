#pragma once
#include "BlackHole.h"
#include "Bullet.h"
#include "Messages_defs.h"
#include "PhysicsComponent.h"

class BlackHoleBulletCollision : public PhysicsComponent {
private:
  const vector<BlackHole *> *blackHoles_ = nullptr;
  const vector<Bullet *> *bullets_ = nullptr;

public:
  BlackHoleBulletCollision();
  ~BlackHoleBulletCollision();
  virtual void update(Container *c, Uint32 time);

  virtual void receive(Container *c, const msg::Message &msg);
};
