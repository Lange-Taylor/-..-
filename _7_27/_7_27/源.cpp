
#if 0
class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		// write code here
		int row = board.size() + 1;
		int col = board[0].size() + 1;
		vector<vector<int>> dp(row, vector<int>(col, 0));

		for (int i = 1; i < row; ++i)
		{
			for (int j = 1; j < col; ++j)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + board[i - 1][j - 1];
			}
		}
		return dp[row - 1][col - 1];
	}
};
#endif