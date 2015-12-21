#ifndef _DUELROOM_H_
#define _DUELROOM_H_

#include "cocos2d.h"
#include "Player.h"
#include "Npc.h"
#include "SimpleAudioEngine.h"

#include <map>

namespace CastingSpells
{
	namespace Scene
	{
		class DuelRoom : public cocos2d::Scene
		{

		private:
			cocos2d::Label * textInput;
			cocos2d::Label * textOutput;
			cocos2d::Sprite * textBackground;

			float textTimer;

			cocos2d::Size visibleSize;

		public:

			DuelRoom();

			Player player;
			Npc npc;
			int posPlayerX;
			int posPlayerY;
			int posNpcX;
			int posNpcY;
			int playerSizeX;
			int playerSizeY;
			int npcSizeX;
			int npcSizeY;

			 

			void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

			//overrided from Scene
			void update(float delta);

			//overrided from Scene
			void onEnter();

		};
	}
}

#endif

