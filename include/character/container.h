#pragma once
#include <character/character.h>
#include <vector>
#include <memory>
#include <cstdarg>


namespace CharacterGame {
	class Container {
		std::vector<std::shared_ptr<CharacterGame::Character>> _array;
	public:
		Container(const Container& arr);
		Container() :_array(0) {};
		Container(std::vector<std::shared_ptr<Character>> arr);


		Character& operator[](const int index);
		Character operator[](const int index) const;
		std::shared_ptr<Character> operator()(const int index) const;


		int GetSize() const;
		void AddElem(std::shared_ptr<Character> elem);
		void AddElem(std::shared_ptr<Character> elem, int index);
		void ChangeElem(const int index, std::shared_ptr<Character> elem);
		void DeleteElem(int index);
		int GetMaxDamage();
		int GetMinDamage();
		void swap(Container& arr);
		Container& operator=(Container arr);
	};
}