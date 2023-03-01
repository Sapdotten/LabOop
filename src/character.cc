#include <character/character.h>
#include <stdexcept>
#include <cstdlib>
#include <ctime>


Character::Character() :type(CharacterType::nobody), HP(0), damage(0), armor(0) {};//конструктор по умолчанию определяет тип перса асасин
Character::Character(CharacterType Ctype) {
	if (Ctype == nobody)
		throw std::invalid_argument("You can't use this type of character");
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
	if (type == nobody)
		throw std::logic_error("You can't use \"nobody\" character");
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
	if (type == nobody)
		throw std::logic_error("You can't use \"nobody\" character");
	if (this->type == berserk && this->_CritChance()) {
			return this->damage * 3;
	}

	return this->damage;
}

int Character::TakeDamage(int damage) {//рассчитывает урон,полученный персонажем
	if (type == nobody)
		throw std::logic_error("You can't use \"nobody\" character");
	int dmg = 0;
	if (this->type == knight && this->_CritChance()) {
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
	if (type == nobody)
		throw std::logic_error("You can't use \"nobody\" character");
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

void Character::_ResetParams() {//сбрасывает параметры после использования скилла
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
	if (type == nobody)
		throw std::logic_error("You can't use \"nobody\" character");
	int dmg = 0;
	switch (act) {
	case 1:
		dmg += opponent.TakeDamage(this->Attack());
		if (this->type == assasin && this->_CritChance()) {
				dmg += opponent.TakeDamage(this->Attack());
			}
		if (this->skillStatus) {
			if (this->type == assasin) {
				dmg += opponent.TakeDamage(this->Attack());
			}
			this->_ResetParams();
		}
		return dmg;
	case 2:
		this->UseSkill();
		return -1;
	}


}

bool Character::_CritChance() {//высчитывает факт выпадения крита
	srand(time(0));
	int inChance = 1 + rand() % 100;
	if (inChance <= this->chance * 100) {
		return true;
	}
	return false;
}
