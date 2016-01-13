#include "GameOver.h"
#include "DuelRoom.h"
#include "Utils.h"
#include <ui\CocosGUI.h>
#include <iostream>
#include "SimpleAudioEngine.h"
#include "Game.h"
#include <iostream>

using namespace std;
using namespace CastingSpells;
using namespace CastingSpells::Scene;


GameOver::GameOver() : cocos2d::Scene()
{
	

	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	auto sprite = cocos2d::Sprite::create("gameover.png");

	sprite->setPosition(cocos2d::Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);



	//ttf1->setPosition(cocos2d::Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 3 + origin.y)); LABEL PLAY
	cocos2d::CCLabelTTF* ttf1 = cocos2d::CCLabelTTF::create("Game Over", "Hobbiton Brushhand", 120);
	ttf1->setPosition(cocos2d::Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
	ttf1->setColor(cocos2d::ccc3(225, 225, 25));
	//ttf1->enableShadow(cocos2d::Color4B::BLACK, 100, 0);
	//	ttf1->enableOutline
	this->addChild(ttf1, 1);
	//cocos2d::CCSizeMake(245, 32), cocos2d::kCCTextAlignmentCenter


	//Evento presionar tecla
	auto listener = cocos2d::EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(Intro::onKeyPressed, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

}

void Intro::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
	
}
