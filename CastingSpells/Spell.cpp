#include "Spell.h" 

#include <iostream>

using namespace std;
using namespace CastingSpells;

/*GETTERS OF SPELL ATRIBUTES*/
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

/*SPELL CONSTRUCTOR*/
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

/* FUNCTIONS: Print. Print the Spells */
void Spell::Print()
{
	//convertir spell a string con un switch
	//cout << "SpellName: " << name << ", Description: " << description << ", Id Spell: " << id << ", Type: " << type << ", Damage or Seconds Stunned: " << value << ", Cooldown: "<< cd << ", Ready in: "<< spawn << endl;
	//Como hacia que en type pusiera el nombre y no el numero?
}

/* IsReady FUNCTION: returns true when current_spawn >= spawn and current_cooldown==0, and the spell will be ready to be spawned*/
bool Spell::IsReady()
{
	if (current_spawn >= spawn && current_cd==0) 
	{//donde actualizaremos current_spawn y current_cd?
		return true;
	}
	else 
	{ 
		return false; 
	}
}

void Spell::Update(int ms)
{

}
