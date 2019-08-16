#if 0
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> arr(n, 0);
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		vector<int> p(n, 1);
		int result = 1;
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (arr[i] > arr[j])
					p[i] = max(p[i], p[j] + 1);
			}
			result = max(result, p[i]);
		}
		cout << result << endl;
	}
	return 0;
}
#endif

#include <iostream>
using namespace std;
//0 0 1 2 9 44 
int main()
{
	int n;
	while (cin >> n)
	{
		long long arr[21] = { 0,0,1 };
		for (int i = 3; i <= n; ++i)
			arr[i] = (i - 1)*(arr[i - 1] + arr[i - 2]);
		cout << arr[n] << endl;
	}
	return 0;
}