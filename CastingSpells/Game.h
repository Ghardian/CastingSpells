#ifndef _GAME_H_
#define _GAME_H_

#include "Grimorio.h"

namespace CastingSpells 
{
	class Game
	{
	private:
		static Game * instance;

		Grimorio * grimorio;

		Game();
		~Game();

	public:

		static Game * GetGame();
		static void Quit();

		Grimorio * GetGrimorio();

	};

}

#endif























#endif
