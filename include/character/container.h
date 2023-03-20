#pragma once
#include <character/character.h>


namespace CharacterGame {
	class Container {
		int _size;
		Character** _array;
	public:
		Container() : _array(nullptr) {};
		Container(int size);
		Container(std::initializer_list<Character> args);
		/*Character operator[](int index) const;*/
		Character& operator[](int index);
		int GetSize() const;
		void AddElem(Character& elem, int index);
		void DeleteElem(int index);
		Character& GetMaxDamage();
		Character& GetMinDamage();
	};
}