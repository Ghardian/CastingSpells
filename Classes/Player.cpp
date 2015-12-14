
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
		messages.push_back(msg);
	}
}
