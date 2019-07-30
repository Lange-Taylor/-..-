
#include <iostream>
#include <string>

using namespace std;
string Area(string &s)
{
	int slen = s.size();
	string str1(slen + 3, 0);
	string str2 = "628";
	int a = 0;
	for(int m = 2; m>=0 ;--m)
		for (int i = slen - 1,j = str1.size() + m -3; i >= 0; --i,--j)
		{
			str1[j] += (s[i] - '0')*(str2[m] - '0');
		}
	for (int i = str1.size(); i >= 0; --i)
	{
		str1[i] += a;
		a = str1[i] / 10;
		str1[i] = str1[i] % 10 + '0';
	}
 
	int index = 0;
	while (str1[index] == '0')
		++index;
	return string(str1.begin() + index, str1.end() - 2);
}

int compare(string& s1, string &s2)
{
	if (s1.size() != s2.size())
	{
		return (s1.size() > s2.size() ? 1 : -1);
	}
	else
	{
		for (int i = 0; i < s1.size(); ++i)
		{
			if (s1[i] == s2[i])
				continue;
			else
				return (s1[i] > s2[i] ? 1 : -1);
		}
		return 0;
	}
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		s2 = Area(s2);
		if (compare(s1, s2) == 1)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;

	}
	return 0;
}

#if 0
#include <iostream>
#include <string>
using namespace std;

string times628(string & str)
{
	string ret(str.length() + 3, 0);
	string str628 = "628";
	int strL = str.length();
	int retL = ret.length();
	int c = 0;

	for (int k = 2; k >= 0; --k)
		for (int i = strL - 1, j = retL + k - 3; i >= 0; --i, --j)
			ret[j] += (str[i] - '0') * (str628[k] - '0');

	for (int i = retL; i >= 0; --i)
	{
		ret[i] += c;
		c = ret[i] / 10;
		ret[i] = ret[i] % 10 + '0';
	}

	int index = 0;
	while (ret[index] == '0') ++index;

	return string(ret.begin() + index, ret.end() - 2);
}

int compare(string & a, string & b)
{
	if (a.length() != b.length())
		return (a.length() > b.length() ? 1 : -1);
	else
	{
		for (int i = 0; i < a.length(); ++i)
			if (a[i] == b[i]) continue;
			else return (a[i] > b[i] ? 1 : -1);
		return 0;
	}
}

int main()
{
	string n, r;
	while (cin >> n >> r)
	{
		r = times628(r);
		if (compare(n, r) == 1) cout << "No" << endl;
		else cout << "Yes" << endl;
	}

	return 0;
}
#endif