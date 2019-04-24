#include "Fighter.h"





Fighter::Fighter(SDLGame * game): Container(game),
	fighterImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Airplanes), {47, 90, 207, 250}),
	naturalMove_(), rotation_(SDLK_LEFT, SDLK_RIGHT, 5), oppositeSide_(), thrust_(SDLK_UP, 0.5, 2.0), reduceSpeed_(0.995), normalGun_(SDLK_SPACE)
{
	setId(msg::Fighter);

	setWidth(75);
	setHeight(75);
	setPosition(Vector2D(game->getWindowWidth() / 2, game->getWindowHeight() / 2));
	addC(&rotation_);
	addC(&thrust_);
	addC(&normalGun_);
	addC(&naturalMove_);
	addC(&oppositeSide_);
	addC(&reduceSpeed_);
	addC(&fighterImage_);
	
	setActive(false);
}

Fighter::~Fighter()
{
}



void Fighter::receive(const void * senderObj, const msg::Message & msg)
{
	Container::receive(senderObj, msg);

	switch(msg.type_)
	{
	case msg::GAME_START:
		onGameStart(msg);
		break;
	case msg::ROUND_START:
		onRoundStart();
		break;
	case msg::ROUND_OVER:
		onRoundOver();
		break;
	}

}

void Fighter::onGameStart(const msg::Message & msg)
{
	// enviar mensaje
	globalSend(this, msg::FighterInfo(msg::Fighter, msg::Broadcast, this));
}

void Fighter::onRoundStart()
{
	setPosition(Vector2D(getGame()->getWindowWidth() / 2, getGame()->getWindowHeight() / 2));
	setVelocity(Vector2D(0, 0));
	setActive(true);
}

void Fighter::onRoundOver()
{
	setActive(false);
}

