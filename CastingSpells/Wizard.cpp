#include "Wizard.h"
#include "Utils.h"
#include "Game.h"

#include <iostream>
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
			cout << "!!! " << spell_name << " !!!" << endl;
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
	ifstream file;

	file.open(file_name);

	string line;
	getline(file, line);

	file.close();

	vector<string> wizard_data = Utils::Split(line, ':');

	string name=wizard_data[0];
	string range = wizard_data[1];
	int id = stoi(wizard_data[2]);
	int hp = stoi(wizard_data[3]);
	int lvl = stoi(wizard_data[4]);
	
	vector<string> s = Utils::Split(wizard_data[5], ',');
	vector<int> spell_ids;
	for (string i : s) 
	{
		spell_ids.push_back(stoi(i));
	}

	vector<Spell> spells = Game::GetGame()->GetGrimorio()->GetSpells(spell_ids);

	Wizard wret(name,range,id,hp,lvl,spells);

	return wret;
}
