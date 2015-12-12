#ifndef _INTRO_H_
#define _INTRO_H_

#include "cocos2d.h"

namespace CastingSpells
{
	namespace Scene 
	{
		class Intro : public cocos2d::Scene
		{
		public:

			Intro();

			void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

		};
	}
}

#endif
