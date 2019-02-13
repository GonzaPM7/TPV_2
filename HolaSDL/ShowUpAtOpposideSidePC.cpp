#include "ShowUpAtOpposideSidePC.h"



ShowUpAtOpposideSidePC::ShowUpAtOpposideSidePC()
{
}


ShowUpAtOpposideSidePC::~ShowUpAtOpposideSidePC()
{
}

void ShowUpAtOpposideSidePC::update(Container * c, Uint32 time)
{
	if (c->getPosition().getX() >= c->getGame()->getWindowWidth()) {
		Vector2D pos(1 - c->getWidth(), c->getPosition().getY());
		c->setPosition(pos);
	}
	else if (c->getPosition().getX() + c->getWidth() <= 0) {
		Vector2D pos(c->getGame()->getWindowWidth(), c->getPosition().getY());
		c->setPosition(pos);
	}
	if (c->getPosition().getY() >= c->getGame()->getWindowHeight()) {
		Vector2D pos(c->getPosition().getX(), 1 - c->getHeight());
		c->setPosition(pos);
	}
	else if (c->getPosition().getY() + c->getHeight() <= 0) {
		Vector2D pos(c->getPosition().getX(), c->getGame()->getWindowHeight());
		c->setPosition(pos);
	}
}
