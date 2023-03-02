#pragma once


enum CharacterType {
	nobody,
	knight,
	assasin,
	berserk
};


class Character {
	CharacterType _type;
	int _health = 1000;
	int _armor = 50;
	int _damage = 100;
	double _chance = 0.5;
	static const int _ADD_ARMOR = 40,
	_ADD_DAMAGE = 30;

	static constexpr double addChance = 0.3;
	
	
	bool skillStatus = false; //отвечает за активность навыка в данный момент, навык работает 1 следующий ход
public:
	Character() :_type(CharacterType::assasin), _health(1200) {};
	Character(CharacterType Ctype);
	void SetChance(double chance);

	int GetHP();
	int GetArmor();
	int GetDamage();
	int Attack();
	int TakeDamage(int Damage);
	void UseSkill();
	int Action(int act, Character opponent); //1 - атака 2 - использовать умение
private:
	void _ResetParams();
	bool _CritChance();

};


