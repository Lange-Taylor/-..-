#if 1
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_dict_rank(vector<string>& v)
{
	for (int i = 0; i < v.size() - 1; ++i)
	{
		if (v[i] > v[i + 1])
		{
			return false;
		}
	}
	return true;
}

bool is_len(vector<string>& v)
{
	for (int i = 0; i < v.size() - 1; ++i)
	{
		if (v[i].size() > v[i + 1].size())
		{
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	if (n < 1)
	{
		cout << "none" << endl;
		return 0;
	}

	vector<string> v;
	v.resize(n);
	cin.get();//È¥µô»º³åÇøµÄ\n×Ö·û
	for (int i = 0; i < n; ++i) {
		getline(cin, v[i]);
	}

	if (is_dict_rank(v) )
	{
		if(is_len(v))
			cout << "both" << endl;
		else 
			cout << "lexicographically" << endl;
	}
	else
	{
		if (is_len(v))
			cout << "lengths" << endl;
		else
			cout << "none" << endl;

	}
	/*if (is_dict_rank(v) && is_len(v))
	{
		cout << "both" << endl;
	}
	else if (is_dict_rank(v) && !is_len(v))
	{
		cout << "lexicographically" << endl;
	}
	else if (!is_dict_rank(v) && is_len)
	{
		cout << "lengths" << endl;
	}
	else
	{
		cout << "none" << endl;
	}*/
	return 0;
}
#endif
#if 0
#include <iostream>

using namespace std;
int main() {
	int A, B;
	cin >> A >> B;
	for (int i = 1; i <= A*B; ++i) {
		if (i >= A && i >= B && i%A == 0 && i%B == 0)
		{
			cout << i << endl;
			break;
		}
	}
	return 0;
}

#endif