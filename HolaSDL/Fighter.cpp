#include "Fighter.h"





Fighter::Fighter(SDLGame * game): Container(game)
{
	setWidth(75);
	setHeight(75);
	setPosition(Vector2D(game->getWindowWidth() / 2, game->getWindowHeight() / 2));
	fighterImage_ = ImageGC(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Airplanes), {47, 90, 207, 25});
	naturalMove_ = NaturalMovePC();
	oppositeSide_ = ShowUpAtOpposideSidePC();
	SDL_Event left;
	left.key.keysym.sym = SDLK_LEFT;
	SDL_Event right;
	right.key.keysym.sym = SDLK_LEFT;
	rotation_ = RotationIC(left, right, 5);
	SDL_Event thrust;
	thrust.key.keysym.sym = SDLK_UP;
	thrust_ = ThrustIC(thrust, 0.5, 2.0);
	reduceSpeed_ = ReduceSpeedPC(0.995);
	SDL_Event shoot;
	shoot.key.keysym.sym = SDLK_SPACE;
	normalGun_ = GunIC(shoot);
}

Fighter::~Fighter()
{
}
