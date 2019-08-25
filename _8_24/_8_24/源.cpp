#if 0
class Printer {
public:
	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
		// write code here
		vector<int> vec;
		int sx = 3, sy = 0;
		int temp[4] = { 1,0,-1,0 };
		int dx = temp[sx], dy = temp[sy];
		int x = 0, y = 0;
		for (int i = 0; i < n*m; ++i)
		{
			vec.push_back(mat[x][y]);
			mat[x][y] = INT_MAX;
			if (dx + x > n - 1 || dx + x < 0 || dy + y > m - 1 || dy + y < 0 || mat[x + dx][y + dy] == INT_MAX)
			{
				sx = (sx + 1) % 4;
				sy = (sy + 1) % 4;
				dx = temp[sx];
				dy = temp[sy];
			}
			x += dx;
			y += dy;
		}
		return vec;
	}
};
#endif

#if 0
class MaxGap {
public:
	int findMaxGap(vector<int> A, int n) {
		// write code here
		int max = A[0];
		int min;
		for (int i = 0; i < n; ++i)
		{
			if (A[i] > max)
				max = A[i];
			min = A[0] > A[n - 1] ? A[n - 1] : A[0];
		}
		return max - min;
	}
};
#endif