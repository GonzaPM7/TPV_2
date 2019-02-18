#include "Bullets.h"


Bullets::Bullets(SDLGame * game):
	GameObjectPool(game), bulletImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::WhiteRect)),
	naturalMove_(), deactivate_(), bulletShooter_(SDLK_b)
{
	setWidth(20);
	setHeight(15);
	assignComponentsToBullets(game);
}

Bullets::~Bullets()
{
}

void Bullets::assignComponentsToBullets(SDLGame * game)
{
	vector<Bullet*> bullets = getAllObjects();

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->setComponents(bulletImage_, naturalMove_, deactivate_);
		bullets[i]->setParameters(getPosition(), getVelocity(), getWidth(), getHeight());
	}
}

void Bullets::spawnExampleBullet()
{
	Bullet *b = getUnusedObject();
	b->setActive(true);
	b->setVelocity(Vector2D{ 0, -5 });
	b->setPosition(Vector2D{ 400, 300 });
}

void Bullets::handleInput(Uint32 time, const SDL_Event & event)
{
	if (event.type == SDL_KEYDOWN) {
		if (bulletShooter_.handleInputEvent(this, 1, event))
			spawnExampleBullet();
	}
}

void Bullets::update(Uint32 time)
{
	vector<Bullet*> bullets = getAllObjects();

	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i]->isActive())
			bullets[i]->update(time);
	}
}

void Bullets::render(Uint32 time)
{
	vector<Bullet*> bullets = getAllObjects();

	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i]->isActive())
			bullets[i]->render(time);
	}
}
