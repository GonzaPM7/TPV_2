#include "GunIC.h"
#include "Messages_defs.h"


GunIC::GunIC(SDL_Keycode shootKey)
{
	shootKey_ = shootKey;
}


GunIC::~GunIC()
{
}

void GunIC::handleInput(Container * c, Uint32 time, const SDL_Event & event)
{
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == shootKey_) {
			Vector2D bulletPosition = c->getPosition() + Vector2D(c->getWidth() / 2.0, c->getHeight() / 2.0) + Vector2D(0.0, -(c->getHeight() / 2.0 + 5.0)).rotate(c->getRotation()); 
			Vector2D bulletDirection = Vector2D(0, -1).rotate(c->getRotation());
			int bulletType = 0;
			// enviar mensaje
			msg::Shoot shoot(msg::None, msg::Broadcast, bulletPosition, bulletDirection, bulletType);
			cout << "shooting";
		}
	}
}
