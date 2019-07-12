


#if 1
#include <iostream>

using namespace std;

int main()
{
	int m;
	cin >> m;
	int max = 0;
	int count = 0;
	while (m)
	{
		
		if (m & 1)
		{
			count++;
			max = count > max ? count : max;
		}
		else
			count = 0;
		m = m >> 1;
	}
	cout << max << endl;
	return 0;
}
#endif