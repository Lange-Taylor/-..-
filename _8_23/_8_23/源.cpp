
//
//有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？
//
//输入描述 :
//每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n(1 <= n <= 50)，表示学生的个数，接下来的一行，包含 n 个整数，按顺序表示每个学生的能力值 ai（ - 50 <= ai <= 50）。接下来的一行包含两个整数，k 和 d(1 <= k <= 10, 1 <= d <= 50)。
//
//
//输出描述 :
//输出一行表示最大的乘积。
//示例1
//输入
//3
//7 4 7
//2 50
//输出
//49
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> a(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		int k, d;
		cin >> k >> d;
		vector<vector<long long>> dp_max(n, vector<long long>(k + 1, 0));
		vector<vector<long long>> dp_min(n, vector<long long>(k + 1, 0));
		for (int i = 0; i < n; ++i)
		{
			dp_max[i][1] = a[i];
			dp_min[i][1] = a[i];
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 2; j <= k; ++j)
			{
				for (int m = max(0, i - d); m <= i - 1; ++m)
				{
					dp_max[i][j] = max(dp_max[i][j], max(dp_max[m][j - 1] * a[i], dp_min[m][j - 1] * a[i]));
					dp_min[i][j] = min(dp_min[i][j], min(dp_min[m][j - 1] * a[i], dp_max[m][j - 1] * a[i]));
				}
			}
		}
		long long max_value = dp_max[k - 1][k];
		for (int i = k; i < n; ++i)
		{
			max_value = max(max_value, dp_max[i][k]);
		}
		cout << max_value << endl;
	}
	return 0;
}
#endif

#if 0
//
//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;

int a[55];
ll f[55][15][2];

int main() {
	int n, kk, d;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	scanf("%d%d", &kk, &d);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		f[i][1][0] = f[i][1][1] = a[i];
		for (int j = 2; j <= kk; ++j) {
			for (int k = i - 1; k >= max(i - d, 1); --k) {
				f[i][j][0] = max(f[i][j][0], max(f[k][j - 1][0] * a[i], f[k][j - 1][1] * a[i]));
				f[i][j][1] = min(f[i][j][1], min(f[k][j - 1][0] * a[i], f[k][j - 1][1] * a[i]));
			}
		}
		ans = max(ans, max(f[i][kk][0], f[i][kk][1]));
	}
	printf("%lld\n", ans);
	return 0;
}
#endif


//搜狐员工小王最近利用假期在外地旅游，在某个小镇碰到一个马戏团表演，精彩的表演结束后发现团长正和大伙在帐篷前激烈讨论，小王打听了下了解到， 马戏团正打算出一个新节目“最高罗汉塔”，即马戏团员叠罗汉表演。考虑到安全因素，要求叠罗汉过程中，站在某个人肩上的人应该既比自己矮又比自己瘦，或相等。 团长想要本次节目中的罗汉塔叠的最高，由于人数众多，正在头疼如何安排人员的问题。小王觉得这个问题很简单，于是统计了参与最高罗汉塔表演的所有团员的身高体重，并且很快找到叠最高罗汉塔的人员序列。 现在你手上也拿到了这样一份身高体重表，请找出可以叠出的最高罗汉塔的高度，这份表中马戏团员依次编号为1到N。
//
//输入描述 :
//首先一个正整数N，表示人员个数。
//之后N行，每行三个数，分别对应马戏团员编号，体重和身高。
//
//
//输出描述 :
//正整数m，表示罗汉塔的高度。
//示例1
//输入
//6
//1 65 100
//2 75 80
//3 80 100
//4 60 95
//5 82 101
//6 81 70
//输出
//4
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
struct unit
{
	int id;
	int weight;
	int height;
};
bool cmp(unit u1, unit u2) {
	if (u1.weight != u2.weight) return u1.weight < u2.weight;
	else return u1.height > u2.height;
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		vector<unit> vec(n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &vec[i].id, &vec[i].weight, &vec[i].height);
		}
		sort(vec.begin(), vec.end(), cmp);
		vector<int> dp(n, 1);
		int max = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (dp[j] + 1 > dp[i] && vec[i].height >= vec[j].height) {
					dp[i] = dp[j] + 1;
				}
			}
			if (dp[i] > max) max = dp[i];
		}
		printf("%d\n", max);
	}
}