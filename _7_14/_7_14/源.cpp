#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		vector<string> vec;  //�洢������Ĳ���
		int flag = 0;
		int cntOfQuot = 0;  //���ż���
		int lastIndexOfSpace = -1;//��һ���ո��λ��
		s += ' '; //Ԥ����ʹ�����һ������Ҳ�ܱ�push��vec
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ' && !flag)
			{
				vec.push_back(s.substr(lastIndexOfSpace + 1, i - lastIndexOfSpace - 1));//�����ո�֮��Ĳ�����������
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
		for (unsigned i = 0; i < vec.size(); i++)//ע��vec�е�Ԫ�ذ�������ǰ�������
		{
			if (vec[i][0] == '"')  
				vec[i] = vec[i].substr(1, vec[i].size() - 2);//ȥ������
			cout << vec[i] << endl;
		}
	}
	return 0;
}
