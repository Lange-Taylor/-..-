#if 1

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<pair<string, int>> errors;
	string str, file;
	while (getline(cin, str))
	{
		if (str.size() == 0)
			break;
		unsigned f = str.rfind('\\');
		file = str.substr(f + 1);
		errors.push_back(make_pair(file, 1));
		for (int i = 0; i < errors.size() - 1; ++i)
		{
			if (errors[i].first == file)
			{
				errors[i].second++;
				errors.pop_back();
				break;
			}
		}
	}
	//stable_sort(errors.begin(),errors.end().compare);
	if (errors.size() < 8)
	{
		int index = 0;
		while (index < 8 && index < errors.size())
		{
			string cheak = errors[index].first;
			int t = cheak.find(' ');
			if (t > 16)
				errors[index].first.erase(0, t - 16);
			cout << errors[index].first << ' ' << errors[index].second << endl;
			index++;
		}
	}
	else
	{
		int index = errors.size() - 8;
		while (index < errors.size())
		{
			string cheak = errors[index].first;
			int t = cheak.find(' ');
			if (t > 16)
				errors[index].first.erase(0, t - 16);
			cout << errors[index].first << ' ' << errors[index].second << endl;
			index++;
		}
	}
	return 0;
}

#endif


#if 0
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty())
			return 0;
		/*
		int len = numbers.size();
		sort(numbers.begin(),numbers.end());
		int mid = numbers[len/2];
		int count = 0;
		for(int i = 0; i < len; ++i)
		{
			if(numbers[i] == mid)
				count++;
		}
		return (count > (len/2)) ? mid : 0;
		*/
		int res = numbers[0];
		int count = 1;
		for (int i = 1; i < numbers.size(); ++i)
		{
			if (count == 0)
			{
				res = numbers[i];
				count = 1;
			}
			else
			{
				if (numbers[i] == res)
					count++;
				else
					count--;
			}
		}
		for (int i = 0; i < numbers.size(); ++i)
		{
			if (numbers[i] == res)
				count++;
		}
		return (count > (numbers.size() / 2)) ? res : 0;
	}
};
#endif