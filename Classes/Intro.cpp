#include "Intro.h"
#include "Game.h"

#include <iostream>

using namespace std;
using namespace CastingSpells;
using namespace CastingSpells::Scene;


Intro::Intro() : cocos2d::Scene()
{
	cout << "Intro scene" << endl;

	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	auto sprite = cocos2d::Sprite::create("CastingSpellsCOVER.png");

	sprite->setPosition(cocos2d::Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);



	//PRIMERITA LABEL, que no se si va, pero compila
	cocos2d::CCLabelTTF* ttf1 = cocos2d::CCLabelTTF::create("Play", "Hobbiton Brushhand", 20, cocos2d::CCSizeMake(245, 32), cocos2d::kCCTextAlignmentCenter);
	ttf1->setPosition(cocos2d::Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(ttf1, 1);

	//static Label * 	createWithSystemFont(const std::string &text, const std::string &font, float fontSize, const Size &dimensions = Size::ZERO, TextHAlignment hAlignment = TextHAlignment::LEFT, TextVAlignment vAlignment = TextVAlignment::TOP)


	auto listener = cocos2d::EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(Intro::onKeyPressed, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

}

void Intro::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
	Game::GetGame()->GotoDuelRoom();
}
