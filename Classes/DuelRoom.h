#ifndef _DUELROOM_H_
#define _DUELROOM_H_

#include "cocos2d.h"
#include "Player.h"
#include "Npc.h"


namespace CastingSpells
{
	namespace Scene
	{
		class DuelRoom : public cocos2d::Scene
		{
		public:

			DuelRoom();

			Player player;
			Npc npc;

			cocos2d::Label * textInput;
			cocos2d::Sprite * textBackground;

			void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

			//overrided from Scene
			void update(float delta);

			//overrided from Scene
			void OnEnter();

		};
	}
}

#endif

