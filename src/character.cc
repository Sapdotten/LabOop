#include <character/character.h>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>



CharacterGame::Character::Character(CharacterType Ctype): _chance(0.5), _health(1000), _armor(25), _damage(100), _skill_is_used("Умение уже активно!") {
	this->_type = Ctype;
	switch (this->_type) {//в зависимости от типа персонажа распределяет разные значения некоторых параметров
	case knight:
		this->_armor = 50;
		break;
	case assasin:
		this->_health = 1200;
		break;
	case berserk:
		this->_damage = 120;
		break;
	}
}

CharacterGame::Character::Character() {};

void CharacterGame::Character::SetChance(double chnc) {//устанавливает шанс для определнного персонажа
	/*if (chnc < 0)
		throw std::invalid_argument("Chance can't be negative");*/
	this->_chance = chnc;
}

int CharacterGame::Character::GetHP() const {
	return this->_health;
}
int CharacterGame::Character::GetArmor() const {
	return this->_armor;
}
int CharacterGame::Character::GetDamage() const {
	return this->_damage;
}

int CharacterGame::Character::Damage() {//высчитывает урон, который должен нанести перс
	if (this->_type == berserk && this->_CritChance()) {
			return this->_damage * 3;
	}

	return this->_damage;
}

int CharacterGame::Character::TakeDamage(int damage) {//рассчитывает урон,полученный персонажем
	if (damage < 0)
		throw std::invalid_argument("Damage can't be negative");
	int dmg = 0;
	if (this->_type == knight && this->_CritChance()) {
			dmg = (damage - this->_armor) / 2;
			this->_health = this->_health - dmg;
			if (_health < 0)
				_health = 0;
			return dmg;
	}
	if (this->_type == assasin && this->skillStatus) {
		return 0;
	}
	dmg = damage - this->_armor;
	this->_health = this->_health - dmg;
	if (_health < 0)
		_health = 0;
	return dmg;
}


void CharacterGame::Character::UseSkill() {//меняет параметры под скилл
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

int CharacterGame::Character::Attack(Character& opponent) {
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


void CharacterGame::Character::_ResetParams() {//сбрасывает параметры после использования скилла
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



bool CharacterGame::Character::_CritChance() {//высчитывает факт выпадения крита
	srand(time(0));
	int inChance = 1 + rand() % 100;
	if (inChance <= this->_chance * 100) {
		return true;
	}
	return false;
}

std::string CharacterGame::Character::MakeAMove(int choose, Character& opponent) {
	if (this == &opponent)
		throw std::logic_error("You can't attack yourself");
	int dmg = 0;
	switch (choose) {
	case 1:
		dmg = this->Attack(opponent);
		return "Вы нанесли "+ std::to_string(dmg) + "ед. урона!";
		break;
	case 2:
		if (!this->skillStatus) {
			this->UseSkill();
			return "Умение использовано!";
		}
		else
			return _skill_is_used;
		

		break;
	}
}


CharacterGame::CharacterType CharacterGame::Character::GetType() const {
	return this->_type;
}


std::string CharacterGame::Character::GetStringUsedSkill() {
	return _skill_is_used;
}

std::ostream& CharacterGame::operator<<(std::ostream& out, const CharacterGame::CharacterType& type) {
	switch (type) {
	case assasin:
		out << "assasin";
		return out;
	case berserk:
		out << "berserk";
		return out;
	case knight:
		out << "knight";
		return out;
	}

}

std::ostream& CharacterGame::operator<<(std::ostream& out, const CharacterGame::Character& pers) {
	out <<"type: " << pers._type << "  HP: " << pers._health << "  DMG: " << pers._damage << "  Armor: " << pers._armor;
	return out;
}