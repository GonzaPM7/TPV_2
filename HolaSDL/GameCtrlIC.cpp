#include "GameCtrlIC.h"
#include "Messages_defs.h"
#include "GameManager.h"

GameCtrlIC::GameCtrlIC()
{
}


GameCtrlIC::~GameCtrlIC()
{
}

void GameCtrlIC::handleInput(Container * c, Uint32 time, const SDL_Event & event)
{
	// enviar mensaje

	GameManager* gm = static_cast<GameManager*>(c);
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == SDLK_RETURN) {
			if (!gm->isRunning())
			{
				if(gm->isGameOver())
					msg::Message gameStart(msg::GAME_START, msg::None, msg::Broadcast);
				msg::Message roundStart(msg::ROUND_START, msg::None, msg::Broadcast);
			}
		}
	}
}
