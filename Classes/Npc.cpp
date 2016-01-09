#include "Npc.h"


#include <iostream>
#include <cstdlib>

using namespace CastingSpells;
using namespace std;

void Npc::Update(int ms)
{
	Wizard::Update(ms);

	if (spells.size() > 0)
	{

		if (attack_spell_name == "")
		{
			//seleccionar hechizo de ataque

			//hardcoded attack
			attack_spell_name = "attack fireball";
			typing_time = 300 * attack_spell_name.size(); //ms por tecla * numero de teclas necesarias
		}


		typing_time -= ms;

		if (typing_time <= 0)
		{
			try
			{
				CastSpell(attack_spell_name);
			}
			catch (string msg)
			{

			}
			attack_spell_name = "";
		}

		
	}

	
}
