
#include "Utils.h"
#include "Grimorio.h"
#include "Wizard.h"

#include <vector>
#include <iostream>
#include <string>

using namespace std;
using namespace CastingSpells;

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

int main(int argc, char *argv[])
{

	cout << "Casting Spells !" << endl;

	
	TestWizard();

	cin.get();

	return 0;
}