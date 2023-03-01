#include <character/character.h>
#include <cstdlib>
#include <ctime>


Character::Character() :type(CharacterType::assasin), HP(1200) {};//конструктор по умолчанию определяет тип перса асасин
Character::Character(CharacterType Ctype) {
	this->type = Ctype;
	switch (this->type) {//в зависимости от типа персонажа распределяет разные значения некоторых параметров
	case knight:
		this->armor = 70;
		break;
	case assasin:
		this->HP = 1200;
		break;
	case berserk:
		this->damage = 150;
		break;
	}
}

void Character::SetChance(double chnc) {//устанавливает шанс для определнного персонажа
	this->chance = chnc;
}

int Character::GetHP() {
	return this->HP;
}
int Character::GetArmor() {
	return this->armor;
}
int Character::getDamage() {
	return this->damage;
}

int Character::Attack() {//высчитывает урон, который должен нанести перс
	if (this->type == berserk) {
		srand(time(0));
		int inChance = 1 + rand() % 100;
		if (inChance <= this->chance * 100) {
			return this->damage * 3;
		}
	}

	return this->damage;
}

int Character::TakeDamage(int damage) {//рассчитывает урон,полученный персонажем
	int dmg = 0;
	if (this->type == knight && this->CritChance()) {
			dmg = (damage - this->armor) / 2;
			this->HP = this->HP - dmg;
			return dmg;
	}
	if (this->type == assasin && this->skillStatus) {
		return 0;
	}
	dmg = damage - this->armor;
	this->HP = this->HP - dmg;
	return dmg;
}

void Character::UseSkill() {//меняет параметры под скилл
	this->skillStatus = true;
	switch (this->type) {
	case knight:
		this->armor += addArmor;
		this->damage -= addDamage;
		break;
	case berserk:
		this->armor -= addArmor;
		this->chance += addChance;
		this->damage += addDamage;
		break;
	}
}

void Character::ResetParams() {//сбрасывает параметры после использования скилла
	switch (this->type) {
	case knight:
		this->armor -=addArmor;
		this->damage += addDamage;
		break;
	case berserk:
		this->armor += addArmor;
		this->chance -= addChance;
		this->damage -= addDamage;
		break;
	}
	this->skillStatus = false;
}

int Character::Action(int act, Character opponent) {//позволяет сделать ход
	int dmg = 0;
	switch (act) {
	case 1:
		dmg += opponent.TakeDamage(this->Attack());
		if (this->type == assasin && this->CritChance()) {
				dmg += opponent.TakeDamage(this->Attack());
			}
		if (this->skillStatus) {
			if (this->type == assasin) {
				dmg += opponent.TakeDamage(this->Attack());
			}
			this->ResetParams();
		}
		return dmg;
	case 2:
		this->UseSkill();
		return -1;
	}


}

bool Character::CritChance() {//высчитывает факт выпадения крита
	srand(time(0));
	int inChance = 1 + rand() % 100;
	if (inChance <= this->chance * 100) {
		return true;
	}
	return false;
}
