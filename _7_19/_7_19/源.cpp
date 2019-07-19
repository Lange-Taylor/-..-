#if 0
#include <stdio.h>
int main() {
	long long a = 1, b = 2, c = 2;
	printf("%d %lld %lld\n", a, b, c);

	return 0;
}
#endif


#if 0
#include <iostream>
using namespace std;
int main()
{
	int M;
	while (cin >> M)
	{
		if (M < 3)
		{
			cout << -1 << endl;
			continue;
		}
		if (M % 4 == 0)
		{
			cout << 3 << endl;
			continue;
		}
		if (M % 2 == 1)
		{
			cout << 2 << endl;
			continue;
		}
		if (M % 2 == 0 && M % 4 != 0)
		{
			cout << 4 << endl;
			continue;
		}
	}
	return 0;
}
#endif


#include <iostream>
#include <string>
using namespace std;
int main()
{
	string addend, augend;
	while (cin >> addend >> augend)
	{
		while (addend.size() > augend.size())
			augend = '0' + augend;
		while (addend.size() < augend.size())
			addend = '0' + addend;
		int ret = 0;
		for (int i = addend.size() - 1; i >= 0; --i)
		{
			int temp = addend[i] - '0' + augend[i] - '0' + ret;
			addend[i] = temp % 10 + '0';
			if (temp / 10)
			{
				ret = 1;
			}
			else
				ret = 0;
		}
		if (ret == 1)
			addend = '1' + addend;
		cout << addend << endl;
	}
	return 0;
}