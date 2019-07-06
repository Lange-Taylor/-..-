#if 1
#include <iostream>
using namespace std;
int main() {
	int W, H,sum;
	cin >> W >> H;
	/*
	if (W == 1) {
		if (H < 3)
			sum = H;
		else
			sum = 2;
	}
	else if (H == 1) {
		if (W < 3)
			sum = W;
		else
			sum = 2;
		}
	else if (W == 2 && H == 2)
		sum = 4;
	else {
		if (W % 2 == 1 && H % 2 == 1) {
			sum = ((W * H)>>1) + 1;
		}
		else
			sum = (W * H)>>1;
	}*/

	if (W % 4 == 0 || H % 4 == 0) {
		sum = (W * H) >> 1;
	}
	else if (W % 2 == 0 && H % 2 == 0) {
		sum = (((W * H) >> 2) + 1) << 1;
	}
	else
		sum = ((W * H) >> 1) + 1;
	cout << sum << endl;
	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
class Solution {
public:
	int StrToInt(string str) {
		int Num = 0;
		int num = 0;
		int flag = 1;
		int n = 1;
		for (int i = str.size() - 1; i >= 0;i--) {
			if (str[i] >= '0' && str[i] <= '9') {
				num += n * (str[i] - '0');
				n *= 10;
			}
			else if (str[i] == '_') {
				num *= (-1);
			}
			else if (str[i] == '+') {
				
			}
			else {
				flag = 0;
				break;
			}
		}
		if (flag) {
			Num = num;
		}
		return Num;
	}
};
#endif