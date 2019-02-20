#include "ScoreViewerGC.h"
#include "GameManager.h"

ScoreViewerGC::ScoreViewerGC()
{
}


ScoreViewerGC::~ScoreViewerGC()
{
}

void ScoreViewerGC::render(Container * c, Uint32 time)
{
	GameManager* gm = static_cast<GameManager*>(c);

	Texture score(c->getGame()->getRenderer(),
		"Score: " + std::to_string(gm->getScore()),
		*(c->getGame()->getServiceLocator()->getFonts()->getFont(
			Resources::ARIAL24)), { COLOR(0x0022ffff) });
	score.render(c->getGame()->getRenderer(),
		c->getGame()->getWindowWidth() / 2 - score.getWidth() / 2, 25);
}
