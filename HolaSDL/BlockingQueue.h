#pragma once

#include <queue>
#include "sdl_includes.h"
#include <iostream>

using namespace std;
/*
 *
 */
template<typename T>
class BlockingQueue {
	queue<T> queue_;
	SDL_cond *cond;
	SDL_mutex *mutex;
public:
	BlockingQueue() :
			queue_() {

		mutex = SDL_CreateMutex();
		cond = SDL_CreateCond();
	}

	virtual ~BlockingQueue() {
		SDL_DestroyMutex(mutex);
		SDL_DestroyCond(cond);
	}

	T dequeue() {
		SDL_LockMutex(mutex);
		while (queue_.size() == 0) {
			SDL_CondWait(cond, mutex);
		}
		T v = queue_.front();
		queue_.pop();
		SDL_UnlockMutex(mutex);
		return v;
	}

	void enqueue(T& e) {
		SDL_LockMutex(mutex);
		if (queue_.size() == 0) {
			SDL_CondSignal(cond);
		}
		queue_.push(e);
		SDL_UnlockMutex(mutex);
	}

	int size() {
		return queue_.size();
	}

};

