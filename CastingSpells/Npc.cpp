#include "Npc.h"


#include <iostream>
#include <cstdlib>

using namespace CastingSpells;
using namespace std;

void Npc::Update(int ms)
{
	Wizard::Update(ms);

	int sid = rand() % spells.size();

	cout << "["<<name<<"] Te lanzo un: " << spells[sid].GetName() << endl;
}
