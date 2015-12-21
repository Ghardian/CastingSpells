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
	this->enemy = nullptr;
}



Wizard::Wizard()
{
	this->enemy = nullptr;
	this->warmingSpell = nullptr;
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

void CastingSpells::Wizard::SetEnemy(Wizard * enemy)
{
	this->enemy = enemy;
}

void Wizard::AddIncommingSpell(Spell * spell)
{
	incomingSpells.push_back(spell);
}

void Wizard::Update(int ms)
{
	//actualizamos el estado de los hechizos
	for (Spell & s : spells)
	{
		s.Update(ms);
	}

	//comprobamos el area de calentamiento
	if (warmingSpell != nullptr)
	{
		if (warmingSpell->IsWarm())//Ya esta preparado para castearse el spell (Is warm)
		{
			cout << "Spawned " << warmingSpell->GetName() << endl; //se lanza

			switch (warmingSpell->GetType())
			{
			case SpellType::Deffense:
			case SpellType::Heal:
				ownSpells.push_back(warmingSpell);
				warmingSpell->SetCurrentDuration(0);//Se resetea para comprobar si el hechizo ha terminado
				cout << "duration: " << warmingSpell->GetDuration() << endl;
				break;

			case SpellType::Attack:
			case SpellType::Utility:
				enemy->AddIncommingSpell(warmingSpell);
				warmingSpell->SetCurrentDuration(0);
				break;
			}

			warmingSpell = nullptr;
		}
	}


	//comprobamos los autohechizos
	vector<Spell *> tmp;

	for (Spell * s : ownSpells)
	{
		if (s->IsDone())
		{
			cout << "-This spell is done! " << s->GetName() << endl;
			s->SetCurrentCD(0);
		}
		else
		{
			//ToDo (aplicarnos los hechizos)

			tmp.push_back(s);
		}
	}

	ownSpells = tmp;


	//comprobamos los hechizos que nos afectan
	vector<Spell*> tmpb;

	for (Spell * s: incomingSpells)
	{
		if (s->IsDone())
		{
			cout << "-This spell is done! " << s->GetName() << endl;
			s->SetCurrentCD(0);
		}
		else
		{
			//ToDo:aplicar daños

			tmpb.push_back(s);
		}
	}

	incomingSpells = tmp;

}

void Wizard::CastSpell(string spell_name)
{


	bool found = false;
	Spell * spell=nullptr;

	if (spell_name=="help")
	{
		string tmp = "";

		for (Spell & s: spells)
		{
			tmp = tmp + s.GetName() + ", ";
		}

		messages.push_back("message:"+tmp);

		return;
	}

	for (Spell & s: spells) 
	{
		if (s.GetName() == spell_name) 
		{
			cout << "!!! " << spell_name << " !!!" << endl;
			
			messages.push_back("action:cast:"+spell_name);

			found = true;
			spell = &s;
		}
	}

	if (found == false) 
	{
		throw string("spell not found");
	
	}

	if (warmingSpell!=nullptr)
	{
		throw string("There is already a spell warming!");
		
	}

	if (!spell->IsCold())
	{
		throw string("Spell is not ready yet!");
		
	}

	if (!spell->IsDone())
	{
		throw string("Spell still working!");
	
	}
	
	//Magia calentandose, a punto de ser lanzada
	warmingSpell = spell;
	warmingSpell->SetCurrentSpawn(0);
	
	
	

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
/*LOAD FUNCTION. 
Loads all the information of a wizard (name, wizards_range: Apprentice, Wizard, Great Wizard and Clock´s Tower Master; id_wizard, )
*/
void Wizard::Load(string file_name)
{
	ifstream file;

	file.open(file_name);

	string line;
	getline(file, line);

	file.close();

	vector<string> wizard_data = Utils::Split(line, ':');

	this->name=wizard_data[1];
	this->wizardRange = wizard_data[2];
	this->id = stoi(wizard_data[0]);
	this->hp = stoi(wizard_data[3]);
	this->lvl = stoi(wizard_data[4]);
	
	vector<string> s = Utils::Split(wizard_data[5], ',');
	vector<int> spell_ids;
	for (string i : s) 
	{
		spell_ids.push_back(stoi(i));
	}

	this->spells = Game::GetGame()->GetGrimorio()->GetSpells(spell_ids);
	
}

vector<std::string> Wizard::GetMessages()
{
	//copiar mensajes
	vector<string> tmp = messages;

	//vaciar lista
	messages.clear();

	return tmp;
}
