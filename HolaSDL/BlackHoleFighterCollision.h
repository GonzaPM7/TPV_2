#pragma once
#include "PhysicsComponent.h"
#include "Fighter.h"
#include "BlackHole.h"
#include "Messages_defs.h"

class BlackHoleFighterCollision :
	public PhysicsComponent
{
private:
	const vector<BlackHole*>* blackHoles_ = nullptr;
	GameObject* fighter_ = nullptr;

public:
	BlackHoleFighterCollision();
	~BlackHoleFighterCollision();
	virtual void update(Container* c, Uint32 time);

	virtual void receive(Container* c, const msg::Message& msg);
};

