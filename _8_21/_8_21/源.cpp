


#if 0
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		int vec1[256] = { 0 };
		int vec2[256] = { 0 };
		for (int i = 0; i < str1.size(); ++i)
			vec1[str1[i]++];
		for (int i = 0; i < str2.size(); ++i)
			vec2[str2[i]++];
		int i;
		for (i = 0; i < str2.size(); ++i)
		{
			if (vec1[str2[i]] < vec2[str2[i]])
				cout << "No" << endl;
		}
		if (i == str2.size())
			cout << "Yes" << endl;
	}
	return 0;
}



#endif


#if 0
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		map<char, int> map1, map2;
		for (int i = 0; i < str1.size(); ++i)
			map1[str1[i]++];
		for (int i = 0; i < str2.size(); ++i)
			map2[str2[i]++];
		int i;
		for (i = 'A'; i <= 'Z'; ++i)
		{
			if (map1[i] < map2[i])
			{
				cout << "No" << endl;
				break;
			}
			if (i == 'Z')
				cout << "Yes" << endl;
		}
	}
	return 0;
}
#endif

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isBrother(string s1, string s2)
{
	if (s1 == s2)
		return false;
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	if (s1 == s2)
		return true;
	else
		return false;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> vec(n);
		for (int i = 0; i < n; ++i)
			cin >> vec[i];
		vector<string> b;
		int m;
		string str;
		cin >> str;
		cin >> m;
		for (int i = 0; i < n; ++i)
		{
			if (isBrother(str, vec[i]))
				b.push_back(vec[i]);
		}
		sort(b.begin(), b.end());
		cout << b.size() << endl;
		if (m <= b.size())
			cout << b[m - 1] << endl;
	}
	return 0;
}