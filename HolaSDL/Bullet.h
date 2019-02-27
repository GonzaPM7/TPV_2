#pragma once

#include "Container.h"
#include "NaturalMovePC.h"
#include "DeactivateOnBorderExit.h"
#include "ImageGC.h"
#include "Messages_defs.h"


class Bullet: public Container
{
private:
	int power_;
public:
	Bullet();
	virtual ~Bullet();
	int getPower();
	void setPower(int power);

	virtual void receive(const void* senderObj, const msg::Message& msg);
};

