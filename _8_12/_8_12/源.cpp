#if 0
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> List(n);
		vector<bool> flag(n, true);
		for (int i = 0; i < n; ++i)
			cin >> List[i];
		sort(List.begin(), List.end());
		for (int i = 0; i < List.size() - 1; ++i)
		{
			if (List[i] == List[i + 1])
				flag[i] = false;
			else if (List[i].size() < List[i + 1].size() && List[i] == List[i + 1].substr(0, List[i].size())
				&& List[i + 1][List[i].size()] == '/')
				flag[i] = false;
		}
		for (int i = 0; i < n; ++i)
			if (flag[i] == true)
				cout << "mkdir -p " << List[i] << endl;
		cout << endl;
	}
	return 0;
}
#endif

#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		char id;
		string str;
		int res = 0;
		int max = 0;
		while (n--)
		{
			
			cin >> id >> str;
			if (str == "connect")
			{
				res++;
				if (res > max)
					max = res;
			}
			else if (str == "disconnect")
			{
				res--;
			}
		}
		cout << max << endl;
	}
	return 0;
}