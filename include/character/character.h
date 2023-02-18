
enum CharacterType {
	knight,
	assasin,
	berserk
};

class Character {
	CharacterType type;
	int HP = 1000;
	int armor = 50;
	int damage = 100;
	double chance = 0.5;
public:
	Character(CharacterType Ctype);
	int GetHP();
	int GetArmor();
	int getDamage();
	int Attack();
private:
	void TakeDamage(int Damage);

};

