#pragma once
#include "GraphicsComponent.h"
class LivesViewer: public GraphicsComponent

{
public:
	LivesViewer();
	~LivesViewer();
	virtual void render(Container* c, Uint32 time);

};

