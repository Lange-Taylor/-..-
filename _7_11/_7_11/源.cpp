#if 0

#include <iostream>

using namespace std;

int main() 
{
	int I = 1;
	if (I <= 0)
		printf("****\n");

	else
		printf("%%%%\n");
	return 0;
}
#endif

#include <iostream>
#include <string>

using namespace std;


int Is_letter_sum(string& s)
{
	int count = 0;
	int count1 = 0;
	for (auto e : s)
	{
		if (e >= 'a' && e <= 'z')
			count++;
		else if (e >= 'A' && e <= 'Z')
			count1++;
	}
	if ((count == 0 && count1 != 0) || (count == 0 && count1 != 0))
		return 10;
	else if (count > 0 && count1 > 0)
		return 20;
	else	
		return 0;
}

//int Is_big_letter(string& s)
//{
//	int count = 0;
//	for (auto e : s)
//	{
//		if (e >= 'A' && e <= 'Z')
//			count++;
//	}
//	return count;
//}
int  Is_symbol_sum(string& s)
{
	int count = 0;
	for (auto e : s)
	{
		if ((e >= '!' && e <= '/') || (e >= ':' && e <= '@')
			|| (e >= '[' && e <= '`') || (e >= '{' && e <= '~'))
			count++;
	}
	if (count == 0)
		return 0;
	else if (count == 1)
		return 10;
	else 
		return 25;
}
int Is_number_sum(string& s)
{
	int count = 0;
	for (auto e : s)
	{
		if (e >= '0' && e <= '9')
			count++;
	}
	if (count == 0)
		return 0;
	else if (count == 1)
		return 10;
	else
		return 20;
}
int len_sum(string& s)
{
	int len = s.size();
	if (len < 5)
		return 5;
	else if (len < 8)
		return 10;
	else
		return 25;
}
int Reward(string& s)
{
	if (Is_letter_sum(s) == 10 && Is_number_sum != 0)
		return 2;
	if (Is_letter_sum(s) == 10 && Is_number_sum(s) != 0 && Is_symbol_sum(s) != 0)
		return 3;
	if (Is_letter_sum(s) == 25 && Is_number_sum(s) != 0 && Is_symbol_sum(s) != 0)
		return 5;
	else
		return 0;
}

int score(string& s)
{
	return Is_symbol_sum(s) + Is_letter_sum(s)
		+ Is_number_sum(s) + len_sum(s) + Reward(s);
}
int main() 
{

	string s;
	cin >> s;

	int temp = score(s);
	if (temp >= 0 && temp < 25)
		cout << "VERY_WEAK" << endl;
	if (temp >= 25 && temp < 50)
		cout << "WEAK" << endl;
	if (temp >= 50 && temp < 60)
		cout << "AVERAGE" << endl;
	if (temp >= 60 && temp < 70)
		cout << "STRONG" << endl;
	if (temp >= 70 && temp < 80)
		cout << "VERY_STRONG" << endl;
	if (temp >= 80 && temp < 90)
		cout << "SECURE" << endl;
	if(temp >= 90)
		cout << "VERY_SECURE" << endl;

	return 0;
}

//38$@NoNoNo