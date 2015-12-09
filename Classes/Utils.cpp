

#include "Utils.h"


using namespace std;

/* SPLIT FUNCTION
Splits a string using a character as splitter. Returns a vector<string>

*/
vector<string> CastingSpells::Utils::Split(string str, char s)
{
	vector<string> tmp;

	string tstr;


	//foreach estilo python
	for (char c : str)
	{
		if (c != s)
		{
			tstr = tstr + c;
		}
		else
		{
			tmp.push_back(tstr);
			tstr = "";
		}
	}

	if (tstr != "")
	{
		tmp.push_back(tstr);
	}

	return tmp;
}

