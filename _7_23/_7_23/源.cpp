#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		int maxlen = 0;
		vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
		for(int i = 1;i<str1.size();++i)
			for (int j = 1; j < str2.size(); ++j)
			{
				if (str1[i -1] == str2[j -1])//左上角确定下一个状态  错位
					dp[i][j] = dp[i - 1][j - 1] + 1;
				if (dp[i][j] > maxlen)
				{
					maxlen = dp[i][j];
				}
			}
		cout << maxlen << endl;
	}
	return 0;
}