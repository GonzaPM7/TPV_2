#pragma once

template<typename T, int SIZE>
class ObjectPool : public GameObject {
public:

private:
	T* getUnusedObject();
	static int const MAX_OBJECTS = 100;

};