#pragma once

#include "Container.h"
#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "RotatingPC.h"
#include "ShowUpAtOpposideSidePC.h"
#include "Messages_defs.h"



class Asteroid: public Container
{
private:
	int generations_;
public:
	Asteroid();
	~Asteroid();
	int getGenerations();
	void setGenerations(int generations);

	virtual void receive(const void* senderObj, const msg::Message& msg);
};

