#include "Fighter.h"





Fighter::Fighter(SDLGame * game): Container(game)
{
	setWidth(75);
	setHeight(75);
	setPosition(Vector2D(game->getWindowWidth() / 2, game->getWindowHeight() / 2));
	fighterImage_ = ImageGC(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Airplanes), {47, 90, 207, 25});
	naturalMove_ = NaturalMovePC();
	oppositeSide_ = ShowUpAtOpposideSidePC();
}

Fighter::~Fighter()
{
}
