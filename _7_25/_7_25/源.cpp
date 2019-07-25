#if 0
#include <iostream>
#include <vector>
using namespace std;

int divisor(int m, int n)
{
	int temp;
	while (n)
	{
		temp = n;
		n = m % n;
		m = temp;
	}
	return m;
}

int main()
{
	int n, a;
	while (cin >> n >> a)
	{
		int c = a;
		vector<int> b;
		b.resize(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> b[i];
			if (b[i] <= c)
			{
				c += b[i];
			}
			if (b[i] > c)
			{
				c += divisor(b[i], c);
			}
		}
		cout << c << endl;
	}

	return 0;
}
#endif


#if 1
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str;
	while (cin >> str)
	{
		vector<int> count;
		count.resize(256);
		for (int i = 0; i < str.size(); ++i)
		{
			count[str[i]]++;
		}
		int flag = 1;
		int i;
		for (i = 0; flag && i < str.size(); ++i)
		{
			if (count[str[i]] == 1)
			{
				flag = 0;
				cout << str[i] << endl;
				continue;
			}
		}
		if(flag)
			cout << -1 << endl;
	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	while (getline(cin,str))
	{
		int i;
		for (i = 0; i < str.size(); ++i)
		{
			if (str.find(str[i]) == str.rfind(str[i]))
			{
				cout << str[i] << endl;
				break;
			}
		}
		if(i == str.size())
			cout << -1 << endl;
	}
	return 0;
}
#endif