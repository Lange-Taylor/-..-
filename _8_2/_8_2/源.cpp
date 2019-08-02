#if 0
#include <iostream>

using namespace std;
int main()
{
	long n;
	while (cin >> n && n)
	{
		if (n == 1)
			cout << 0 << endl;
		else if (n == 2 || n == 3)
			cout << 1 << endl;
		else
		{
			int count = 1;
			while (n > 3)
			{
				count++;
				if (n % 3 == 0)
					n /= 3;
				else
					n = n / 3 + 1;
			}
			cout << count << endl;
		}
	}
	return 0;
}
#endif

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
	/**
	 *	正数数组中的最小不可组成和
	 *	输入：正数数组arr
	 *	返回：正数数组中的最小不可组成和
	 */
	int getFirstUnFormedNum(vector<int> arr, int len) {
		int sum = 0; int min = arr[0];
		for (int i = 0; i < len; ++i)
		{
			sum += arr[i];
			if (arr[i] < min)
				min = arr[i];
		}
		vector<int> dp(sum + 1, 0);
		for (int i = 0; i < len; ++i)
			for (int j = sum; j >= arr[i]; --j)
			{
				if (dp[j - arr[i]] + arr[i] > dp[j])
					dp[j] = dp[j - arr[i]] + arr[i];
			}
		for (int i = min; i <= sum; ++i)
		{
			if (dp[i] != i)
				return i;
		}
		return sum + 1;
	}
};
int main()
{
	int n;
	while (cin >> n)
	{
		Solution S;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		cout << S.getFirstUnFormedNum(arr, n) << endl;
	}
	return 0;
}