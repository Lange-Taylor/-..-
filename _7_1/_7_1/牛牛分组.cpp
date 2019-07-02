#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


void niuniufenzu() {
	int n, ans = 0;
	int a_i[3000] = { 0 };
	cin >> n;
	for (int i = 0; i < 3 * n; i++) {
		cin >> a_i[i];
	}
	sort(a_i, a_i + 3 * n);
	for (int j = n; j < 3 * n; j += 2) {
		ans += a_i[j];
	}
	cout << ans << endl;
}
int main() {

	
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);

	int count[256] = {0};
	int i = 0;

	while (s2[i] != '\0') {
		count[s2[i]]++;
		i++;
	}
	int begin = 0;
	int end = 0;

	while (s1[end] != '\0') {
		if (count[s1[end]] == 0) {
			s1[begin] = s1[end];
			begin++;
		}
		end++;
	}

	s1 = s1.substr(0, begin);
	cout << s1 << endl;
	return 0;
}