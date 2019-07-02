//#include <iostream>
//using namespace std;
//
//int main() {
//
//	int n = 6;
//	//int A_i[100] = { 0 };
//	//cin >> n;
//	int A_i[100] = {1,2,3,2,2,1 };
//	//for (int i = 0; i < n; ++i) {
//	//	cin >> A_i[i];
//	//}
//	int count = 0;
//	for (int j = 1; j < n-1; ++j) {
//
//		if (n<3) {
//			count = 1;
//		}
//		else {
//			
//				if (A_i[j] > A_i[j - 1] && A_i[j] > A_i[j + 1]
//					|| A_i[j] < A_i[j - 1] && A_i[j] < A_i[j + 1]) {
//					count++;
//					j++;
//				}
//				if (n - 3 != j)
//					j++;
//		
//			
//		}
//		
//	}
//	cout << count + 1 << endl;
//	//1,2,2,3,3,  2,1,1,  2,3,5,5,6   ,4,7,  6,8,9,  7,5  ,8,9  ,3,0,6
//	return 0;
//}
//
//

//////#include <iostream>
//////using namespace std;
//////
//////#define N 100001
//////
//////bool isChange(int previous, int current, int next) {
//////	if ((current > previous && current > next) ||
//////		(current < previous && current < next)) {
//////		return true;
//////	}
//////	return false;
//////}
//////
//////int main {
//////	int n, arr[N];
//////	while (cin >> n) {
//////		int ans = 1, previous = 0;
//////		// 序列长度小于3，输出1
//////		if (n < 3) cout << "1" << endl;
//////		for (int i = 0; i < n; i++)
//////			cin >> arr[i];
//////		for (int i = 1; i < n - 1; i++) {
//////			// 当前数字与下一个数字相等，则跳过
//////			if (arr[i] == arr[i + 1]) {
//////				continue;
//////			}
//////			else {
//////				// 若发生跳变，计数+1，指针+1。
//////				if (isChange(arr[previous], arr[i], arr[i + 1])) {
//////					ans++;
//////					previous = ++i;
//////				}
//////			}
//////		}
//////		cout << ans << endl;
//////	}
//////	return 0;
//////}



//#include <iostream>
//using namespace std;
//
//int main() {
//
//	int n = 25;
//	int A_i[100001] = { 0 };
//	cin >> n;
//	int A_i[100] = { 1,2,2,3,3,2,1,1,2,3,5,5,6,4,7,6,8,9,7,5,8,9,3,0,6 };
//	int A_i[100] = {1,2,3,2,2,1 };
//	for (int i = 0; i < n; ++i) {
//		cin >> A_i[i];
//	}
//	int count = 1;
//	for (int j = 1; j < n - 1; ++j) {
//		if (A_i[j] > A_i[j - 1] && A_i[j] > A_i[j + 1]
//			|| A_i[j] < A_i[j - 1] && A_i[j] < A_i[j + 1]) {
//			count++;
//			if (n - 3 != j) j++;
//		}
//	}
//	cout << count << endl;
//	return 0;
//}

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string str;
	stack<string> sta;
	while (cin >> str) {
		sta.push(str);
		if (*(str.rbegin()) == '.') {
			break;
		}
	}
	cout << sta.top();
	sta.pop();
	while (!sta.empty()) {
		cout << ' ' << sta.top();
		sta.pop();
	}

	return 0;
}


