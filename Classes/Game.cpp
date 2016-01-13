#include "cocos2d.h"
#include "Game.h"



using namespace CastingSpells;



Game * Game::instance = nullptr;


Game::Game()
{
	grimorio = new Grimorio();
	grimorio->LoadSpells();
	grimorio->PrintSpells();

	introScene = new Scene::Intro();
	duelroomScene = new Scene::DuelRoom();
	gameoverScene = new Scene::GameOver();
		
}

Game::~Game()
{
	delete grimorio;
}


Game * Game::GetGame()//Get Game Instance
{
	if (Game::instance==nullptr)
	{
		Game::instance = new Game();
	}
	return Game::instance;
}


void Game::Quit()
{
	delete Game::instance;
	Game::instance = nullptr;
}

Grimorio * Game::GetGrimorio()
{
	return grimorio;
}

void CastingSpells::Game::GotoIntro()
{
	auto director = cocos2d::Director::getInstance();

	director->runWithScene(introScene);
}

void CastingSpells::Game::GotoDuelRoom()
{
	auto director = cocos2d::Director::getInstance();

	director->replaceScene(duelroomScene);
}

void CastingSpells::Game::GotoGameOver()
{
	auto director = cocos2d::Director::getInstance();

	director->replaceScene(gameoverScene);
}
