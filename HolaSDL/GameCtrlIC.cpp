#include "GameCtrlIC.h"
#include "Messages_defs.h"
#include "GameManager.h"

GameCtrlIC::GameCtrlIC()
{
}


GameCtrlIC::~GameCtrlIC()
{
}

void GameCtrlIC::handleInput(Container * c, Uint32 time)
{
	// enviar mensaje

	GameManager* gm = static_cast<GameManager*>(c);
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == SDLK_RETURN) {
			if (!gm->isRunning())
			{
				if(gm->isGameOver())
					c->globalSend(this, msg::Message(msg::GAME_START, msg::None, msg::Broadcast));
				c->globalSend(this, msg::Message(msg::ROUND_START, msg::None, msg::Broadcast));
			}
		}
	}
}
