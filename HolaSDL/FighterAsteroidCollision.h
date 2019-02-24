#pragma once

#include "PhysicsComponent.h"
#include "Asteroid.h"

class FighterAsteroidCollision: public PhysicsComponent
{
private:
	GameObject* fighter_ = nullptr;
	const vector<Asteroid*>* asteroids_ = nullptr;
public:
	FighterAsteroidCollision();
	~FighterAsteroidCollision();
	virtual void update(Container* c, Uint32 time);

};

