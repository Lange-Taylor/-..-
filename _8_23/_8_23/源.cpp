
//
//�� n ��ѧ��վ��һ�ţ�ÿ��ѧ����һ������ֵ��ţţ����� n ��ѧ���а���˳��ѡȡ k ��ѧ����Ҫ����������ѧ����λ�ñ�ŵĲ���� d��ʹ���� k ��ѧ��������ֵ�ĳ˻�������ܷ������ĳ˻���
//
//�������� :
//ÿ��������� 1 ������������ÿ���������ݵĵ�һ�а���һ������ n(1 <= n <= 50)����ʾѧ���ĸ�������������һ�У����� n ����������˳���ʾÿ��ѧ��������ֵ ai�� - 50 <= ai <= 50������������һ�а�������������k �� d(1 <= k <= 10, 1 <= d <= 50)��
//
//
//������� :
//���һ�б�ʾ���ĳ˻���
//ʾ��1
//����
//3
//7 4 7
//2 50
//���
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


//�Ѻ�Ա��С��������ü�����������Σ���ĳ��С������һ����Ϸ�ű��ݣ����ʵı��ݽ��������ų����ʹ��������ǰ�������ۣ�С�����������˽⵽�� ��Ϸ���������һ���½�Ŀ������޺�����������Ϸ��Ա���޺����ݡ����ǵ���ȫ���أ�Ҫ����޺������У�վ��ĳ���˼��ϵ���Ӧ�üȱ��Լ����ֱ��Լ��ݣ�����ȡ� �ų���Ҫ���ν�Ŀ�е��޺���������ߣ����������ڶ࣬����ͷ����ΰ�����Ա�����⡣С�������������ܼ򵥣�����ͳ���˲�������޺������ݵ�������Ա��������أ����Һܿ��ҵ�������޺�������Ա���С� ����������Ҳ�õ�������һ��������ر����ҳ����Ե���������޺����ĸ߶ȣ���ݱ�����Ϸ��Ա���α��Ϊ1��N��
//
//�������� :
//����һ��������N����ʾ��Ա������
//֮��N�У�ÿ�����������ֱ��Ӧ��Ϸ��Ա��ţ����غ���ߡ�
//
//
//������� :
//������m����ʾ�޺����ĸ߶ȡ�
//ʾ��1
//����
//6
//1 65 100
//2 75 80
//3 80 100
//4 60 95
//5 82 101
//6 81 70
//���
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