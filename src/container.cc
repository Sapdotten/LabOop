#include <character/character.h>


Container() : _size(0) {};
Container(int size) : _size(size) {}

Character& Container::operator[](int index) {
	return _array[index];
}

int Container::getSize() {
	return _size;
}

void Container::add(Character& elem, int index) {
	if (index > _size)
		throw

}