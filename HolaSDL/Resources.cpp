#include <tuple>
#include "Resources.h"
#include "sdl_includes.h"

vector<Resources::FontInfo> Resources::fonts_ {
	{ ARIAL16, "resources/fonts/ARIAL.ttf", 16 },
	{ ARIAL24, "resources/fonts/ARIAL.ttf", 24 }
};

vector<Resources::ImageInfo> Resources::images_ {
	{ Blank, "resources/images/blank.png" },
	{ TennisBall, "resources/images/tennis_ball.png" },
	{ KeyBoardIcon, "resources/images/keyboard.png" },
	{ MouseIcon, "resources/images/mouse.png" },
	{ AIIcon,	"resources/images/ai.png" },
	{ SpaceShips, "resources/images/spaceships.png" },
	{ Airplanes, "resources/images/airplanes.png" },
	{ Star,"resources/images/star.png" },
	{ Bird,"resources/images/bird.png" },
	{ FireEgg,"resources/images/fireegg.png" }
};

vector<Resources::TextMsgInfo> Resources::messages_ {
	{ HelloWorld, "Hello World", { COLOR(0xaaffffff) }, ARIAL16 },
	{ PresAnyKey, "Press Any Key ...", {COLOR(0xaaffbbff) }, ARIAL24 },
	{ GameOver, "Game Over", { COLOR( 0xffffbbff) },  ARIAL24 }
};

vector<Resources::MusicInfo> Resources::musics_ {
	{ Beat, "resources/sound/beat.wav" },
	{ Cheer, "resources/sound/cheer.wav" },
	{ Boooo, "resources/sound/boooo.wav" },
	{ GunShot, "resources/sound/GunShot.wav" },
	{ Explosion, "resources/sound/explosion.wav" }

};

vector<Resources::SoundInfo> Resources::sounds_ {
	{ Wall_Hit, "resources/sound/wall_hit.wav" },
	{ Paddle_Hit, "resources/sound/paddle_hit.wav" }
};

