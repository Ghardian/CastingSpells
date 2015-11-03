
#include "Utils.h"
#include "Grimorio.h"

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

int main(int argc, char *argv[])
{

	cout << "Casting Spells !" << endl;

	
	TestGrimorio();

	cin.get();

	return 0;
}