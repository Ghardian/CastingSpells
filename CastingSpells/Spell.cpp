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

float Spell::GetDuration()
{
	return duration;
}

void Spell::SetCurrentSpawn(float spawn)
{
	current_spawn = spawn;
}

void Spell::SetCurrentCD(float cd)
{
	current_cd = cd;
}

void Spell::SetCurrentDuration(float duration)
{
	current_duration = duration;
}

/*SPELL CONSTRUCTOR*/
Spell::Spell(int id,string name, string description, SpellType type, int value, float cd, float spawn, float duration)
{
	this->name = name;
	this->id = id;
	this->description = description;
	this->type = type;
	this->value = value;
	this->cd = cd;
	this->spawn = spawn;
	this->duration = duration;

	current_cd = cd;
	current_spawn = 0;
	current_duration = duration;
	
}

/* FUNCTIONS: Print. Print the Spells */
void Spell::Print()
{
	//convertir spell a string con un switch
	//cout << "SpellName: " << name << ", Description: " << description << ", Id Spell: " << id << ", Type: " << type << ", Damage or Seconds Stunned: " << value << ", Cooldown: "<< cd << ", Ready in: "<< spawn << endl;
	//Como hacia que en type pusiera el nombre y no el numero?
	cout << "--> " << name << ":" << current_spawn << endl;
}

/* IsReady FUNCTION: returns true when current_spawn >= spawn and current_cooldown==0, and the spell will be ready to be spawned*/

bool Spell::IsCold()
{
	return (current_cd >= cd);
}

bool Spell::IsWarm()
{
	return (current_spawn >= spawn);
}

bool Spell::IsDone()
{
	return (current_duration >= duration);
}

void Spell::Update(int ms)
{
	float time_lapse = (ms / 1000.0f);
	current_cd += time_lapse;
	current_spawn += time_lapse;
	current_duration += time_lapse;
}
