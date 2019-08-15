#if 0
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int row = s1.size();
		int col = s2.size();
		vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
		for (int i = 1; i <= row; ++i)
		{
			for (int j = 1; j <= col; ++j)
			{
				if (s1[i - 1] == s2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		cout << dp[row][col] << endl;
	}
	return 0;
}
#endif

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int change(string str)
{
	int result = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		result = result * 26 + (str[i] - 'a' + 1);
	}
	return result;
}
int change1(int n)
{
	int result = 0;
	string str;
	for (int i = 0; i < n; ++i)
	{
		str += 'z';
	}
	//string str(n, 'z');
	for (int i = 0; i < str.size(); ++i)
	{
		result = result * 26 + (str[i] - 'a' +1);
	}
	return result;
}

int main()
{
	string s1, s2;
	int len1, len2;
	while (cin >> s1 >> s2 >> len1 >> len2)
	{
		int x = s1.size();
		int y = s2.size();
		int num1 = change(s1);
		int num2 = change(s2);
		if (len1 <= x && len2 >= y)
			cout << num2 - num1 - 1 << endl;
		if (len1 <= x && len2 < y)
		{
			int max = change1(len2 );
			cout << max - num1 - 1 << endl;
		}
		if (len1 > x && len2 >= y)
		{
			int min = change1(len1 );
			cout << num2 - min - 1 << endl;
		}
		if (len1 > x && len2 < y)
		{
			int max = change1(len2);
			int min = change1(len1);
			cout << max - min  << endl;
		}
	}
	return 0;
}