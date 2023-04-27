#pragma once
#include <string>
#include <memory>


namespace CharacterGame {

	class Character {
	protected:
		std::string _type;
		int _health;
		int _armor;
		int _damage;
		double _chance;
		std::string _skill_is_used = "Умение уже активно!";

		static const int _D_ARMOR = 20,
			_D_DAMAGE = 20;
		static constexpr double _D_CHANCE = 0.3;
		Character(int health, int armor, int damage) :_type("No type"),_health(health), _armor(armor), _damage(damage), _chance(0.5) {};

		bool _skillStatus = false; //отвечает за активность навыка в данный момент, навык работает 1 следующий ход
	public:
		friend std::ostream& operator<<(std::ostream& out, const Character& pers);
		virtual void Print(std::ostream& out) const;
		Character() : _health(0), _armor(0), _damage(0), _chance(0.5) {};

		std::string GetStringUsedSkill();
		void SetChance(double chance);

		bool GetSkillStatus() const;
		std::string GetType() const;
		int GetHP() const;
		int GetArmor() const;
		int GetDamage() const;
		double GetChance() const {
			return _chance;
		}
		virtual int Damage();
		virtual int TakeDamage(int Damage);
		virtual int Attack(Character& opponent);
		virtual void UseSkill();
		std::string MakeAMove(int choose, Character& opponent);
		std::unique_ptr<Character> clone() const;
	protected:
		virtual void _ResetParams();
		bool _CritChance();
		

	};
	
	class Knight : public Character {
	public:
		Knight() :Character(1000, 50, 100) { 
			_type = "Knight"; 
		};
		int TakeDamage(int Damage) override;
		void UseSkill() override;
		void _ResetParams() override;
		void Print(std::ostream& out) const override;
	};

	class Assasin : public Character {
	public:
		Assasin() : Character(1200, 25, 100) { _type = "Assasin"; };
		friend std::ostream& operator<<(std::ostream& out, const Assasin& pers);
		int TakeDamage(int Damage) override;
		int Attack(Character& opponent) override;
		void Print(std::ostream& out) const override;
	};

	class Berserk : public Character {
	public:
		Berserk() : Character(1000, 25, 120) { _type = "Berserk"; };
		int Damage() override;
		void UseSkill() override;
		void _ResetParams() override;
		void Print(std::ostream& out) const override;
	};
	
}


