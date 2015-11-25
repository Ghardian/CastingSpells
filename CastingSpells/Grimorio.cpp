#include "Grimorio.h"
#include "Utils.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;
using namespace CastingSpells;

void Grimorio::LoadSpells()
{
	ifstream file;

	file.open("spells.txt");
	
	//eof=end of file
	while (!file.eof())
	{
		string line;
		getline(file, line);

		vector<string> spell = Utils::Split(line,':');
		if (spell.size() == 8) 
		{

			string name;
			int id;
			string description;
			int raw_type;
			SpellType type;
			int value;
			float cd;
			float spawn;
			float duration;

			name = spell[1];
			id = stoi(spell[0]);
			description = spell[2];
			raw_type = stoi(spell[3]);
			switch (raw_type)
			{
			case 1:
				type = SpellType::Attack;
				break;

			case 2:
				type = SpellType::Deffense;
				break;

			case 3:
				type = SpellType::Utility;
				break;

			case 4:
				type = SpellType::Heal;
				break;
			}

			value = stoi(spell[4]);
			cd = stof(spell[5]);
			spawn = stof(spell[6]);
			duration = stof(spell[7]);
			
			Spell tmp(id,name,description,type,value,cd,spawn,duration);

			spells.push_back(tmp);


		}
		else //Comentario
		{
			cout << "Comentario: " << line << endl;
		}
	}

	file.close();
}

void Grimorio::PrintSpells()
{
	for (Spell s : spells)
	{
		s.Print();
	}
}

vector<Spell> Grimorio::GetSpells(vector<int> ids)
{
	vector<Spell> list;

	for (int id: ids) 
	{

		for (Spell s : spells) 
		{
			if (s.GetId() == id) 
			{
				list.push_back(s);
			}
		}
	}

	return list;
}
