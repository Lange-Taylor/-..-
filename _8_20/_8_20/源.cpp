#if 0
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	while (cin >> str)
	{
		string res;
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] != '_')
				res += str[i];
			else
			{
				i++;
				res += (char)toupper(str[i]);

			}
		}
		cout << res << endl;
	}
	return 0;
}
#endif

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		vector<string> arr;
		string temp;
		for (int i = 0; i <= str.size(); ++i)
		{
			if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
				temp += str[i];
			else
			{
				if (temp.size() > 0)
				{
					arr.push_back(temp);
					temp.clear();
				}
			}
		}
		for (int i = arr.size() - 1; i > 0; --i)
		{
			cout << arr[i] << ' ';
		}
		cout << arr[0] << endl;
	}
	return 0;
}