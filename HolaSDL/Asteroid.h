#pragma once

#include "Container.h"
#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "RotatingPC.h"
#include "ShowUpAtOpposideSidePC.h"


class Asteroid: public Container
{
private:
	int generations_;
	ImageGC asteroidImage_;
	NaturalMovePC naturalMove_;
	RotatingPC rotating_;
	ShowUpAtOpposideSidePC showUpAtOpposideSide_;
public:
	Asteroid();
	~Asteroid();
	int getGenerations();
	void setGenerations(int generations);
	void setComponents(ImageGC asteroidImage, NaturalMovePC naturalMove, RotatingPC rotating, ShowUpAtOpposideSidePC showUpAtOpposideSide);
	void setParameters(Vector2D position, Vector2D velocity, double width, double height);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
};

