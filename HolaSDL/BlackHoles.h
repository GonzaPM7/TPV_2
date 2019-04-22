#pragma once
#include "Container.h"
#include "GameObjectPool.h"
#include "BlackHole.h"
#include "RotatingPC.h"
#include "ImageGC.h"
#include "Messages_defs.h"
#include <vector>

class BlackHoles :
	public GameObjectPool<BlackHole, 10>
{
private:
	ImageGC blackHoleImage_;
	RotatingPC rotating_;

	int blackHoleNumber_;

public:
	BlackHoles(SDLGame* game);
	~BlackHoles();
	void createBlackHoles();
	virtual void receive(const void* senderObj, const msg::Message& msg);

};

