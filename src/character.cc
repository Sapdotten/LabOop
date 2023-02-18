#include <character/character.h>
#include <cstdlib>
#include <ctime>


Character::Character(CharacterType Ctype) {
	this->type = Ctype;
	/*switch (this->type) {
	case knight:
		this->armor = 70;
		break;
	case assasin:
		this->HP = 1200;
		break;
	case berserk:
		this->damage = 150;
		break;
	}*/
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

int Character::Attack() {
	if (this->type == berserk) {
		srand(time(0));
		int inChance = 1 + rand() % 100;
		if (inChance <= this->chance * 100) {
			return this->damage * 3;
		}
	}
	return this->damage;
}

int Character::TakeDamage(int damage) {
	int dmg = 0;
	if (this->type == knight) {
		srand(time(0));
		int inChance = 1 + rand() % 100;
		if (inChance <= this->chance * 100) {
			dmg = (damage - this->armor) / 2;
			this->HP = this->HP - dmg;
			return dmg;
		}
	}
	dmg = damage - this->armor;
	this->HP = this->HP - dmg;
	return dmg;
}

void Character::UseSkill() {
	this->skillStatus = true;
	switch (this->type) {
	case knight:
		this->armor += 40;
		this->damage -= 30;
		break;
	case berserk:
		this->armor -= 40;
		this->chance += 0.3;
		this->damage += 50;
		break;
	}
}

void Character::ResetParams(){
	switch (this->type) {
	case knight:
		this->armor +=40;
		this->damage += 30;
		break;
	case berserk:
		this->armor += 40;
		this->chance -= 0.3;
		this->damage -= 50;

		break;
	}
	this->skillStatus = false;
}

