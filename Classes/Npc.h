#ifndef _NPC_H_
#define _NPC_H_

#include "Wizard.h"

#include <string>

namespace CastingSpells
{
	class Npc : public Wizard
	{
	private:

	public:

		void Update(int ms);
	};
}

#endif
