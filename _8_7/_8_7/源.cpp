#if 0
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		int sum = 0;
		int pos = 0;
		while ((pos = s.find(t, pos)) != string::npos)
		{
			pos += t.size();
			sum++;
		}
		cout << sum << endl;
	}
	return 0;
}
#endif


#include <iostream>
using namespace std;
int main()
{
	long long arr[80] = { 1,1 };
	for (int i = 2; i < 80; ++i)
	{
		arr[i] = arr[i - 2] + arr[i - 1];
	}
	int from, to;
	while (cin >> from >> to)
	{
		long long res = 0;
		for (int i = from; i <= to; ++i)
		{
			res += arr[i - 1];
		}
		cout << res << endl;
	}
	return 0;
}
