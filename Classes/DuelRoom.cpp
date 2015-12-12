#include "DuelRoom.h"
#include <ui\CocosGUI.h>
#include <iostream>

using namespace std;
using namespace CastingSpells;
using namespace CastingSpells::Scene;


DuelRoom::DuelRoom() : cocos2d::Scene()
{
	cout << "DuelRoom Scene: Game" << endl;


	


	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	auto sprite = cocos2d::Sprite::create("escenario.png");

	sprite->setPosition(cocos2d::Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));


	//sprite->setPosition(cocos2d::Vec2(x,y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);


	textBackground = cocos2d::Sprite::create("keyboard.png");
	textBackground->setPosition(cocos2d::Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 3 + origin.y));

	addChild(textBackground,1);


	textInput = cocos2d::Label::create("hola", "Hobbiton Brushhand", 36);
	textInput->setPosition(cocos2d::Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 3 + origin.y));

	addChild(textInput, 2);

	auto listener = cocos2d::EventListenerKeyboard::create();
	listener->onKeyPressed= CC_CALLBACK_2(DuelRoom::onKeyPressed, this);


	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);



}

void DuelRoom::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
	
	string tmp;

	switch (keyCode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_A:
		tmp = textInput->getString();
		tmp = tmp + "a";
		textInput->setString(tmp);
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_B:
		tmp = textInput->getString();
		tmp = tmp + "b";
		textInput->setString(tmp);
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_BACKSPACE:
		tmp = textInput->getString();

		if(tmp.size()>0)
		{
			tmp.erase(tmp.size() - 1, 1);
			textInput->setString(tmp);
		}
		

		
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_KP_ENTER:

		tmp = textInput->getString();
		try
		{
			player.TrySpell(tmp);
		}
		catch (string msg)
		{

		}
		

		textInput->setString("");

		break;
	}


}



void DuelRoom::update(float delta)
{
	int ms = delta * 1000;

	player.Update(ms);
	npc.Update(ms);
}

void Scene::DuelRoom::OnEnter()
{
	player.Load("potter.txt");
	npc.Load("granger.txt");

	player.SetEnemy(&npc);
	npc.SetEnemy(&player);
}
