#ifndef _GRIMORIO_H_
#define _GRIMORIO_H_

#include "Spell.h"
#include <vector>

namespace CastingSpells
{
	class Grimorio
	{
	private:
		std::vector<Spell> spells; //lista de spells
	public:
		void LoadSpells();

		void PrintSpells();

		std::vector<Spell> GetSpells(std::vector<int> ids);
	};
}

#endif
