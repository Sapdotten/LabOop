
enum CharacterType {
	knight,
	assasin,
	berserk
};

struct Character {
	CharacterType type;
	int HP=1000;
	int armor=50;
	int damage=100;
	double chance=0.5;
	Character(CharacterType Ctype);
	int GetHP();
	int GetArmor();
	int getDamage();
	void Attack(Character opponent);
	int TakeDamage(int Damage);


};

