#if 0
#include <iostream>
using namespace std;
int Add(int num1, int num2)
{
	/*if(0 == num2)
		return num1;
	int sum = num1^num2;
	int res = num1&num2;
	return Add(sum,res<<1);
	*/
	//char* a = (char*)num1;
	//return (int)&a[num2];
	char* a = reinterpret_cast<char*>(num1);
	return reinterpret_cast<long>(&(a[num2]));
}
int main()
{
	cout << Add(-102, 26849468) << endl;
	return 0;
}
#endif

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	double a[3] = { 0 };;
	while (cin >> a[0] >> a[1] >> a[2])
	{
		sort(a, a + 3);
		if (a[0] + a[1] > a[2])   // && (a[2] - a[0] < a[1])
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}