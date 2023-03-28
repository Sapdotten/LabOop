#pragma once
#include <character/character.h>


namespace CharacterGame {
	class Container {
		int _size;
		Character** _array;
	public:
		Container(const Container& arr);
		Container() : _size(0), _array(nullptr) {};
		Container(int size);
		Container(std::initializer_list<Character> args);


		Character& operator[](const int index);
		Character operator[](const int index) const;


		int GetSize() const;


		void AddElem(Character& elem, int index);
		void DeleteElem(int index);
		int GetMaxDamage();
		Character& GetMinDamage();

		void swap(Container& arr);
		~Container();
		Container& operator=(Container arr);
	};
}