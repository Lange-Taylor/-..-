#if 0
#include <iostream>

using namespace std;

int main() {
	int year1, month1, day1, year2, month2, day2;
	int d[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
	{
		int sum = 0;
		int year = year1;

		for (int i = year1; i <= year2 - 1; ++i) {
			if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) sum += 580;
			else  sum += 579;
		}

		for (int i = 0; i <= month1 - 1; ++i) {
			int temp = 0;
			if (i == month1 - 1) temp = day1 - 1;
			else temp = d[i];
			if (i != 1 && i != 2 && i != 4 && i != 6 && i != 10) { sum -= temp * 2; }
			else sum -= temp;
		}

		for (int i = 0; i <= month2 - 1; ++i) {
			int temp = 0;
			if (i == month2 - 1) temp = day2;
			else temp = d[i];
			if (i != 1 && i != 2 && i != 4 && i != 6 && i != 10) { sum += temp * 2; }
			else sum += temp;
		}

		cout << sum << endl;

	}


	return 0;
}
#endif

#if 0
// write your code here cpp
#include <iostream>

using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 1 || n == 2)
		{
			cout << 1 << endl;
			continue;
		}
		int first = 1;
		int second = 1;
		for (int i = 3; i <= n; ++i)
		{
			int temp = first;
			first = second;
			second = temp + second;
		}
		/*if (second > 1000000)
		{
			second = second % 1000000;
		}*/
		/*if (n < 37)
			printf("%d\n", second);
		else
			printf("%06d\n", second);*/
		printf("%d\n", second);
		//cout << second << endl;
	}
	return 0;
}
#endif



#include<stdio.h>
int main() {
	/*int arr[100001];
	int n = 0;
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= 100000; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
		arr[i] = arr[i] % 1000000;
	}
	while (scanf("%d", &n) != EOF) {
		printf((n < 29 ? "%d\n" : "%06d\n"), arr[n]);
	}*/
	int n = 12678 % 1000000;
	printf("%d\n",n);
	printf("%06d", n);
	return 0;
}