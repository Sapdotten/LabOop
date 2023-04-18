#include <character/character.h>
#include <character/container.h>
#include <stdexcept>


CharacterGame::Container::Container(const Container& arr) {
	_size = arr._size;
	_array = new Character * [_size];
	for (int i = 0; i < _size; i++) {
		_array[i] = new Character;
		*_array[i] = arr[i];
	}
}

CharacterGame::Container::Container(int size){
	if (size < 0)
		throw std::invalid_argument("Size of array can't be negative");
	_size = size;
	_array = new Character*[size];
	for (int i = 0; i < size; i++) {
		_array[i] = new Character;
		*_array[i] = Character();
	}
}

CharacterGame::Container::Container(std::initializer_list<Character> args) {
	_size = args.size();
	_array = new Character * [_size];
	for (int i = 0; i < _size; i++) {
		_array[i] = new Character;
		*_array[i] = *(args.begin()+i);
	}
}

CharacterGame::Character CharacterGame::Container::operator[](const int index) const{
	if (index >= _size)
		throw std::out_of_range("");
	return *_array[index];
}

CharacterGame::Character& CharacterGame::Container::operator[](const int index) {
	if (index >= _size || index<0)
		throw std::out_of_range("");
	return *_array[index];
}

int CharacterGame::Container::GetSize() const{
	return _size;
}

void CharacterGame::Container::AddElem(Character& elem, int index) {
	if (index > _size || index<0)
		throw std::out_of_range("Invalid index");

	Character** ptr = new Character * [_size + 1];
	for (int i = 0; i <= _size; i++) {
		ptr[i] = new Character;
	}
	
	memcpy(ptr, _array, sizeof(Character*)*index);
	*ptr[index] = elem;
	memcpy(ptr + index + 1, _array + index, sizeof(Character*) * (_size - index));
	++_size;
	
	delete[] _array;
	_array = ptr;
	ptr = nullptr;
}

void CharacterGame::Container::DeleteElem(int index) {
	if (index >= _size || index < 0)
		throw std::out_of_range("Invalid index");
	Character** ptr = new Character*[_size - 1];
	for (int i = 0; i < _size - 1; i++) {
		ptr[i] = new Character;
	}
	memcpy(ptr, _array, sizeof(Character*)*index);
	memcpy(ptr+index, _array+index + 1, sizeof(Character*) * (_size - index - 1));
	delete _array[index];
	delete[] _array;
	_array = ptr;
	ptr = nullptr;
	--_size;
}

int CharacterGame::Container::GetMaxDamage() {
	if (_size == 0)
		throw std::invalid_argument("");
	int maxElem = 0;
	for (int i = 0; i < _size; ++i) {
		if ((*this)[i].GetDamage() > (*this)[maxElem].GetDamage()) {
			maxElem = i;
		}
	}
	return maxElem;
}

CharacterGame::Character& CharacterGame::Container::GetMinDamage() {
	if (_size == 0)
		throw std::invalid_argument("");
	int minElem = 0;
	for (int i = 0; i < _size; ++i) {
		if ((*this)[i].GetDamage() < (*this)[minElem].GetDamage()) {
			minElem = i;
		}
	}
	return (*this)[minElem];
}

CharacterGame::Container::~Container() {
	for (int i = 0; i < _size; i++) {
		delete _array[i];
	}
	delete[] _array;
}

void CharacterGame::Container::swap(Container& arr) {
	std::swap(_size, arr._size);
	std::swap(_array, arr._array);
}

CharacterGame::Container& CharacterGame::Container::operator=(Container arr) {
	this->swap(arr);
	return *this;


}