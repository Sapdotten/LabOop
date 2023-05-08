#include <character/character.h>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>




void CharacterGame::Character::SetChance(double chnc) {//устанавливает шанс для определнного персонажа
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
bool CharacterGame::Character::GetSkillStatus() const {
	return _skillStatus;
}

std::string CharacterGame::Character::GetType() const {
	return "Character";
}
std::string CharacterGame::Assasin::GetType() const {
	return "Assasin";
}
std::string CharacterGame::Berserk::GetType() const {
	return "Berserk";
}
std::string CharacterGame::Knight::GetType() const {
	return "Knight";
}


int CharacterGame::Character::Damage() {
	return _damage;
}
int CharacterGame::Berserk::Damage() {//высчитывает урон, который должен нанести перс
	if (this->_CritChance()) return this->_damage * 3;
	return this->_damage;
}

int CharacterGame::Character::TakeDamage(int damage) {
	if (damage < 0)
		throw std::invalid_argument("Damage can't be negative");
	int dmg = damage - this->_armor;
	this->_health = this->_health - dmg;
	if (_health < 0)
		_health = 0;
	return dmg;
}
int CharacterGame::Assasin::TakeDamage(int damage) {//рассчитывает урон,полученный персонажем
	if (damage < 0)
		throw std::invalid_argument("Damage can't be negative");
	if (this->_skillStatus) {
		return 0;
	}
	int dmg = damage - this->_armor;
	this->_health = this->_health - dmg;
	if (_health < 0)
		_health = 0;
	return dmg;
}
int CharacterGame::Knight::TakeDamage(int damage) {//рассчитывает урон,полученный персонажем
	if (damage < 0)
		throw std::invalid_argument("Damage can't be negative");
	int dmg = 0;
	if (this->_CritChance()) {
		dmg = (damage - this->_armor) / 2;
	}
	else {
		dmg = damage - this->_armor;
	}
	this->_health = this->_health - dmg;
	if (_health < 0)
		_health = 0;
	return dmg;
}


void CharacterGame::Character::UseSkill() {//меняет параметры под скилл
	this->_skillStatus = true;
}
void CharacterGame::Knight::UseSkill() {//меняет параметры под скилл
	this->_skillStatus = true;
	this->_armor += _D_ARMOR;
	this->_damage -= _D_DAMAGE;

}
void CharacterGame::Berserk::UseSkill() {//меняет параметры под скилл
	this->_skillStatus = true;
	this->_armor -= _D_ARMOR;
	this->_chance += _D_CHANCE;
	this->_damage += _D_DAMAGE;
}

int CharacterGame::Character::Attack(Character& opponent) {
	if (this == &opponent)
		throw std::logic_error("You can't attack yourself");
	int dmg = 0;
	dmg += opponent.TakeDamage(this->Damage());
	if (this->_skillStatus) {
		this->_ResetParams();
	}
	return dmg;
}
int CharacterGame::Assasin::Attack(Character& opponent) {
	if (this == &opponent)
		throw std::logic_error("You can't attack yourself");
	int dmg = 0;
	dmg += opponent.TakeDamage(this->Damage());
	if (this->_CritChance()) {
		dmg += opponent.TakeDamage(this->Damage());
	}
	if (this->_skillStatus) {
		this->_ResetParams();
	}
	return dmg;
}


void CharacterGame::Character::_ResetParams() {//сбрасывает параметры после использования скилла
	this->_skillStatus = false;
}
void CharacterGame::Knight::_ResetParams() {//сбрасывает параметры после использования скилла
	this->_armor -= _D_ARMOR;
	this->_damage += _D_DAMAGE;
	this->_skillStatus = false;
}
void CharacterGame::Berserk::_ResetParams() {//сбрасывает параметры после использования скилла
	this->_armor += _D_ARMOR;
	this->_chance -= _D_CHANCE;
	this->_damage -= _D_DAMAGE;
	this->_skillStatus = false;
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
		if (!this->_skillStatus) {
			this->UseSkill();
			return "Умение использовано!";
		}
		else
			return _skill_is_used;
		break;
	}
}





std::string CharacterGame::Character::GetStringUsedSkill() const{
	return _skill_is_used;
}


void CharacterGame::Character::Print(std::ostream& out) const{
	out <<"type: " << this->GetType() << "  HP: " << this->_health << "  DMG: " << this->_damage << "  Armor: " << this->_armor;
}
//void CharacterGame::Assasin::Print(std::ostream& out) const {
//	out << "type: " << "Assasin" << "  HP: " << this->_health << "  DMG: " << this->_damage << "  Armor: " << this->_armor;
//}
//void CharacterGame::Berserk::Print(std::ostream& out) const {
//	out << "type: " << "Berserk" << "  HP: " << this->_health << "  DMG: " << this->_damage << "  Armor: " << this->_armor;
//}
//void CharacterGame::Knight::Print(std::ostream& out) const {
//	out << "type: " << "Knight" << "  HP: " << this->_health << "  DMG: " << this->_damage << "  Armor: " << this->_armor;
//}


std::ostream& CharacterGame::operator<<(std::ostream& out, const CharacterGame::Character& pers){
	pers.Print(out);
	return out;
}

std::unique_ptr<CharacterGame::Character> CharacterGame::Character::clone() const {
	return std::make_unique<CharacterGame::Character>(*this);
};

std::unique_ptr<CharacterGame::Character> CharacterGame::Assasin::clone() const {
	return std::make_unique<CharacterGame::Assasin>(*this);
};

std::unique_ptr<CharacterGame::Character> CharacterGame::Berserk::clone() const {
	return std::make_unique<CharacterGame::Berserk>(*this);
};

std::unique_ptr<CharacterGame::Character> CharacterGame::Knight::clone() const {
	return std::make_unique<CharacterGame::Knight>(*this);
};
//"type: " << this->GetType() << "  HP: " << this->_health << "  DMG: " << this->_damage << "  Armor: " << this->_armor;
