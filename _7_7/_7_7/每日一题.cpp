
#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int Fi = 0;
	int Fj = 1;
	int s, l;
	int L = 0;
	while (1) {
		s = Fi + Fj;
		Fi = Fj;
		Fj = s;
		if (s < N) {
			L = N - s;
		}
		else {
			l = s - N;
			break;
		}
	}
	if (L > l) {
		cout << l << endl;
	}
	else {
		cout << L << endl;
	}
	return 0;
}


#if 0
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		int flag = 0;
		for (int i = 0; i < n; ++i) {
			if (A[i] == '(') {
				++flag;
			}
			else if (A[i] == ')') {
				--flag;
			}
			else {
				return false;
			}
		}
		return flag == 0;
	}
};
#endif