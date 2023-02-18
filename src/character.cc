#include <character/character.h>


struct Character {
	spesial TypeCharacter;
	int HP = 100;
	int armor = 100;
	int damage = 100;
	double chance = 0.5;

	Character(spesial dreb) {
		this->TypeCharacter = dreb;
		switch (this->TypeCharacter) {
		case knight:
			this->armor = 150;
			break;
		case assasin:
			this->HP = 150;
			break;
		case berserk:
			this->damage = 150;
			break;
		}
	}


};
