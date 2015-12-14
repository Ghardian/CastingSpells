#include "DuelRoom.h"
#include <ui\CocosGUI.h>
#include <iostream>
#include "SimpleAudioEngine.h"

using namespace std;
using namespace CastingSpells;
using namespace CastingSpells::Scene;


DuelRoom::DuelRoom() : cocos2d::Scene()
{
	cout << "DuelRoom Scene: Game" << endl;


	//audio
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("batalla.m4a", true);

	//Vector variable
	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();


	//BG Sprite
	auto sprite = cocos2d::Sprite::create("escenario.png");
	sprite->setPosition(cocos2d::Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	//sprite->setPosition(cocos2d::Vec2(x,y));
	// add the sprite as a child to this layer
	this->addChild(sprite, 0);


	//Player and Enemy Sprites
	string enemy="NPC_2.png";
	string player = "main_boy_pj.png";
	auto player1 = cocos2d::Sprite::create(player);
	auto player2 = cocos2d::Sprite::create(enemy);

	player1->setPosition(300,300);
	player2->setPosition(1150,750);

	addChild(player1, 4);
	addChild(player2, 5);


	//Grimorio Sprite
	textBackground = cocos2d::Sprite::create("keyboard.png");
	textBackground->setPosition(800,100);

	addChild(textBackground,1);

	//Grimorio Label
	textInput = cocos2d::Label::create("Type to write the spell!", "Hobbiton Brushhand", 36);
	textInput->setPosition(800,100);
	textInput->setColor(cocos2d::ccc3(225, 225, 25));

	addChild(textInput, 2);

	//string error_txt = "";
	textOutput = cocos2d::Label::create("TextOutput", "Hobbiton Brushhand", 40);
	textOutput->setPosition(800,200);
	textOutput->setColor(cocos2d::ccc3(225,225,40));

	addChild(textOutput, 3);
	
	

	auto listener = cocos2d::EventListenerKeyboard::create();
	listener->onKeyPressed= CC_CALLBACK_2(DuelRoom::onKeyPressed, this);


	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);



}

void DuelRoom::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
	
	string tmp;
	
	if (textInput->getString() == "Type to write the spell!") 
	{
		textInput->setString("");
	}
	

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

	case cocos2d::EventKeyboard::KeyCode::KEY_C:
		tmp = textInput->getString();
		tmp = tmp + "c";
		textInput->setString(tmp);
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_D:
		tmp = textInput->getString();
		tmp = tmp + "d";
		textInput->setString(tmp);
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_E:
		tmp = textInput->getString();
		tmp = tmp + "e";
		textInput->setString(tmp);
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_F:
		tmp = textInput->getString();
		tmp = tmp + "f";
		textInput->setString(tmp);
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_G:
		tmp = textInput->getString();
		tmp = tmp + "g";
		textInput->setString(tmp);
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_H:
		tmp = textInput->getString();
		tmp = tmp + "h";
		textInput->setString(tmp);
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_I:
		tmp = textInput->getString();
		tmp = tmp + "i";
		textInput->setString(tmp);
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_J:
		tmp = textInput->getString();
		tmp = tmp + "j";
		textInput->setString(tmp);
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_K:
		tmp = textInput->getString();
		tmp = tmp + "k";
		textInput->setString(tmp);
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_L:
		tmp = textInput->getString();
		tmp = tmp + "l";
		textInput->setString(tmp);
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_M:
		tmp = textInput->getString();
		tmp = tmp + "m";
		textInput->setString(tmp);
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_N:
		tmp = textInput->getString();
		tmp = tmp + "n";
		textInput->setString(tmp);
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_O:
		tmp = textInput->getString();
		tmp = tmp + "o";
		textInput->setString(tmp);
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_P:
		tmp = textInput->getString();
		tmp = tmp + "p";
		textInput->setString(tmp);
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_Q:
		tmp = textInput->getString();
		tmp = tmp + "q";
		textInput->setString(tmp);
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_R:
		tmp = textInput->getString();
		tmp = tmp + "r";
		textInput->setString(tmp);
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_S:
		tmp = textInput->getString();
		tmp = tmp + "s";
		textInput->setString(tmp);
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_T:
		tmp = textInput->getString();
		tmp = tmp + "t";
		textInput->setString(tmp);
		break;
	
	case cocos2d::EventKeyboard::KeyCode::KEY_U:
		tmp = textInput->getString();
		tmp = tmp + "u";
		textInput->setString(tmp);
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_V:
		tmp = textInput->getString();
		tmp = tmp + "v";
		textInput->setString(tmp);
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_W:
		tmp = textInput->getString();
		tmp = tmp + "w";
		textInput->setString(tmp);
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_X:
		tmp = textInput->getString();
		tmp = tmp + "x";
		textInput->setString(tmp);
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_Y:
		tmp = textInput->getString();
		tmp = tmp + "y";
		textInput->setString(tmp);
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_Z:
		tmp = textInput->getString();
		tmp = tmp + "z";
		textInput->setString(tmp);
		break;

	case cocos2d::EventKeyboard::KeyCode::KEY_SPACE:
		tmp = textInput->getString();
		tmp = tmp + " ";
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
		
		player.TrySpell(tmp);
		
		
		textInput->setString("");
		//remove

		break;
	}

}



void DuelRoom::update(float delta)
{
	int ms = delta * 1000;


	vector<string> messages;
	messages = player.GetMessages();

	if (messages.size()>0)
	{
		string tmp = messages[0];
		textOutput->setString(tmp);
	}


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
