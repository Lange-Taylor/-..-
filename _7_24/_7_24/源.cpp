#if 0
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int T, n, k;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		vector<int> arr(2 * n);
		for (int i = 0; i < 2 * n; i++)
			cin >> arr[i];
		while(k--)
		{
			vector<int> arr1(arr.begin(),arr.end());
			for (int i = 0; i < n; i++)
			{
				arr[2 * i] = arr1[i];
				arr[2 * i + 1] = arr[i + n];
			}
		}
		for (int i = 0; i < 2 * n - 1; i++)
		{
			cout << arr[i] << " ";
			
		}
		cout << arr[2 * n - 1] << endl;
	}
	return 0;
}
#endif

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	int N;
//	cin >> N;
//	string M;
//	cin >> M;
//	int temp = N;
//	if (N <= 4)
//	{
//		for (int i = 0;i<M.size();++i)
//		{
//			if (M[i] == 'U')
//			{
//				N = (N - 1);
//				if (N == 0)
//					N = temp;
//			}
//			if (M[i] == 'D')
//			{
//				N = (N + 1);
//				if (N == temp + 1)
//					N = 1;
//			}
//		}
//		cout << 1 << " "<< 2 << " " << 3 << " " << 4 << endl;
//		cout << N << endl;
//	}
//	else
//	{
//		int count = 0;
//		int ret = 0;
//		for (int i = 0;i<M.size();++i)
//		{
//			if (M[i] == 'U')
//			{
//				N = (N - 1);
//				if (N == 0)
//					N = temp;
//				++count;
//			}
//			if (M[i] == 'D')
//			{
//				N = (N + 1);
//				if (N == temp +1)
//					N = 1;
//				++ret;
//			}
//		}
//		if (count > ret)
//		{
//			cout << temp - 2 << " " << temp - 1 << " " << temp << " " << temp + 1 << endl;
//			cout << N + 1 << endl;
//		}
//		else if (ret - count <= 4)
//		{
//				cout << 1 << " " << 2 << " " << 3 << " " << 4 << endl;
//				cout << N << endl;
//		}
//		else
//		{
//			cout << N - 1 << " " << N << " " << N + 1 << " " << N + 2 << endl;
//			cout << N + 2 << endl;
//		}
//		
//	}
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		cin >> s;
		int cur_head = 1, cur_pos = 0;
		if (n <= 4) {
			for (int i = 0; i < (int)s.size(); i++) {
				if (s[i] == 'U') {
					cur_pos = (cur_pos + n - 1) % n;
				}
				else {
					cur_pos = (cur_pos + 1) % n;
				}
			}
		}
		else {
			for (int i = 0; i < (int)s.size(); i++) {
				if (s[i] == 'U') {
					if (cur_head == 1 && cur_pos == 0) {
						cur_head = n - 3;
						cur_pos = 3;
					}
					else {
						if (cur_pos > 0) {
							cur_pos--;
						}
						else {
							cur_head--;
						}
					}
				}
				else {
					if (cur_head == n - 3 && cur_pos == 3) {
						cur_head = 1;
						cur_pos = 0;
					}
					else {
						if (cur_pos < 3) {
							cur_pos++;
						}
						else {
							cur_head++;
						}
					}
				}
			}
		}
		for (int i = 0; i < min(n, 4); i++) {
			if (i) {
				printf(" ");
			}
			printf("%d", cur_head + i);
		}
		printf("\n%d\n", cur_head + cur_pos);
	}
	return 0;
}