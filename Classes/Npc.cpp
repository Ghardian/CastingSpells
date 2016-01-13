#include "Npc.h"


#include <stdlib.h>
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
			
			
			int num_spell;
			num_spell = rand() % 3;

			switch (num_spell)
			{
			case 0:
				attack_spell_name = "attack fireball";
				typing_time = 350 * attack_spell_name.size(); //ms por tecla * numero de teclas necesarias
				break;
			case 1:
				attack_spell_name = "attack frosty wind";
				typing_time = 350 * attack_spell_name.size();
				break;
			case 2:
				attack_spell_name = "deffense war cry";
				typing_time = 350 * attack_spell_name.size();
				break;
			}
			
			
			typing_time = 350 * attack_spell_name.size(); //ms por tecla * numero de teclas necesarias
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
