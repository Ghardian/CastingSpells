

#include "Utils.h"


using namespace std;


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

