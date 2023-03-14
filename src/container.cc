#include <character/character.h>
#include <character/container.h>
#include <stdexcept>


Container::Container(int size){
	if (size > _SIZE || size < 0)
		throw std::out_of_range("Invalid size");
	_size = size;
}

//Character Container::operator[](int index) const{
//	if (index >= _size)
//		throw std::out_of_range("");
//	return _array[index];
//}

Character& Container::operator[](int index) {
	if (index >= _size || index<0)
		throw std::out_of_range("");
	return _array[index];
}

int Container::GetSize() const{
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

Character& Container::GetMaxDamage() {
	if (_size == 0)
		throw std::invalid_argument("");
	int maxElem = 0;
	for (int i = 0; i < _size; ++i) {
		if ((*this)[i].GetDamage() > (*this)[maxElem].GetDamage()) {
			maxElem = i;
		}
	}
	return (*this)[maxElem];
}

Character& Container::GetMinDamage() {
	if (_size == 0)
		throw std::invalid_argument("");
	int minElem = 0;
	for (int i = 0; i < _size; ++i) {
		if ((*this)[i].GetDamage() < (*this)[minElem].GetDamage() && !(*this)[i].GetType()==nobody) {
			minElem = i;
		}
	}
	return (*this)[minElem];
}


