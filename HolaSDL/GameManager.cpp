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
		case msg::GAME_START:
			gameOver_ = false;
			winner_ = 0;
			lives_ = maxLives_;
			break;
		case msg::ROUND_START:
			running_ = true;
			getGame()->getServiceLocator()->getAudios()->playMusic(Resources::ImperialMarch, -1);
			break;
		case msg::ASTEROID_DESTROYED:
		{
			int points = static_cast<const msg::AsteroidDestroyed&>(msg).points_;
			score_ += points;
		}
			break;
		case msg::NO_MORE_ASTEROIDS:
			running_ = false;
			gameOver_ = true;
			winner_ = 1;
			getGame()->getServiceLocator()->getAudios()->haltMusic();
			globalSend(this, msg::Message(msg::ROUND_OVER, msg::GameManagerID, msg::Broadcast));
			globalSend(this, msg::Message(msg::GAME_OVER, msg::GameManagerID, msg::Broadcast));
			break;
		case msg::FIGHTER_ASTEROID_COLLISION:
			getGame()->getServiceLocator()->getAudios()->playChannel(Resources::Explosion, 0, -1);
			getGame()->getServiceLocator()->getAudios()->haltMusic();
			running_ = false;
			lives_--;
			globalSend(this, msg::Message(msg::ROUND_OVER, msg::GameManagerID, msg::Broadcast));

			if (lives_ == 0)
			{
				gameOver_ = true;
				winner_ = 2;
				globalSend(this, msg::Message(msg::GAME_OVER, msg::GameManagerID, msg::Broadcast));
			}
			break;

	}

}
