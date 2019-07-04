#if 0
#include <iostream>

using namespace std;
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A, B1, B2, C;
	A = (a + c) >> 1;
	B1 = (b + d) >> 1;
	B2 = (c - a) >> 1;
	C = (d - b) >> 1;
	if (B1 == B2) {
		cout << A << ' ' << B1 << ' ' << C << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
#endif

#include <iostream>
#include <string>
using namespace std;

int main() {
	int M, N;
	cin >> M >> N;
	string s = "", table = "0123456789ABCDEF";
	while (M) {
		if (M < 0) {
			M = -M;
			cout << '-';
		}
		s = table[M%N] + s;
		M /= N;
	}
	cout << s << endl;
	return 0;
}