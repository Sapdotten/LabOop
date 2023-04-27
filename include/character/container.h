#pragma once
#include <character/character.h>
#include <vector>
#include <memory>
#include <cstdarg>


namespace CharacterGame {
	class Container {
		std::vector<std::shared_ptr<CharacterGame::Character>> _array;
		int _size;
	public:
		Container(const Container& arr);
		Container() : _size(0) {};
		Container(Character& pers);
		Container(std::initializer_list<std::shared_ptr<Character>>&& args) : _array(std::move(args)), _size(args.size()) {};


		Character& operator[](const int index);
		Character operator[](const int index) const;
		std::shared_ptr<Character> operator()(const int index) const;


		int GetSize() const;
		void AddElem(std::shared_ptr<Character>& elem);
		void AddElem(std::shared_ptr<Character>&& elem, int index);
		void DeleteElem(int index);
		int GetMaxDamage();
		Character& GetMinDamage();
		void swap(Container& arr);
		Container& operator=(Container arr);
	};
}