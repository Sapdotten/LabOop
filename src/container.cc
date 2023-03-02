#include <character/character.h>
#include <character/container.h>
#include <stdexcept>


Container::Container() : _size(0) {};
Container::Container(int size){
	if (_size > _SIZE || _size < 0)
		throw std::out_of_range("Invalid size");
}

Character& Container::operator[](int index) {
	if (index >= _size)
		throw std::out_of_range("");
	return _array[index];
}

int Container::GetSize() {
	return _size;
}

void Container::AddElem(Character& elem, int index) {
	if (index > _size || _size<0 || _size==_SIZE)
		throw std::out_of_range("Invalid index");
	++_size;
	_array[index] = elem;
}

void Container::DeleteElem(int index) {
	if (index >= _size || index < 0)
		throw std::out_of_range("Invalid index");
		std::memmove(_array + index-1, _array + index, sizeof(Character) * (_size - index));
		--_size;
		_array[_size] = Character();
}