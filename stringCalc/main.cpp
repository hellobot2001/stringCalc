#include <cassert>
#include <string>
#include <iostream>
using namespace std;

static int stringCalc(string str)
{
	int sum = 0;
	string cur = "";
	//cout << str << " " << str.length() << endl;
	for (int i = 0; i < str.length(); i++)
	{
		//cout << str[i] << " == ; or , ? " << ((str[i] == 59) || (str[i] == 44)) << endl;
		if ((str[i] == 59) || (str[i] == 44))
		{
			sum += stoi(cur, 0, 10);
			cur = "";
		}
		else
		{
			cout << "cur: " << cur << endl;
			string s(1, str[i]);
			cout << s << endl;
			cur.append(s);
		}
	}
	
	if (cur.length() > 0)
	{
		sum += stoi(cur, 0, 10);
	}
	cout << str << " -> " << sum << endl;
	return sum;
}

int main()
{
	assert(stringCalc("") == 0);
	assert(stringCalc("5,6") == 11);
	assert(stringCalc("81,2") == 83);
	assert(stringCalc("-2,6") == 4);
	assert(stringCalc("60;5") == 65);
	assert(stringCalc("-5;6") == 1);
	assert(stringCalc("5;-6") == -1);
	assert(stringCalc("5,6;-11") == 0);
	assert(stringCalc("") == 0);
	assert(stringCalc("5,6;7,8") == 26);
	assert(stringCalc("5") == 5);
	assert(stringCalc("5,6") == 11);
	cout << "woahg it all workde" << endl;
}