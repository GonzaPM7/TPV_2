#pragma once

namespace msg {

enum ObjectId {
	None,  	// special value indicating no object (or more precisely component)
	Broadcast,   // special value indicating all objects
	Ball,
	Fighter,
	Asteroids,
	BulletsShooter,
	FighterGun,

	// 2 extra
	BulletsID,
	GameManagerID,
	BlackHoleID
};

enum MessageType {
	GAME_START,
	GAME_OVER,
	ROUND_START,
	ROUND_OVER,
	FIGHTER_SHOOT,
	BULLET_ASTEROID_COLLISION,
	FIGHTER_ASTEROID_COLLISION,
	BLACKHOLE_FIGHTER_COLLISION,
	BLACKHOLE_ASTEROID_COLLISION,
	BLACKHOLE_BULLET_COLLISION,
	ASTEROID_DESTROYED,
	NO_MORE_FIGHTER_LIVES,
	NO_MORE_ASTEROIDS,
	FIGHTER_INFO,
	BULLETS_INFO,
	ASTEROIDS_INFO,
	BLACKHOLES_INFO
};

struct Message;

};
