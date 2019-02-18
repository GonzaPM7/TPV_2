#pragma once

#include "Container.h"
#include "NaturalMovePC.h"
#include "DeactivateOnBorderExit.h"
#include "ImageGC.h"

class Bullet: public Container
{
private:
	int power_;
	NaturalMovePC naturalMove_;
	DeactivateOnBorderExit deactivate_;
	ImageGC bulletImage_;
public:
	Bullet();
	virtual ~Bullet();
	int getPower();
	void setPower(int power);
	void setComponents(ImageGC bulletImage, NaturalMovePC naturalMove, DeactivateOnBorderExit deactivate);
	void setParameters(Vector2D position, Vector2D velocity, double width, double height);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
};

