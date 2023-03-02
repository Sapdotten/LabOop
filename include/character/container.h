#include <character/character.h>
#pragma once


class Container {
	static const int _SIZE = 10;
	int _size;
	Character _array[_SIZE];

	Container() : _size(0) {};
	Container(int size);

	Character& operator[](int index);
	int getSize();
	void AddElem(Character& elem, int index);
	void DeleteElem(int index);

};