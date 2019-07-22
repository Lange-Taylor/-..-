
//
//bool fun(int n)
//{
//	int sum = 0;
//	for (int i = 1; n > sum; i = i + 2)
//		sum = sum + i;
//	return (n == sum);
//}
//int main()
//{
//	cout << fun(483) << endl;
//	return 0;
//
//}
#if 0
#include <iostream>
using namespace std;
int main()
{
	int M;
	while (cin>> M)
	{
		int ret = 0;
		int a, b;
		if (M == 0)
			break;
		
		while (M>=3)
		{
			a = M / 3;
			b = M % 3;
			ret += a;
			M = a + b;
		}
		if (M == 2)
			ret += 1;
		cout << ret << endl;
	}
	return 0;
}
#endif
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void findMaxCommonStr(string str1, string str2)
{
	if (str1.size() > str2.size())
		swap(str1, str2);
	int maxlen = 0, start = 0;
	vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
	for (int i = 1; i <= str1.size(); ++i)
	{
		for (int j = 1; j <= str2.size(); ++j)
		{
			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			if (dp[i][j] > maxlen)
			{
				maxlen = dp[i][j];
				start = i - maxlen;
			}
		}
	}
	cout << str1.substr(start, maxlen) << endl;
}

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		findMaxCommonStr(str1, str2);
	}
	return 0;
}