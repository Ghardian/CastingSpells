#include "Wizard.h"

#include <fstream>

using namespace std;
using namespace CastingSpells;

Wizard::Wizard(string name,string wizardRange, int id, int hp, int lvl,vector<Spell> spells)
{
	this->name = name;
	this->wizardRange = wizardRange;
	this->id = id;
	this->hp = hp;
	this->lvl = lvl;
	this->spells = spells;	
}

Wizard::Wizard()
{
}

string Wizard::GetName()
{
	return name;
}

string Wizard::GetWizardRange()
{
	return wizardRange;
}

int Wizard::GetHP()
{
	return hp;
}

int Wizard::GetLvl()
{
	return lvl;
}

void Wizard::Update(int ms)
{

}

void Wizard::CastSpell(string spell_name)
{


	bool found = false;

	for (Spell s: spells) 
	{
		if (s.GetName() == spell_name) 
		{
			//to do
			found = true;
		}
	}

	if (found == false) 
	{
		throw string("spell not found");
	}

}

void Wizard::Save(string file_name)
{
	/*
	id:nombre:rango:hp:lvl:1,3,6,8,9,4	
	*/

	ofstream file;

	file.open(file_name);

	file << id << ":" << name << ":" << wizardRange << ":" << hp << ":" << lvl << ":";
	for (int i = 0; i < spells.size(); i++)
	{
		if(i < (spells.size()-1) )
		{
			file << spells[i].GetId() << ",";
		}
		else 
		{
			file << spells[i].GetId();
		}
	}


	file.close();

}

Wizard Wizard::Load(string file_name)
{
	//to do, load wizard (mirar el de grimorio)
	return Wizard();
}
