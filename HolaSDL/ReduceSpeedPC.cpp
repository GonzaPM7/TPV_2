#include "ReduceSpeedPC.h"



ReduceSpeedPC::ReduceSpeedPC(double factor)
{
	factor_ = factor;
}


ReduceSpeedPC::~ReduceSpeedPC()
{
}

void ReduceSpeedPC::update(Container * c, Uint32 time)
{
	c->setVelocity(c->getVelocity()*factor_);
}
