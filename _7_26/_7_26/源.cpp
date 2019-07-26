#if 0
class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		// write code here
		int res = gifts[0];
		int count = 1;
		for (int i = 1; i < n; ++i)
		{
			if (count == 0)
			{
				res == gifts[i];
				count = 1;
			}
			else
			{
				if (gifts[i] == res)
					count++;
				else
					count--;
			}
		}
		count = 0;
		for (int i = 0; i < n; ++i)
		{
			if (res == gifts[i])
				count++;
		}
		return (count > (n / 2)) ? res : 0;
	}
};
#endif

////#include <algorithm>  ÅÅÐòÍ·ÎÄ¼þ

//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	string str1, str2;
//	getline(cin, str1);
//	getline(cin, str2);
//	int row = str1.size();
//	int col = str2.size();
//
//	vector<vector<int>> dp(row + 1,vector<int>(col + 1,0));
//	for (int i = 0; i <= row; ++i)
//	{
//		dp[i][0] = i;
//	}
//	for (int i = 0; i <= col; ++i)
//	{
//		dp[0][i] = i;
//	}
//	for (int i = 1; i <= row; ++i)
//	{
//		for (int j = 1; j <= col; ++j)
//		{
//			dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + 1;
//			if (str1[i - 1] == str2[j - 1])
//			{
//				
//				dp[i][j] = min(dp[i - 1][j - 1],dp[i][j]);
//			}
//			else
//			{
//				dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i][j]);
//			}
//		}
//	}
//	cout << dp[row][col] << endl;
//	return dp[row][col];
//}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string str1, str2;
	while (getline(cin, str1) && getline(cin, str2))
	{
		int row = str1.size();
		int col = str2.size();
		vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
		for (int i = 0; i <= row; ++i)
			dp[i][0] = i;
		for (int i = 0; i <= col; ++i)
			dp[0][i] = i;
		for (int i = 1; i <= row; ++i)
		{
			for (int j = 1; j <= col; ++j)
			{
				dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + 1;
				if (str1[i - 1] == str2[j - 1])
				{
					dp[i][j] = min(dp[i - 1][j - 1], dp[i][j]);
				}
				else
				{
					dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i][j]);
				}
			}
		}
		cout << dp[row][col] << endl;
	}
	return 0;
}