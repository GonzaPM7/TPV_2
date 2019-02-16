#include "Fighter.h"





Fighter::Fighter(SDLGame * game, Vector2D position, double width, double height): Container(game),
	fighterImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Airplanes), {47, 90, 207, 25}),
	naturalMove_(), rotation_(SDLK_LEFT, SDLK_RIGHT, 5), oppositeSide_(), thrust_(SDLK_UP, 0.5, 2.0), reduceSpeed_(0.995), normalGun_(SDLK_SPACE)
{
	setWidth(width);
	setHeight(height);
	setPosition(position);
}

Fighter::~Fighter()
{
}

void Fighter::handleInput(Uint32 time, const SDL_Event & event)
{
	if (event.type == SDL_KEYDOWN) {
		rotation_.handleInput(this, 1, event);
		thrust_.handleInput(this, 1, event);
		normalGun_.handleInput(this, 1, event);
	}
}

void Fighter::update(Uint32 time)
{
	naturalMove_.update(this, 1);
	oppositeSide_.update(this, 1);
	reduceSpeed_.update(this, 1);
}

void Fighter::render(Uint32 time)
{
	fighterImage_.render(this, 1);
}
