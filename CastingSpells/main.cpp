
#include "Game.h"
#include "Utils.h"
#include "Grimorio.h"
#include "Wizard.h"
#include "Player.h"
#include "Npc.h"

#include <vector>
#include <iostream>
#include <string>

using namespace std;
using namespace CastingSpells;

/*
* Test: Utils function: Split
*
*/
void TestSplit()
{
	vector<string> split = Utils::Split("hola;adios;hasta luego", ';');

	cout << "El resultado es:" << endl;

	for (string s : split)
	{
		cout << "[" << s << "]" << endl;
	}
}


void TestGrimorio()
{
	Grimorio grimorio;

	grimorio.LoadSpells();
	grimorio.PrintSpells();

}

void TestWizard()
{
	Grimorio grimorio;

	grimorio.LoadSpells();
	grimorio.PrintSpells();

	vector<int> ids = {1,2};
	vector<Spell> spells = grimorio.GetSpells(ids);

	Wizard wizard("Potter", "Estudiante", 0, 100, 1, spells);

	wizard.Save("potter.txt");

}


/* MAIN FUNCTION
* Print the Grimorio, Load the current wizard?, Try Spells
*
*/
int main(int argc, char *argv[])
{
	
	cout << "Casting Spells !" << endl;

	
	//Wizard wizard = Wizard::Load("potter.txt");
	Player player;
	player.Load("potter.txt");
	
	Npc npc;
	npc.Load("granger.txt");
	

	player.SetEnemy(&npc);
	npc.SetEnemy(&player);



	while (true)
	{
		string input;

		getline(cin,input);

		if (input == "quit")
		{
			break;
		}

		if (input=="help")
		{
			//ToDo:mostrar spells
		}

		if (input != "")
		{
			player.TrySpell(input);
		}

		player.Update(500);
		npc.Update(500);

	}

	Game::Quit();

	//cin.get();

	return 0;
}