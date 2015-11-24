#ifndef _WIZARD_H_
#define _WIZARD_H_
#include "Spell.h"

#include <string>
#include <vector>

namespace CastingSpells
{
	class Wizard 
	{
	protected:
		std::string name;
		std::string wizardRange;
		int id;
		int hp;
		int lvl;
		std::vector<Spell> spells; //lista de spells

		Wizard * enemy;

	public:

		Wizard(std::string name, std::string wizardRange, int id, int hp, int lvl,std::vector<Spell> spells);
		Wizard();

		std::string GetName();
		std::string GetWizardRange();
		int GetHP();
		int GetLvl();

		void SetEnemy(Wizard * enemy);

		//Virtual : se usa para que las clases que hereden de ti usen sus propias funciones con el mismo nombre(overload?)
		virtual void Update(int ms);
		void CastSpell(std::string spell_name);

		void Save(std::string file_name);
		void Load(std::string file_name);
	
	};
}
#endif