#if 0


#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> vec;
		vec.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> vec[i];
		stack<int> s;
		string str;
		for (int i = 0; i < n; ++i)
		{
			str = vec[i];
			if (!(str == "+" || str == "-" || str == "*" || str == "/"))
			{
				s.push(atoi(str.c_str()));
			}
			else
			{
				int right = s.top();
				s.pop();
				int left = s.top();
				s.pop();
				if (str == "+")
					s.push(left + right);
				else if (str == "-")
					s.push(left - right);
				else if (str == "*")
					s.push(left * right);
				else if (str == "/")
				{
					if (right != 0)
						s.push(left / right);
					else
						return 0;
				}
			}
		}
		cout << s.top() << endl;
	}
	return 0;
}

#endif

// write your code here cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int count(string table[], char ch, int x, int y)
{
	int maxc = 0;
	int dir[4][2][2] = { {{ -1,0 },{ 1,0 }},{{ 0,-1 },{ 0,1 }},{{ -1,-1 },{ 1,1 }},{{ -1,1 },{ 1,-1 }} };
	for (int i = 0; i < 4; ++i) // 四种方向
	{
		int c = 0;
		for (int j = 0; j < 2; ++j)  // 两个小方向
		{
			int nx = x, ny = y;
			while (nx >= 0 && nx < 20 && ny >= 0 && ny < 20 && table[nx][ny] == ch)
			{
				nx += dir[i][j][0];
				ny += dir[i][j][1];
				++c;
			}
		}
		maxc = (maxc > c ? maxc : c);
	}
	return maxc - 1;
}


bool solve(string table[])
{
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			if (table[i][j] == '*' || table[i][j] == '+')
			{
				if (count(table, table[i][j], i, j) >= 5)
					return true;
			}
		}
	}
	return false;
}

int main()
{
	string table[20];
	while (cin >> table[0])
	{
		for (int i = 1; i < 20; ++i)
			cin >> table[i];
		cout << (solve(table) ? "Yes" : "No") << endl;
	}

	return 0;
}



