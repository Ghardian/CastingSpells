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
	public:

		Wizard(std::string name, std::string wizardRange, int id, int hp, int lvl,std::vector<Spell> spells);
		Wizard();

		std::string GetName();
		std::string GetWizardRange();
		int GetHP();
		int GetLvl();

		void Update(int ms);
		void CastSpell(std::string spell_name);

		void Save(std::string file_name);
		static Wizard Load(std::string file_name);
	
	};
}
#endif