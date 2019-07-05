#if 0
#include <iostream>
#include <string>
using namespace std;
bool IsPalindrome(string str) {
	int begin = 0;
	int end = str.size() - 1;
	while (begin < end) {
		if (str[begin] != str[end]) {
			return false;
		}
		else {
			begin++;
			end--;
		}
	}
	return true;
}
int main() {
	string str1, str2, temp;
	getline(cin , str1);
	getline(cin , str2);
	string str;
	int count = 0;
	temp = str1;
	int len = str1.size() + 1;
	for (int i = 0; i < len ; i++) {
		str1 = temp;
		str = str1.insert(i, str2);
		if (IsPalindrome(str)) {
			count++;
		}
	}
	cout << count << endl;
	return 0;
}
#endif

#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	if (n < 2) {
		return 0;
	}
	int arr[100001];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int sum = 0;
	int max = arr[0];
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum > max) {
			max = sum;
		}
		if (sum < 0) {
			sum = 0;
		}
	}
	
	cout << max  << endl;
	
	return 0;
}
