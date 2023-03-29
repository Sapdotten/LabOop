#pragma once
#include <string>


namespace CharacterGame {



	enum CharacterType {
		nobody = 0,
		knight = 1,
		assasin = 2,
		berserk = 3
	};


	class Character {
		CharacterType _type;
		int _health;
		int _armor;
		int _damage;
		double _chance;
		std::string _skill_is_used;

		static const int _ADD_ARMOR = 20,
			_ADD_DAMAGE = 20;
		static constexpr double _ADD_CHANCE = 0.3;


		bool skillStatus = false; //отвечает за активность навыка в данный момент, навык работает 1 следующий ход
	public:
		friend std::ostream& operator<<(std::ostream& out, const CharacterType& type);
		friend std::ostream& operator<<(std::ostream& out, const Character& pers);

		std::string GetStringUsedSkill();
		Character() :_type(CharacterType::nobody), _health(0), _damage(0), _armor(0), _chance(0) {};
		Character(CharacterType Ctype);
		void SetChance(double chance);

		CharacterType GetType() const;
		int GetHP() const;
		int GetArmor() const;
		int GetDamage() const;
		int Damage();
		int TakeDamage(int Damage);
		int Attack(Character& opponent);
		int UseSkill();
		std::string MakeAMove(int choose, Character& opponent);
		
	private:
		void _ResetParams();
		bool _CritChance();
		

	};

	
}


