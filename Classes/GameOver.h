#ifndef _GAMEOVER_H_
#define _GAMEOVER_H_


#include "cocos2d.h"

namespace CastingSpells
{
	namespace Scene
	{
		class GameOver : public cocos2d::Scene
		{
		public:

			GameOver();

			void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

		};
	}
}

#endif
