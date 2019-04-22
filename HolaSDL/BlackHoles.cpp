#include "BlackHoles.h"

BlackHoles::BlackHoles(SDLGame *game)
    : GameObjectPool(game),
      blackHoleImage_(getGame()->getServiceLocator()->getTextures()->getTexture(
          Resources::BlackHole)),
      rotating_() {
  for (BlackHole *b : getAllObjects()) {
    b->addC(&blackHoleImage_);
    b->addC(&rotating_);
  }
  setId(msg::BlackHoleID);
  setActive(true);
}

BlackHoles::~BlackHoles() {}

void BlackHoles::createBlackHoles()
{
	for (int i = 0; i < blackHoleNumber_; i++) {
		BlackHole *b = getUnusedObject();
		b->setWidth(50);
		b->setHeight(50);
		int x = getGame()->getWindowWidth() / 2;
		int y = getGame()->getWindowHeight() / 2;

		while (x == getGame()->getWindowWidth() / 2 && y == getGame()->getWindowHeight() / 2)
		{
			x = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(
				0, getGame()->getWindowWidth());
			y = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(
				0, getGame()->getWindowHeight());
		}
		Vector2D p = Vector2D(x, y);
		b->setPosition(p);
		b->setActive(true);
	}
}

void BlackHoles::receive(const void *senderObj, const msg::Message &msg) {
  Container::receive(senderObj, msg);

  switch (msg.type_) {
  case msg::GAME_START:
    blackHoleNumber_ = 1;
    break;
  case msg::ROUND_START:
    blackHoleNumber_ *= 2;
	createBlackHoles();
    break;
  case msg::BULLET_ASTEROID_COLLISION:

    break;
  }
}
