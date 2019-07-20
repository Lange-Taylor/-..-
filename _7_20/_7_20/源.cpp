#include <iostream>
#include <string>
using namespace std;
bool solve(string s1, string s2)
{
	for (int i = 0, j = 0; i < s1.size(), j < s2.size();)
	{
		if (s1[i] == '?')
		{
			i++;
			j++;
		}
		else if (s1[i] == '*')
		{
			if (i == s1.size() - 1)
				return true;
			else
			{
				i++;
				j++;
			}
		}
		else if (s1[i] != s2[j])
			return false;
		else
		{
			i++;
			j++;
		}
	}
	return true;
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		if (solve(s1, s2))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}

	return 0;
}



