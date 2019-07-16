#if 0
#include <iostream>
using namespace std;
int main()
{
	int arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		if (year <= 0)
			return -1;
		if (month > 12 && month <= 0)
			return -1;
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			arr[2] = arr[2] + 1;
		}
		if (day > arr[month])
		{
			return -1;
		}
		for (int i = 1; i < month; i++)
		{
			day += arr[i];
		}
		cout << day << endl;
	}
	return 0;
}
#endif


#if 0
#include<iostream>
#include<algorithm>
using namespace std;
int getLuckPacket(int x[], int n, int pos, int sum, int multi) {
	int count = 0;
	//循环，搜索以位置i开始的所有可能组合
	for (int i = pos; i < n; ++i) {
		sum += x[i];
		multi *= x[i];
		if (sum > multi) {
			//找到以i位置开始的所有组合的可能
			count += 1 + getLuckPacket(x, n, i + 1, sum, multi);
		}
		else if (x[i] == 1) {
			//如果不符合要求，且当前元素为 1
			//这里可能会有疑惑，既然不满足为何不直接break,而是继续
			//因为加 1 之后可能会导致条件继续成立
			//例如 1 1 2 5 1 如果这个下一个为 1，则加 1之后条件成立
			count += getLuckPacket(x, n, i + 1, sum, multi);
		}
		else {
			//因为已经对数组进行升序，所以如果下一位不是1 ，那么条件永远不可能满足
			//直接退出
			break;
		}
		//要搜索下一个位置之前，先恢复 sum 和 multi
		sum -= x[i];
		multi /= x[i];
		//数字相同的球没有任何区别，都只能算一个组合，所以直接跳过
		while (i < n - 1 && x[i] == x[i + 1]) {
			i++;
		}
	}
	return count;
}
int main() {
	int n;
	while (cin >> n) {
		int x[n];
		for (int i = 0; i < n; ++i) {
			cin >> x[i];
		}
		sort(x, x + n);
		//从第一个位置开始搜索
		cout << getLuckPacket(x, n, 0, 0, 1) << endl;
	}
	return 0;
}
#endif

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int getLuckPacket(int x[], int n, int pos, int sum, int multi)
{
	int count = 0;
	for (int i = pos; i < n; i++)
	{
		sum += x[i];
		multi *= x[i];
		//找到以i开始的所有可能组合
		if (sum > multi)
		{
			count += 1 + getLuckPacket(x, n, i + 1, sum, multi);
		}
		else if (x[i] == 1)
		{
			//虽然当前不满足,但当当前为1时,有几率满足
			//例如  1,1,2,5,1   
			count += getLuckPacket(x, n, i + 1, sum, multi);
		}
		else
		{
			break;
		}
		//每次搜索前将上次位置重置
		sum -= x[i];
		multi /= x[i];
		while (i < n - 1 && x[i] == x[i + 1])
		{
			//去重
			i++;
		}
	}
	return count;
}


int main()
{
	int n;
	int x[1000];
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> x[i];
		}
		sort(x, x + n);
		cout << getLuckPacket(x, n, 0, 0, 1);
	}
	
	return 0;
}