#if 0
#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		long long arr[91] = {0,1,2};
		if (n > 2)
		{
			int i;
			for (i = 3; i <= n; ++i)
			{
				arr[i] = arr[i - 2] + arr[i - 1];
			}
			cout << arr[n] << endl;
			continue;

		}
		cout << arr[n] << endl;

	}

	return 0;
}
#endif

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		getchar();
//		string name;
//		for (int i = 0; i < n; ++i)
//		{
//			getline(cin,name);
//			if (name.find(',') != string::npos || name.find(' ') != string::npos)
//				cout << "\"" << name << "\"";
//			if(i == n - 1)
//				cout << ", ";
//		}
//		cout << endl;
//	}
//	return 0;
//}

// write your code here cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		getchar();
		string name;
		for (int i = 0; i < n; ++i)
		{
			getline(cin, name);
			if (i != n - 1)
			{
				if (name.find(',') != string::npos || name.find(' ') != string::npos)
					cout << "\"" << name << "\"" << "," << " ";
				else
					cout << name << "," << " ";
			}
			else
			{
				if (name.find(',') != string::npos || name.find(' ') != string::npos)
					cout << "\"" << name << "\"" << endl;
				else
					cout << name << endl;
			}
		}
	}
	return 0;
}