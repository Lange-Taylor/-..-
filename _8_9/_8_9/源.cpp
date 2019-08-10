// write your code here cpp
#if 0
#include <iostream>
#include <cstdio>

using namespace std;
int main()
{
	long long vec[21][2] = { {1,0}, {1,0}, {2,1}, {6,2} };
	for (int i = 4; i < 21; ++i)
	{
		vec[i][0] = i * (vec[i - 1][0]);
		vec[i][1] = (i - 1)*(vec[i - 2][1] + vec[i - 1][1]);
	}
	int n;
	while (cin >> n)
	{
		double res = (double)vec[n][1] / vec[n][0] * 100.00;
		//printf("%02.2lf%\n", res);
		printf("%.2lf%%\n", res);
	}
	return 0;
}
#endif

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1;
	while (getline(cin, s1))
	{
		string s2;
		getline(cin, s2);
		bool flag = false;
		for (int i = 0; i < s1.size(); ++i)
		{
			string temp;
			if (s1[i] == '"')
			{
				i++;
				while (i < s1.size() && s1[i] != '"')
				{
					temp += s1[i];
					i++;
				}
				if (temp == s2)
				{
					flag = true;
					break;
				}
			}
			else if (s1[i] != ',')
			{
				while (i < s1.size() && s1[i] != ',')
				{
					temp += s1[i];
					i++;
				}
				if (temp == s2)
				{
					flag = true;
					break;
				}
			}
		}
		if (flag == true)
			cout << "Ignore" << endl;
		else
			cout << "Important!" << endl;
	}
	return 0;

}