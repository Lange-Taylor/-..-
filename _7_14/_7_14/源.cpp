#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		vector<string> vec;  //存储解析后的参数
		int flag = 0;
		int cntOfQuot = 0;  //引号计数
		int lastIndexOfSpace = -1;//上一个空格的位置
		s += ' '; //预处理使得最后一个参数也能被push进vec
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ' && !flag)
			{
				vec.push_back(s.substr(lastIndexOfSpace + 1, i - lastIndexOfSpace - 1));//两个空格之间的参数包括引号
				lastIndexOfSpace = i;
			}
			if (s[i] == '"')
			{
				if (cntOfQuot % 2 == 0)
					flag = 1;
				else
					flag = 0;
				cntOfQuot++;
			}
		}
		cout << vec.size() << endl;
		for (unsigned i = 0; i < vec.size(); i++)//注意vec中的元素包括参数前面的引号
		{
			if (vec[i][0] == '"')  
				vec[i] = vec[i].substr(1, vec[i].size() - 2);//去掉引号
			cout << vec[i] << endl;
		}
	}
	return 0;
}
