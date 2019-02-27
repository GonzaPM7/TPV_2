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
	}

}
