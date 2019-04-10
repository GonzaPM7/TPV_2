#include "GunIC.h"
#include "Messages_defs.h"
#include "InputHandler.h"
#include "Logger.h"
#include <string.h>
#include <fstream>
#include <iostream>

GunIC::GunIC(SDL_Keycode shootKey)
{
	shootKey_ = shootKey;
}


GunIC::~GunIC()
{
}

void GunIC::handleInput(Container * c, Uint32 time)
{
	if (InputHandler::getInstance()->isAnyKeyDown()) {
		if (InputHandler::getInstance()->isKeyDown(shootKey_)) {
			Vector2D bulletPosition = c->getPosition() + Vector2D(c->getWidth() / 2.0, c->getHeight() / 2.0) + Vector2D(0.0, -(c->getHeight() / 2.0 + 5.0)).rotate(c->getRotation()); 
			Vector2D bulletDirection = Vector2D(0, -1).rotate(c->getRotation());
			int bulletType = 0;
			// enviar mensaje
			c->globalSend(this, msg::Shoot(msg::None, msg::Broadcast, bulletPosition, bulletDirection, bulletType));
			cout << "shooting";
			Logger::instance()->log([bulletPosition, bulletDirection]() {
				stringstream s;
				s << "Shooting: " << bulletPosition << " " << bulletDirection;
				return s.str();
		}
	}
}
