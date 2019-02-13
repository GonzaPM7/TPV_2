#include "Fighter.h"





Fighter::Fighter(SDLGame * game): Container(game)
{
	fighterImage_.setTexture(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Airplanes));
	clip_ = { 47, 90, 207, 250 };
	rotation_ = 90;
}

Fighter::~Fighter()
{
}
