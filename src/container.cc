#include <character/character.h>
#include <character/container.h>
#include <stdexcept>
#include <memory>
#include <vector>
#include <iostream>
#include <cstdarg>

CharacterGame::Container::Container(const Container& arr) {
	_size = arr._size;
	_array = std::vector(arr._array);
}
//CharacterGame::Container::Container(int size, ...) {
//	va_list ap;
//	va_start(ap, size);
//	for (int i = 0; i < size; i++) {
//		_array.push_back(std::make_shared<Character>(va_arg(ap, CharacterGame::Character)));
//	}
//}

CharacterGame::Container::Container(Character& pers){
	_size = 1;
	_array.push_back(std::make_shared<Character>(pers));
};

//CharacterGame::Container::Container(int size){
//	if (size < 0)
//		throw std::invalid_argument("Size of array can't be negative");
//	_size = size;
//	for (int i = 0; i < size; i++) {
//		_array.push_back(std::make_shared<Character> Character())
//		_array_o[i] = new Character;
//		*_array_o[i] = Character();
//	}
//}

//CharacterGame::Container::Container(std::initializer_list<std::shared_ptr<Character>> args) {
//	_size = args.size();
//	for (int i = 0; i < _size; i++) {
//			//std::shared_ptr<Assasin> temp(new Character(**(args.begin() + i)));
//			std::shared_ptr<Character> temp(*(args.begin() + i));
//			_array.push_back(temp);
//		}
//	//_array.push_back(std::make_shared<CharacterGame::Character>(*(args.begin() + i)));
//}


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

void CharacterGame::Container::AddElem(std::shared_ptr<Character>& elem) {
	_array.insert(_array.begin()+_size,  elem);
	_size++;
}

void CharacterGame::Container::AddElem(std::shared_ptr<Character>&& elem, int index) {
	if (index > _size || index<0)
		throw std::out_of_range("Invalid index");

	_array.insert(_array.begin() + index, elem);
	_size++;
}

void CharacterGame::Container::DeleteElem(int index) {
	if (index >= _size || index < 0)
		throw std::out_of_range("Invalid index");

	_array.erase(_array.begin() + index);
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


void CharacterGame::Container::swap(Container& arr) {
	std::swap(_size, arr._size);
	std::swap(_array, arr._array);
}

CharacterGame::Container& CharacterGame::Container::operator=(Container arr) {
	this->swap(arr);
	return *this;
}

std::shared_ptr<CharacterGame::Character> CharacterGame::Container::operator()(const int index) const {
	return _array[index];
}