
#include "Player.h"

#include <iostream>

using namespace CastingSpells;
using namespace std;

void Player::TrySpell(string spellname)
{
	try
	{
		CastSpell(spellname);
	}
	catch (string msg)
	{
		cout << "Spell not found! try again [" << spellname << "]" << endl;
	}
}
