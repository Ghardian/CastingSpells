#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Wizard.h"

#include <string>

namespace CastingSpells
{
	class Player: public Wizard
	{
	public:

		void TrySpell(std::string spellname);
	};
}

#endif
