#include <character/character.h>
#include <stdexcept>
#include <cstdlib>
#include <ctime>



Character::Character(CharacterType Ctype): _chance(0.5), _health(1000), _armor(70), _damage(100) {
	if (Ctype == nobody)
		throw std::invalid_argument("You can't use this type of character");
	this->_type = Ctype;
	switch (this->_type) {//в зависимости от типа персонажа распределяет разные значения некоторых параметров
	case knight:
		this->_armor = 70;
		break;
	case assasin:
		this->_health = 1200;
		break;
	case berserk:
		this->_damage = 150;
		break;
	}
}

void Character::SetChance(double chnc) {//устанавливает шанс для определнного персонажа
	if (_type == nobody)
		throw std::logic_error("You can't use \"nobody\" character");
	if (chnc < 0)
		throw std::invalid_argument("Chance can't be negative");
	this->_chance = chnc;
}

int Character::GetHP() {
	return this->_health;
}
int Character::GetArmor() {
	return this->_armor;
}
int Character::GetDamage() {
	return this->_damage;
}

int Character::Damage() {//высчитывает урон, который должен нанести перс
	if (_type == nobody)
		throw std::logic_error("You can't use \"nobody\" character");
	if (this->_type == berserk && this->_CritChance()) {
			return this->_damage * 3;
	}

	return this->_damage;
}

int Character::TakeDamage(int damage) {//рассчитывает урон,полученный персонажем
	if (_type == nobody)
		throw std::logic_error("You can't use \"nobody\" character");
	if (damage < 0)
		throw std::invalid_argument("Damage can't be negative");
	int dmg = 0;
	if (this->_type == knight && this->_CritChance()) {
			dmg = (damage - this->_armor) / 2;
			this->_health = this->_health - dmg;
			return dmg;
	}
	if (this->_type == assasin && this->skillStatus) {
		return 0;
	}
	dmg = damage - this->_armor;
	this->_health = this->_health - dmg;
	return dmg;
}

int Character::UseSkill() {//меняет параметры под скилл
	if (_type == nobody)
		throw std::logic_error("You can't use \"nobody\" character");
	this->skillStatus = true;
	switch (this->_type) {
	case knight:
		this->_armor += _ADD_ARMOR;
		this->_damage -= _ADD_DAMAGE;
		break;
	case berserk:
		this->_armor -= _ADD_ARMOR;
		this->_chance += _ADD_CHANCE;
		this->_damage += _ADD_DAMAGE;
		break;
	}
}

int Character::Attack(Character& opponent) {
	if (this->_type == nobody || opponent._type == nobody)
		throw std::logic_error("You can't use \"nobody\" character");
	if (this == &opponent)
		throw std::logic_error("You can't attack yourself");
	int dmg = 0;
	dmg += opponent.TakeDamage(this->Damage());
	if (this->_type == assasin && this->_CritChance()) {
		dmg += opponent.TakeDamage(this->Damage());
		}
	if (this->skillStatus) {
		this->_ResetParams();
	}
	return dmg;
}


void Character::_ResetParams() {//сбрасывает параметры после использования скилла
	switch (this->_type) {
	case knight:
		this->_armor -=_ADD_ARMOR;
		this->_damage += _ADD_DAMAGE;
		break;
	case berserk:
		this->_armor += _ADD_ARMOR;
		this->_chance -= _ADD_CHANCE;
		this->_damage -= _ADD_DAMAGE;
		break;
	}
	this->skillStatus = false;
}



bool Character::_CritChance() {//высчитывает факт выпадения крита
	srand(time(0));
	int inChance = 1 + rand() % 100;
	if (inChance <= this->_chance * 100) {
		return true;
	}
	return false;
}
