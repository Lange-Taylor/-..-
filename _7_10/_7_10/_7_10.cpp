#include <iostream>
using namespace std;

#if 0
int addAB(int A, int B) {
	// write code here
	while (A != 0)
	{
		int ret = A ^ B;
		A = (A&B) << 1;
		B = ret;
	}
	return B;
}

int main() 
{
	cout << addAB(3, 5);
	return 0;
}
#endif

#include <vector>
int main() 
{	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> sum(n + 1, vector<int>(m + 1, 1));
	
	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; j < m + 1; ++j)
		{
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j];
		}
	}
	cout << sum[n][m] << endl;

	return 0;
}