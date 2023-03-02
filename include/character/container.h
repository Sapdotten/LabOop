#pragma once
#include <character/character.h>



class Container {
	static const int _SIZE = 10;
	int _size;
	Character _array[_SIZE];
public:
	Container() : _size(0) {};
	Container(int size);
	Character operator[](int index) const;
	Character& operator[](int index);
	int GetSize() const;
	void AddElem(Character& elem, int index);
	void DeleteElem(int index);
	Character& GetMaxDamage();
};