#if 0
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct node
{
	int x;
	int y;
	int count;
};
node dir[4] = { {0,1},{1,0},{-1,0},{0,-1} };
int bfs(vector<string> map, node begin, node end)
{
	queue<node> q;
	q.push(begin);
	map[begin.x][begin.y] = '#';
	while (!q.empty())
	{
		node begin = q.front();
		node next;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			next.x = begin.x + dir[i].x;
			next.y = begin.y + dir[i].y;
			next.count = begin.count + 1;
			if (next.x == end.x && next.y == end.y)
				return next.count;
			if (next.x <= 9 && next.x >= 0 && next.y <= 9 && next.y >= 0 && map[next.x][next.y] == '.')
			{
				map[next.x][next.y] = '#';
				q.push(next);
			}
		}
	}
	return 0;
}

int main()
{
	vector<string> map(10,string(10,'0'));
	node beginp{ 0, 1 ,0 };
	node endp{ 9, 8 ,0 };
	while (cin >> map[0][0])
	{
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				if (i == 0 && j == 0)
					continue;
				else
					cin >> map[i][j];
			}
		}
		cout << bfs(map, beginp, endp) << endl;
	}
	return 0;
}
#endif


#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		for (auto e : str)
		{
			if (e >= '0' && e <= '9')
				cout << e;
		}
		//for(int i = 0; i < str.size(); ++i)
		//{
		//    if(str[i] <= '9' && str[i] >= '0')
		//        cout << str[i];
		//}
		cout << endl;
	}
	return 0;
}
