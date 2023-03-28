#include <iostream>
#include <character/character.h>
#include <character/container.h>
#include <string>
#include <conio.h>
#include <locale.h>
using namespace std;
using namespace CharacterGame;





void PrintContainer(Container& arr) {
	cout << ">>>\t назад в меню" << endl;
	if (arr.GetSize() == 0)
		cout << "Массив персонажей пуст";
	for (int i = 0; i < arr.GetSize(); ++i) {
		cout << "[" << i << "]\t" << arr[i] << endl;
	}
	while (_getch() != 13);
}

void Draw(string* arr, int size, int choose) {
	for (int i = 0; i < size; i++) {
		if (choose == i)
			cout << ">>>";
		cout << "\t" << arr[i] << endl;
	}

}

bool Input(int len, int& choose) {
	int input = _getch();
	switch (input) {
	case 72:
		if (choose > 0)
			--choose;
		else
			choose = len - 1;
		break;
	case 80:
		if (choose + 1 < len)
			++choose;
		else
			choose = 0;
		break;
	case 13:
		return true;
		break;
	}

	return false;
}

int InputIndex(int size) {
	bool answ = true;
	int index;
	while (answ) {
		cout << "Введите индекс или -1, если хотите выйти: ";
		cin >> index;
		if (cin.fail() || index < -1 || index >= size) {
			std::cin.clear();
			//cin.ignore(100, '\n');
			system("cls");
			cout << "Неверный индекс или ввод!" << endl;
		}
		else {
			//cin.ignore(100, '\n');
			answ = false;
		}
		cin.ignore(100, '\n');
	}
	return index;
}

CharacterType InputType() {
	string types[] = { "berserk", "assasin", "knight" };
	CharacterType ctypes[] = { berserk, assasin, knight };
	int choose = 0;
	int answ = false;
	while (!answ) {
		system("cls");
		cout << "<Выберите тип вашего персонажа>" << endl;
		Draw(types, 3, choose);
		answ = Input(3, choose);
	}
	return ctypes[choose];
}

void AddCharacter(Container& arr) {
	int index = 0;
	index = InputIndex(arr.GetSize() + 1);
	if (index != -1) {
		Character pers(InputType());
		arr.AddElem(pers, index);
	}

}

void DeleteCharacter(Container& arr) {
	int index = InputIndex(arr.GetSize());
	if (index != -1) {
		arr.DeleteElem(index);
	}

}

void FindMaxDamage(Container& arr) {
	int index = arr.GetMaxDamage();
	cout << ">>>\t назад в меню" << endl;
	cout << "[" << index << "]\t" << arr[index] << endl;
	bool flag = false;
	while (!flag)
		flag = Input(1, index);

}

void ChangeCharacter(Container& arr) {
	int index = InputIndex(arr.GetSize());
	if (index != -1)
		arr[index] = Character(InputType());
}

int main() {
	setlocale(LC_ALL, "RUS");
	Container array;
	Container fullarr = { assasin, berserk, knight };
	string commands[] = {
		"Добавить персонажа в массив по индексу",
		"Удалить персонажа из массива по индексу",
		"Вывести персонажей на экран",
		"Вывести пероснажа с максимальным уроном",
		"Заменить персонажа из массива по индексу",
		"Начать сражение"
	};
	void (*functions[6]) (Container&) = { &AddCharacter , &DeleteCharacter , &PrintContainer , &FindMaxDamage , &ChangeCharacter, nullptr };

	int choose = 0;
	bool answ = false;
	while (true) {
		system("cls");
		Draw(commands, 6, choose);
		answ = Input(6, choose);
		if (answ) {
			answ = false;
			while (!answ) {
				system("cls");
				(functions[choose])(fullarr);
				answ = true;
			}

		}
	}




	return 0;
}