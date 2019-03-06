#include "GameManager.h"
#include "Messages_decl.h"

GameManager::GameManager(SDLGame * game): Container(game),
running_(false), gameOver_(true), score_(0), lives_(maxLives_), winner_(0),
gameCtrl_(), scoreView_(), livesViewer_(), gameStatusView_(), fighterAsteroidCollision_(), bulletsAsteroidsCollision_()
{
	setId(msg::GameManagerID);
}

GameManager::~GameManager()
{
}

void GameManager::handleInput(Uint32 time, const SDL_Event & event)
{
	gameCtrl_.handleInput(this, 1, event);
}

void GameManager::update(Uint32 time)
{
	fighterAsteroidCollision_.update(this, 1);
	bulletsAsteroidsCollision_.update(this, 1);
}

void GameManager::render(Uint32 time)
{
	scoreView_.render(this, 1);
	livesViewer_.render(this, 1);
	gameStatusView_.render(this, 1);
}

void GameManager::receive(const void * senderObj, const msg::Message & msg)
{
	Container::receive(senderObj, msg);

	switch (msg.type_)
	{
	}

}
