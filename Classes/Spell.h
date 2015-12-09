#ifndef _SPELL_H_
#define _SPELL_H_

#include <string>

enum class SpellType {Attack, Deffense, Utility, Heal};

namespace CastingSpells 
{
	class Spell 
	{

	private:
		std::string name;
		int id;
		std::string description;
		SpellType type; //Attack, Deffense, Utility and Heal
		int value;
		float cd; //Cooldown
		float current_cd;
		float spawn;//Time to cast
		float current_spawn;
		float duration;
		float current_duration;

		

	public:

		std::string GetName();
		int GetId();
		std::string GetDescription();
		SpellType GetType();
		int GetValue();
		float GetCD();
		float GetSpawn();
		float GetDuration();
		void SetCurrentSpawn(float spawn);
		void SetCurrentCD(float cd);
		void SetCurrentDuration(float duration);

		
		Spell(int id, std::string name, std::string description, SpellType type, int value, float cd, float spawn, float duration);

		//Funciones
		void Print();

		bool IsCold();
		bool IsWarm();
		bool IsDone();
		void Update(int ms);
	};
}

#endif





