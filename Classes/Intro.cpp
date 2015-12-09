#include "Intro.h"

#include <iostream>

using namespace std;
using namespace CastingSpells;
using namespace CastingSpells::Scene;


Intro::Intro() : cocos2d::Scene()
{
	cout << "Intro scene" << endl;

	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	auto sprite = cocos2d::Sprite::create("HelloWorld.png");

	sprite->setPosition(cocos2d::Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);
}