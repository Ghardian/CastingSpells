#ifndef _NPC_H_
#define _NPC_H_

#include "Wizard.h"

#include <string>

namespace CastingSpells
{
	class Npc : public Wizard
	{
	private:
		std::string attack_spell_name;
		int typing_time;

	public:

		void Update(int ms);
	};
}

#endif
