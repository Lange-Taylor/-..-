#if 1
#include <iostream>
#include <string>
using namespace std;

int main() {

	string str, cur, res;
	cin >> str;
	for (int i = 0; i <= str.length(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			cur += str[i];
		}
		else {
			if (res.length() < cur.length()) {
				res = cur;
			}
			cur = "";
		}
	}
	cout << res << endl;
	return 0;
}
#endif

#if 0
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str, res, cur;
	cin >> str;
	for (int i = 0; i <= str.length(); i++) {
		if (str[i] >= '0' && str[i] <= '9')cur += str[i];
		else {
			if (res.length() < cur.length())res = cur;
			cur = "";
		}
	}
	cout << res;
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty()) return 0;
		//int result = numbers[0];
		//int count = 1;
		//for (int i = 1; i < numbers.size(); i++) {
		//	if (count == 0) {
		//		result = numbers[i];
		//		count == 1;
		//	}
		//	else {
		//		if (result == numbers[i]) {
		//			count++;
		//		}
		//		else {
		//			count--;
		//		}
		//	}
		//}
		sort(numbers.begin(), numbers.end());
		int result = numbers[numbers.size()/2];

		int count = 0;
		for (int i = 0; i < numbers.size(); i++) {
			if (numbers[i] == result) {
				count++;
			}
		}
		return (count > numbers.size() / 2) ? result : 0;
	}
};
#endif