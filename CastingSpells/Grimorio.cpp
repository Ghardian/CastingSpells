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
		if (spell.size() == 7) 
		{

			string name;
			int id;
			string description;
			int raw_type;
			SpellType type;
			int value;
			float cd;
			float spawn;

			name = spell[0];
			id = stoi(spell[1]);
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


			Spell tmp(name,id,description,type,value,cd,spawn);

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
