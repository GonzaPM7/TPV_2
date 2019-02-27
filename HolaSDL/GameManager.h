#pragma once

#include "Container.h"
#include "GameCtrlIC.h"
#include "ScoreViewerGC.h"
#include "LivesViewer.h"
#include "GameStatusViewGC.h"
#include "FighterAsteroidCollision.h"
#include "BulletsAsteroidsCollision.h"
#include "Messages_defs.h"


class GameManager: public Container
{
private:
	static int const maxLives_ = 3;
	bool running_;
	bool gameOver_;
	int score_;
	int lives_;
	int winner_;  // 0=none, 1=asteroids, 2=fighter

	// components of GameManager
	GameCtrlIC gameCtrl_;
	ScoreViewerGC scoreView_;
	GameStatusViewGC gameStatusView_;
	LivesViewer livesViewer_;
	FighterAsteroidCollision fighterAsteroidCollision_;
	BulletsAsteroidsCollision bulletsAsteroidsCollision_; 

public:
	GameManager(SDLGame* game);
	virtual ~GameManager();
	bool isRunning() { return running_; }
	bool isGameOver() { return gameOver_; }
	int getScore() { return score_; }
	int getLives() { return lives_; }
	int getWinner() { return winner_; }

	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);

	virtual void receive(const void* senderObj, const msg::Message& msg);
};

