#include "Spell.h" 

#include <iostream>

using namespace std;
using namespace CastingSpells;

string Spell::GetName()
{
	return name;
}

int Spell::GetId()
{
	return id;
}

string Spell::GetDescription() 
{
	return description;
}

SpellType Spell::GetType()
{
	return type;
}

int Spell::GetValue()
{
	return value;
}

float Spell::GetCD()
{
	return cd;
}

float Spell::GetSpawn()
{
	return spawn;
}

Spell::Spell(string name, int id, string description, SpellType type, int value, float cd, float spawn)
{
	this->name = name;
	this->id = id;
	this->description = description;
	this->type = type;
	this->value = value;
	this->cd = cd;
	this->spawn = spawn;

	current_cd, current_spawn = 0;
	
}


void Spell::Print()
{
	cout << "SpellName: " << name << " Description: " << description << endl;
	//to do, acabar print
}

bool Spell::IsReady()
{
	return false;
}

void Spell::Update(int ms)
{

}
