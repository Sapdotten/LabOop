#include <character.h>
#pragma once


class Container {
	static const int _SIZE = 10;
	int _size;
	Character _array[_SIZE];

	Container() : _size(0) {};
	Container(int size) : _size(size) {}

	Character& operator[](int index) {
		return _array[index];
	}

	int getSize()

	void add
};