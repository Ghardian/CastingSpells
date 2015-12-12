#ifndef _GAME_H_
#define _GAME_H_

#include "Grimorio.h"

#include "Intro.h"
#include "DuelRoom.h"

namespace CastingSpells 
{
	class Game
	{
	private:
		static Game * instance;

		Grimorio * grimorio;

		Scene::Intro * introScene;
		Scene::DuelRoom * duelroomScene;

		Game();
		~Game();

	public:

		static Game * GetGame();
		static void Quit();

		Grimorio * GetGrimorio();

		void GotoIntro();
		void GotoDuelRoom();

	};

}

#endif
























