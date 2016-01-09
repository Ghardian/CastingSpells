#ifndef _DUELROOM_H_
#define _DUELROOM_H_

#include "cocos2d.h"
#include "Player.h"
#include "Npc.h"
#include "SimpleAudioEngine.h"

#include <map>
#include <queue>

namespace CastingSpells
{
	namespace Scene
	{
		class DuelRoom : public cocos2d::Scene
		{

		private:
			cocos2d::Label * textInput;
			cocos2d::Label * textOutput;


			cocos2d::Label * textPlayerLife;
			cocos2d::Label * textNPCLife;

			cocos2d::Sprite * textBackground;

			std::queue<std::string> msg_queue;
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

			void PushMessage(std::string msg);

			void ProcessPlayerMessages(std::vector<std::string> messages);
			void ProcessNPCMessages(std::vector<std::string> messages);

		};
	}
}

#endif

