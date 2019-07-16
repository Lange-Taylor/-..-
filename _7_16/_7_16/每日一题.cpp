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
	//ѭ����������λ��i��ʼ�����п������
	for (int i = pos; i < n; ++i) {
		sum += x[i];
		multi *= x[i];
		if (sum > multi) {
			//�ҵ���iλ�ÿ�ʼ��������ϵĿ���
			count += 1 + getLuckPacket(x, n, i + 1, sum, multi);
		}
		else if (x[i] == 1) {
			//���������Ҫ���ҵ�ǰԪ��Ϊ 1
			//������ܻ����ɻ󣬼�Ȼ������Ϊ�β�ֱ��break,���Ǽ���
			//��Ϊ�� 1 ֮����ܻᵼ��������������
			//���� 1 1 2 5 1 ��������һ��Ϊ 1����� 1֮����������
			count += getLuckPacket(x, n, i + 1, sum, multi);
		}
		else {
			//��Ϊ�Ѿ�����������������������һλ����1 ����ô������Զ����������
			//ֱ���˳�
			break;
		}
		//Ҫ������һ��λ��֮ǰ���Ȼָ� sum �� multi
		sum -= x[i];
		multi /= x[i];
		//������ͬ����û���κ����𣬶�ֻ����һ����ϣ�����ֱ������
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
		//�ӵ�һ��λ�ÿ�ʼ����
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
		//�ҵ���i��ʼ�����п������
		if (sum > multi)
		{
			count += 1 + getLuckPacket(x, n, i + 1, sum, multi);
		}
		else if (x[i] == 1)
		{
			//��Ȼ��ǰ������,������ǰΪ1ʱ,�м�������
			//����  1,1,2,5,1   
			count += getLuckPacket(x, n, i + 1, sum, multi);
		}
		else
		{
			break;
		}
		//ÿ������ǰ���ϴ�λ������
		sum -= x[i];
		multi /= x[i];
		while (i < n - 1 && x[i] == x[i + 1])
		{
			//ȥ��
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