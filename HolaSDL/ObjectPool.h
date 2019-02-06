#pragma once

#include "GameObject.h"


template<typename T, int SIZE>
class ObjectPool : public GameObject {
public:
	ObjectPool(SDLGame* game);
	virtual ~ObjectPool();
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
protected:
	T* getUnusedObject();
private:
	static int const MAX_OBJECTS = SIZE;
	T objects_[MAX_OBJECTS];

};

template<typename T, int SIZE>
inline ObjectPool<T, SIZE>::ObjectPool(SDLGame* game)
{
	for (int i = 0; i < MAX_OBJECTS; i++) {
		objects_[i].setActive(false);
		objects_[i].setGame(game);
	}
}

template<typename T, int SIZE>
inline ObjectPool<T, SIZE>::~ObjectPool()
{
}

template<typename T, int SIZE>
inline void ObjectPool<T, SIZE>::handleInput(Uint32 time, const SDL_Event & event)
{
	for (int i = 0; i < MAX_OBJECTS; i++)
		if (objects_[i].isActive()) {
			objects_[i].handleInput(time, event);
		}
}

template<typename T, int SIZE>
inline void ObjectPool<T, SIZE>::update(Uint32 time)
{
	for (int i = 0; i < MAX_OBJECTS; i++)
		if (objects_[i].isActive()) {
			objects_[i].update(time);
		}
}

template<typename T, int SIZE>
inline void ObjectPool<T, SIZE>::render(Uint32 time)
{
	for (int i = 0; i < MAX_OBJECTS; i++)
		if (objects_[i].isActive()) {
			objects_[i].render(time);
		}
}

template<typename T, int SIZE>
inline T * ObjectPool<T, SIZE>::getUnusedObject()
{
	for (int i = 0; i < MAX_OBJECTS; i++)
		if (!objects_[i].isActive()) {
			return &objects_[i];
		}

	return nullptr;
}
