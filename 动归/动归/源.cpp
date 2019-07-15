#if 0
#include <vector>
//F(i,j): 从(0,0)到(i,j)的最短路径

//F(i,j) = min(grid[i][j - 1],grid[i - 1][j]) + grid[i][j]
void pathsum() {
	int m = 3, n = 2;
	int grid[3][2] = {1,2,3,4,5,6};
	vector<vector<int>> Path(m,vector<int>(n, 0));
	Path[0][0] = grid[0][0];
	for (int i = 0; i < m; ++i) {
		Path[i][0] = grid[i][0] + Path[i - 1][0];
	}
	for (int j = 0; j < n; ++j) {
		Path[0][j] = grid[0][j] + Path[0][j - 1];
	}
	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			if (i = 0) {
				
			}
			else if (j = 0) {
				
			}
			else
				Path[i][j] = grid[i][j - 1] + grid[i - 1][j];
		}
	}
	return Path[i][j];
}
#endif