#pragma once

#include "BlackHoleAsteroidCollision.h"
#include "BlackHoleBulletCollision.h"
#include "BlackHoleFighterCollision.h"
#include "BulletsAsteroidsCollision.h"
#include "Container.h"
#include "FighterAsteroidCollision.h"
#include "GameCtrlIC.h"
#include "GameStatusViewGC.h"
#include "LivesViewer.h"
#include "Messages_defs.h"
#include "ScoreViewerGC.h"

class GameManager : public Container {
private:
  static int const maxLives_ = 3;
  bool running_;
  bool gameOver_;
  int score_;
  int lives_;
  int winner_; // 0=none, 1=asteroids, 2=fighter

  // components of GameManager
  GameCtrlIC gameCtrl_;
  ScoreViewerGC scoreView_;
  GameStatusViewGC gameStatusView_;
  LivesViewer livesViewer_;
  FighterAsteroidCollision fighterAsteroidCollision_;
  BulletsAsteroidsCollision bulletsAsteroidsCollision_;
  BlackHoleAsteroidCollision blackholeAsteroidsCollision_;
  BlackHoleBulletCollision blackholeBulletsCollision_;
  BlackHoleFighterCollision blackholeFighterCollision_;

public:
  GameManager(SDLGame *game);
  virtual ~GameManager();
  bool isRunning() { return running_; }
  bool isGameOver() { return gameOver_; }
  int getScore() { return score_; }
  int getLives() { return lives_; }
  int getWinner() { return winner_; }

  virtual void receive(const void *senderObj, const msg::Message &msg);

  void fighterDeath();
};
