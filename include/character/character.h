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
		bool _skillStatus; //отвечает за активность навыка в данный момент, навык работает 1 следующий ход

		Character(int health, int armor, int damage) :_type("No type"), _health(health), _armor(armor), _damage(damage), _chance(0.5), _skillStatus(false) {};
	
	public:
		friend std::ostream& operator<<(std::ostream& out, const Character& pers);
		void Print(std::ostream& out) const;

		Character() : _health(0), _armor(0), _damage(0), _chance(0.5), _skillStatus(false) {};

		int GetHP() const;
		int GetArmor() const;
		int GetDamage() const;
		double GetChance() const {
			return _chance;
		}
		bool GetSkillStatus() const;
		virtual std::string GetType() const;
		std::string GetStringUsedSkill() const;

		void SetChance(double chance);

		virtual std::unique_ptr<Character> clone() const;

		virtual int Damage();
		virtual int TakeDamage(int Damage);
		virtual int Attack(Character& opponent);
		virtual void UseSkill();
		std::string MakeAMove(int choose, Character& opponent);
		virtual ~Character() = default;
		Character(const Character& other) = default;
		Character& operator=(const Character& other) = default;

	protected:
		virtual void _ResetParams();
		bool _CritChance();
		

	};
	
	class Knight : public Character {
	public:
		Knight() :Character(1000, 50, 100) {};
		int TakeDamage(int Damage) override;
		void UseSkill() override;
		void _ResetParams() override;
		std::unique_ptr<Character> clone() const override;
		std::string GetType() const override;

	};

	class Assasin : public Character {
	public:
		Assasin() : Character(1200, 25, 100) {};
		int TakeDamage(int Damage) override;
		int Attack(Character& opponent) override;
		std::unique_ptr<Character> clone() const override;
		std::string GetType() const override;

	};

	class Berserk : public Character {
	public:
		Berserk() : Character(1000, 25, 120) {};
		int Damage() override;
		void UseSkill() override;
		void _ResetParams() override;
		std::unique_ptr<Character> clone() const override;
		std::string GetType() const override;
	};
	
}


