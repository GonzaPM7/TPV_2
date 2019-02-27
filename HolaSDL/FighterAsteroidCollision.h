#pragma once

#include "PhysicsComponent.h"
#include "Asteroid.h"
#include "Messages_defs.h"


class FighterAsteroidCollision: public PhysicsComponent
{
private:
	GameObject* fighter_ = nullptr;
	const vector<Asteroid*>* asteroids_ = nullptr;
public:
	FighterAsteroidCollision();
	~FighterAsteroidCollision();
	virtual void update(Container* c, Uint32 time);

	virtual void receive(Container* c, const msg::Message& msg);
};

