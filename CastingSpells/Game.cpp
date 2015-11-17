#include "Game.h"

using namespace CastingSpells;


Game * Game::instance = nullptr;


Game::Game()
{
	grimorio = new Grimorio();
	grimorio->LoadSpells();
	grimorio->PrintSpells();
		
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