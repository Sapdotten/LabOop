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

template <typename T>
void Draw(T arr, int size, int choose, string prestr = "", string poststr = "") {
	cout << prestr;
	for (int i = 0; i < size; i++) {
		if (choose == i)
			cout << ">>>";
		cout << "\t" << arr[i] << endl;
	}
	cout << poststr;

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

int InputType() {
	string types[] = { "berserk", "assasin", "knight" };
	//"berserk" = 0
	//"assasin" = 1 
	//"knight" = 2
	int choose = 0;
	int answ = false;
	while (!answ) {
		system("cls");
		cout << "<Выберите тип вашего персонажа>" << endl;
		Draw(types, 3, choose);
		answ = Input(3, choose);
	}
	return choose;
}

void AddCharacter(Container& arr) {
	int index = 0;
	index = InputIndex(arr.GetSize() + 1);
	if (index != -1) {
		int choose = InputType();
		if (choose == 0) {
			Berserk pers;
			arr.AddElem(make_shared<Berserk>(pers), index);
		}
		else if (choose == 1) {
			Assasin pers;
			arr.AddElem(make_shared<Assasin>(pers), index);
		}
		else if (choose == 2) {
			Knight pers;
			arr.AddElem(make_shared<Knight>(pers), index);
		}
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
	if (index != -1) {
		int choose = InputType();
		switch (choose) {
		case 0:
			arr.ChangeElem(index, make_shared<Berserk>());
			break;
		case 1:
			arr.ChangeElem(index, make_shared<Assasin>()) ;
			break;
		case 2:
			arr.ChangeElem(index, make_shared<Knight>());
			break;

		}
	}
}

int ChooseCharacter(Container& arr) {
	int choose = 0;
	bool flag = false;
	while (!flag) {
		system("cls");
		Draw(arr, arr.GetSize(), choose, "Выберите бойца\n");
		flag = Input(arr.GetSize(), choose);
	}
	return choose;

}
void MakeAMove(Container& players, int turn) {
	string chooses[] = { "Атаковать", "Использовать умение" };
	bool answ = false;
	int choose = 0;
	string skills[] = {
		"\n Берсерк: \n\tурон увеличивается на 20ед \n\tвероятность утроенного удара увеличивается на 0.3 \n\tброня уменьшается на 20 ед",
		"\n Рыцарь: \n\tброня увеличивается на 20ед \n\tурон уменьшается на 20 ед",
		"\n Ассасин: \n\tуворот от атаки"

	};
	while (!answ) {
		system("cls");
		cout << "Ход  игрока: \n";
		Draw(players, 2, turn);
		cout << endl << endl;
		Draw(chooses, 2, choose, "", string("\n\nУмения персонажей:" + skills[0]+skills[1]+skills[2]));
		answ = Input(2, choose);
		if (answ) {
			if (choose + 1 == 2 && players[turn].GetSkillStatus())
				answ = false;
			string result = players[turn].MakeAMove(choose+1, players[1 - turn]);
			system("cls");
			cout << result;
			_getche();
		}
	}
}

void Battle(shared_ptr<Character> p1, shared_ptr<Character> p2) {
	int turn = 0;
	Container players;
	players.AddElem(p1);
	players.AddElem(p2);

	/*Container players = {std::make_shared<Character>(p1), std::make_shared<Character>(p1) };*/
	while (players[0].GetHP() != 0 && players[1].GetHP() != 0) {
		MakeAMove(players, turn);
		turn = 1 - turn;
	}
	system("cls");
	cout << "***Игра окончена***" << endl;
	if (players[0].GetHP() == 0)
		cout << "   Победил игрок 2!";
	else
		cout << "   Победил игрок 1!";
	_getche();

}

void PlayGame(Container& arr) {
	string players[4] = { "Игрок 1 - персонаж не выбран",  "Игрок 2 - персонаж не выбран", "Начать сражение", "Назад" };
	int pers[2] = { -1 , -1};
	bool answer = false;
	int choose = 0;
	while (!answer) {
		system("cls");
		Draw(players, 4, choose, "Выберите игрока, для которого хотите выбрать персонажа, либо начните игру\n");
		answer = Input(4, choose);
		if (answer) {
			if (choose == 2) {//если начать сражение
				if (pers[0] == -1 || pers[1] == -1) {//если не выбраны персонажи
					system("cls");
					cout << "Вы не можете начать игру, пока оба игрока не выберут персонажей";
					_getche();
					system("cls");
					answer = false;
				}
				else {//если персонажи все же выбраны
					system("cls");
					Battle(arr[pers[0]].clone(), arr[pers[1]].clone());
				}
			}
			else if (choose != 3) {
				int chosenChr = ChooseCharacter(arr);
				if (chosenChr == pers[1-choose]) {
					system("cls");
					cout << "Вы не можете выбрать того же персонажа, что и другой игрок";
					_getche();
					system("cls");
				}
				else {
					players[choose].replace(10, 18, "персонаж выбран");
					pers[choose] = chosenChr;	
				}
				answer = false;
				
			}

		}
	}

	
}




int main() {
	setlocale(LC_ALL, "RUS");
	Container array;
	int const size = 7;
	vector<shared_ptr<Character>> arr;
	arr.push_back(make_shared<Assasin>());
	arr.push_back(make_shared<Berserk>());
	arr.push_back(make_shared<Knight>());
	Container fullarr(arr);

	//Container fullarr(ass);
	//fullarr.AddElem(ber);
	//fullarr.AddElem(kni);
	string commands[size] = {
		"Добавить персонажа в массив по индексу",
		"Удалить персонажа из массива по индексу",
		"Вывести персонажей на экран",
		"Вывести пероснажа с максимальным уроном",
		"Заменить персонажа из массива по индексу",
		"Сразиться",
		"Выйти"
	};
	void (*functions[6]) (Container&) = { &AddCharacter , &DeleteCharacter , &PrintContainer , &FindMaxDamage , &ChangeCharacter, &PlayGame };
	int choose = 0;
	bool answ = false;
	while (true) {
		system("cls");
		Draw(commands, size, choose);
		answ = Input(size, choose);
		if (answ) {
			answ = false;
			while (!answ) {
				system("cls");
				if (choose == 6)
					return 0;
				(functions[choose])(fullarr);
				answ = true;
			}

		}
	}




	return 0;
}