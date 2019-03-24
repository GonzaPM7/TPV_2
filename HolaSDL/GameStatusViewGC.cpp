#include "GameStatusViewGC.h"
#include "GameManager.h"

GameStatusViewGC::GameStatusViewGC()
{
}


GameStatusViewGC::~GameStatusViewGC()
{
}

void GameStatusViewGC::render(Container * c, Uint32 time)
{
	GameManager* gm = static_cast<GameManager*>(c);

	if (!gm->isRunning())
	{
		string winnerText;
		switch (gm->getWinner())
		{
		case 0:
			winnerText = "none";
			break;
		case 1:
			winnerText = "asteroids";
			break;
		case 2:
			winnerText = "fighter";
			break;
		default:
			break;
		}

		Texture winner(c->getGame()->getRenderer(),
			"Game Over: " + winnerText + " wins.",
			*(c->getGame()->getServiceLocator()->getFonts()->getFont(
				Resources::ARIAL24)), { COLOR(0x0022ffff) });
		winner.render(c->getGame()->getRenderer(),
			c->getGame()->getWindowWidth() / 2 - winner.getWidth() / 2, c->getGame()->getWindowHeight() / 2 - 25);

		string instructionMessage;
		string roundMessage = "Press ENTER to Continue";
		string gameMessage = "Press ENTER to Start a New Game";

		if (gm->isGameOver())
			instructionMessage = gameMessage;
		else
			instructionMessage = roundMessage;

		Texture instruction(c->getGame()->getRenderer(),
			instructionMessage,
			*(c->getGame()->getServiceLocator()->getFonts()->getFont(
				Resources::ARIAL24)), { COLOR(0x0022ffff) });
		instruction.render(c->getGame()->getRenderer(),
			c->getGame()->getWindowWidth() / 2 - instruction.getWidth() / 2, c->getGame()->getWindowHeight() / 2 + 25);
	}
}

