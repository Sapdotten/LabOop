#include <character/character.h>
#include <cstdlib>
#include <ctime>


Character::Character(CharacterType Ctype) {
		this->type = Ctype;
		switch (this->type) {
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

int Character::GetHP() {
	return this->HP;
}

int Character::GetArmor() {
	return this->armor;
}

int Character::getDamage() {
	return this->damage;
}

void Character::Attack(Character opponent) {
	if (this->type == berserk) {
		srand(time(0));
		int inChance = 1 + rand() % 100;
		if (inChance <= this->chance * 100) {
			opponent.TakeDamage(this->damage * 3);
		}
	}
	else
	opponent.TakeDamage(this->damage);
}

int Character::TakeDamage(int damage) {
	int dmg = 0;
	if (this->type == knight) {
		srand(time(0));
		int inChance = 1 + rand() % 100;
		if (inChance <= this->chance * 100) {
			dmg = (damage - this->armor) / 2;
			this->HP = HP - dmg;
			if (this->HP < 0)
				this->HP = 0;
		}
	}
	else {
		dmg = damage - this->armor;
		this->HP = HP-dmg;
		if (this->HP < 0)
			this->HP = 0;
	}
		
}

