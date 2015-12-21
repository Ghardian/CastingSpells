#include "DuelRoom.h"
#include "Utils.h"
#include <ui\CocosGUI.h>
#include <iostream>
#include "SimpleAudioEngine.h"

using namespace std;
using namespace CastingSpells;
using namespace CastingSpells::Scene;


DuelRoom::DuelRoom() : cocos2d::Scene()
{
	cout << "DuelRoom Scene: Game" << endl;

	textTimer = 0.0f;
		
	posPlayerX = 200;
	posPlayerY = 180;
	posNpcX = 1000;
	posNpcY = 540;



	//audio
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("batalla.m4a", true);

	//Vector variable
	visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
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

	//pos_enemy = (cocos2d::Vec2(visibleSize.width - , visibleSize.height));

	player1->setPosition(posPlayerX, posPlayerY);
	player2->setPosition(posNpcX,posNpcY);

	addChild(player1, 4);
	addChild(player2, 5);


	//Grimorio Sprite
	textBackground = cocos2d::Sprite::create("keyboard.png");
	textBackground->setPosition(650,100);

	addChild(textBackground,1);

	//Grimorio Label
	textInput = cocos2d::Label::create("Type to write the spell!", "DK Moonlight Shadow", 36);
	int x = 650;
	int y = 70;
	textInput->setPosition(x,y);
	textInput->setColor(cocos2d::ccc3(225, 225, 25));

	addChild(textInput, 2);

	//string error_txt = "";
	textOutput = cocos2d::Label::create("Cast 'help' for help", "Harry P", 50);
	textOutput->setPosition(650,140);
	textOutput->setColor(cocos2d::ccc3(225,225,40));

	addChild(textOutput, 3);
	
	

	auto listener = cocos2d::EventListenerKeyboard::create();
	listener->onKeyPressed= CC_CALLBACK_2(DuelRoom::onKeyPressed, this);


	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	scheduleUpdate();

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


/**
 This function is called each frame
 delta is time since last frame in seconds
*/
void DuelRoom::update(float delta)
{
	int ms = delta * 1000;

	textTimer += delta;


	if (textTimer > 4.0f)
	{
		textOutput->setString("");
	}

	vector<string> messages;
	messages = player.GetMessages();
	
	if (messages.size()>0)
	{
		string tmp = messages[0];
		vector<string> msgdata=Utils::Split(tmp,':');

		if (msgdata[0] == "message")
		{
			textOutput->setString(msgdata[1]);
			textTimer = 0.0f;
		}

		if (msgdata[0] == "action")
		{
			if(msgdata[1]=="cast")
			{
				if (msgdata[2] == "attack fireball")
				{
					textOutput->setString("Casted " + msgdata[2]);
					textTimer = 0.0f;
					
					auto fireball=cocos2d::Sprite::create("fireball.png");
					
					fireball->setPosition(cocos2d::Vec2(posPlayerX+20, posPlayerY+10));

					auto callbackDie = cocos2d::CallFunc::create([this,fireball]() {
						this->removeChild(fireball, true);
					});

					auto action = cocos2d::MoveTo::create(0.5, cocos2d::Vec2(posNpcX, posNpcY));
					auto seq = cocos2d::Sequence::create(action, callbackDie, nullptr);
					fireball->runAction(seq);
					
					addChild(fireball);
				}


				if (msgdata[2] == "utility silence curse") 
				{
					textOutput->setString("Casted " + msgdata[2]);
					textTimer = 0.0f;

					auto silence = cocos2d::Sprite::create("silence.png");

					silence->setPosition(cocos2d::Vec2(posNpcX, posNpcY+50));

					auto callbackDie = cocos2d::CallFunc::create([this, silence]() {
						this->removeChild(silence, true);});

					auto action = cocos2d::MoveTo::create(0.5, cocos2d::Vec2(posNpcX+10, posNpcY-100));
					auto seq = cocos2d::Sequence::create(action, callbackDie, nullptr);
					silence->runAction(seq);

					addChild(silence);
				}

				if (msgdata[2] == "deffense shield of ancients")
				{
					textOutput->setString("Casted " + msgdata[2]);
					textTimer = 0.0f;

					auto shield = cocos2d::Sprite::create("shield.png");

					shield->setPosition(cocos2d::Vec2(posPlayerX+20, posPlayerY+20));

					auto callbackDie = cocos2d::CallFunc::create([this, shield]() {
						this->removeChild(shield, true); });

					auto action = cocos2d::RotateBy::create(2.0f, 180.0f);
					auto action2 = cocos2d::ScaleBy::create(2.0f, 1.2f);
					auto seq = cocos2d::Sequence::create(action,action2, callbackDie, nullptr);
					shield->runAction(seq);

					addChild(shield);
				}
				
				if (msgdata[2] == "attack thunderstruck")
				{
					textOutput->setString("Casted " + msgdata[2]);
					textTimer = 0.0f;

					auto thunder = cocos2d::Sprite::create("rayo.png");

					thunder->setPosition(cocos2d::Vec2(posNpcX, posNpcY + 30));

					auto callbackDie = cocos2d::CallFunc::create([this, thunder]() {
						this->removeChild(thunder, true); });

					auto action = cocos2d::RotateTo::create(1.5f, 15.0f);
					auto action2 = cocos2d::ScaleBy::create(2.5f, 1.5f);
					auto seq = cocos2d::Sequence::create(action, action2, callbackDie, nullptr);
					thunder->runAction(seq);

					addChild(thunder);
				}

				
			}
		}

		
	}


	player.Update(ms);
	npc.Update(ms);
}

void Scene::DuelRoom::onEnter()
{
	cocos2d::Node::onEnter();

	player.Load("potter.txt");
	npc.Load("granger.txt");

	player.SetEnemy(&npc);
	npc.SetEnemy(&player);
}
