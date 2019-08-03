#if 0
class Solution {
public:
	void DFS(vector<vector<char>>& board, int row, int col, int x, int y)
	{
		static int nextpos[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
		board[x][y] = '*';
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + nextpos[i][0];
			int ny = y + nextpos[i][1];
			if (nx >= row || nx < 0 || ny >= col || ny < 0)
				continue;
			if (board[nx][ny] == 'O')
				DFS(board, row, col, nx, ny);
		}
	}
	void solve(vector<vector<char>>& board) {
		if (board.empty())
			return;
		int row = board.size();
		int col = board[0].size();
		for (int i = 0; i < col; ++i)
		{
			if (board[0][i] == 'O')
				DFS(board, row, col, 0, i);
			if (board[row - 1][i] == 'O')
				DFS(board, row, col, row - 1, i);
		}
		for (int j = 0; j < row; ++j)
		{
			if (board[j][0] == 'O')
				DFS(board, row, col, j, 0);
			if (board[j][col - 1] == 'O')
				DFS(board, row, col, j, col - 1);
		}
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (board[i][j] == '*')
					board[i][j] = 'O';
				else if (board[i][j] == 'O')
					board[i][j] = 'X';
			}
		}
	}
};

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str))
	{
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] == ' ')
				continue;
			str[i] -= 5;
			if (str[i] < 'A')
				str[i] += 26;
		}
		cout << str << endl;
	}
	return 0;
}
#endif
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int x, y, z;
	while (cin >> x)
	{
		z = 0;
		for (y = 2; y < sqrt(x); ++y)
		{
			if (x % y == 0)
			{
				while (x % y == 0)
					x = x / y;
				z++;
			}
		}
		if (x != 1)
			z++;
		cout << z << endl;
	}
	return 0;
}