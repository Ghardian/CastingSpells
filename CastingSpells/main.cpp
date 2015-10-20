
#include "Utils.h"

#include <vector>
#include <iostream>
#include <string>

using namespace std;
using namespace CastingSpells;

int main(int argc, char *argv[])
{

	cout << "Hola Mundo" << endl;

	vector<string> split = Utils::Split("hola;adios;hasta luego", ';');

	cout << "El resultado es:" << endl;

	for (string s : split)
	{
		cout << "[" << s << "]" << endl;
	}

	cin.get();

	return 0;
}