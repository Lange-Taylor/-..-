#if 0
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int cnt;
void DFS(vector<vector<int>>& flag, vector<string>& board, int row, int col, int m, int n)
{
	static int nextPosition[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
	if (board[row][col] == '.' && flag[row][col] == 0 || board[row][col] == '@')
		cnt++;
	if (board[row][col] == '#')
		return;
	flag[row][col] = 1;
	for (int i = 0; i < 4; ++i)
	{
		int new_row = row + nextPosition[i][0];
		int new_col = col + nextPosition[i][1];
		if (new_row >= m || new_row < 0 || new_col >= n || new_col < 0)
			continue;
		if (board[new_row][new_col] == '.' && flag[new_row][new_col] == 0)
			DFS(flag, board, new_row, new_col, m, n);
	}
}

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		vector<string> path(m);
		vector<vector<int>> flag(m, vector<int>(n, 0));
		for (auto& e : path) {
			cin >> e;
		}
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (path[i][j] == '@')
					DFS(flag, path, i, j, m, n);
			}
		}
		cout << cnt << endl;
		cnt = 0;
	}
	return 0;
}
#endif

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int n, m, k;
	while (scanf("%d %d %d", &n, &m, &k) != EOF)
	{
		vector<vector<int>> res(n + 1, vector<int>(m + 1, 0));
		vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));
		int x, y;
		for (int i = 0; i < k; ++i)
		{
			scanf("%d %d", &x, &y);
			res[x][y] = 1;
		}
		dp[1][1] = 1.0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (!(i == 1 && j == 1))
					dp[i][j] = dp[i - 1][j] * (j == m ? 1 : 0.5) + dp[i][j - 1] * (i == n ? 1 : 0.5);
				if (res[i][j] == 1)
					dp[i][j] = 0;
			}
		}
		printf("%.2lf\n", dp[n][m]);
	}
}