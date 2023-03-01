#pragma once


enum CharacterType {
	nobody,
	knight,
	assasin,
	berserk
};


class Character {
	CharacterType type;
	int HP = 1000;
	int armor = 50;
	int addArmor = 40;
	int damage = 100;
	int addDamage = 30;
	double chance = 0.5;
	double addChance = 0.3;
	
	
	bool skillStatus = false; //отвечает за активность навыка в данный момент, навык работает 1 следующий ход
public:
	Character() :type(CharacterType::assasin), HP(1200) {};
	Character(CharacterType Ctype);
	void SetChance(double chance);

	int GetHP();
	int GetArmor();
	int getDamage();
	int Attack();
	int TakeDamage(int Damage);
	void UseSkill();
	int Action(int act, Character opponent); //1 - атака 2 - использовать умение
private:
	void ResetParams();
	bool CritChance();

};


