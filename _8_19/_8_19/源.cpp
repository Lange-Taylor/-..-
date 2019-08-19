#if 0
#include <iostream>
#include <string>
#include <set>

using namespace std;
int main()
{
	string str;
	int n;
	while (cin >> n)
	{
		string num = "22233344455566677778889999";
		set<string> data;
		int count;
		for (int i = 0; i < n; ++i)
		{
			string res;
			cin >> str;
			count = 0;
			for (int j = 0; j < str.size(); ++j)
			{
				if (str[j] >= 'A' && str[j] <= 'Z')
				{
					res += num[str[j] - 'A'];
					count++;
					if (count == 3)
						res += '-';
				}
				else if (str[j] >= '0' && str[j] <= '9')
				{
					res += str[j];
					count++;
					if (count == 3)
						res += '-';
				}
			}
			data.insert(res);
		}
		for (auto e : data)
			cout << e << endl;
		cout << endl;
	}
	return 0;
}
#endif


#include<iostream>
#include<vector>
using namespace std;
void help(int n, int m, vector<int>& v, int beg) {
	//if (beg>n) return;
	if (m == 0) {
		for (int i = 0; i < v.size(); i++) {
			i == 0 ? cout << v[i] : cout << " " << v[i];
		}
		cout << endl;
	}
	for (int i = beg; i <= n && i <= m; i++) {
		v.push_back(i);
		help(n, m - i, v, i + 1);
		v.pop_back();
	}
}
int main() {
	int n, m;
	while (cin >> n >> m) {
		vector<int>v;
		help(n, m, v, 1);
	}
}
