#if 0
class Solution {
public:
	/**
	 *  奇数位上都是奇数或者偶数位上都是偶数
	 *  输入：数组arr，长度大于2
	 *  len：arr的长度
	 *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
	 */
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		int i = 0;
		int j = 1;
		while (i < len && j < len)
		{
			if (arr[len - 1] % 2 == 0)
			{
				swap(arr[i], arr[len - 1]);
				i += 2;
			}
			else
			{
				swap(arr[j], arr[len - 1]);
				j += 2;
			}
		}
	}
};
#endif


#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	while (cin >> n && n > 0)
	{
		cout << (long)pow(5, n) - 4 << " " << (long)pow(4, n) + n - 4 << endl;
	}
	return 0;
}