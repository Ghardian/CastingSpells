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

		

	public:

		std::string GetName();
		int GetId();
		std::string GetDescription();
		SpellType GetType();
		int GetValue();
		float GetCD();
		float GetSpawn();

		
		Spell(std::string name, int id, std::string description, SpellType type, int value, float cd, float spawn);

		//Funciones
		void Print();

		bool IsReady();
		void Update(int ms);
	};
}

#endif





