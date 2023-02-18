

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
	bool skillStatus = false; //отвечает за активность навыка в данный момент, навык работает 1 следующий ход
public:
	Character(CharacterType Ctype);
	int GetHP();
	int GetArmor();
	int getDamage();
	int Attack();
	int TakeDamage(int Damage);
	void UseSkill();
	int Action(int act, Character opponent); //1 - атакаб 2 - использовать умение
private:
	void ResetParams();

};

