//��ȫ��
#if 0
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int M;
	cin >> M;
	//vector<int> ret;
	int count = 0;
	
	for (int i = M; i >= 2; --i)
	{
		int sum = 1;
		for (int j = i/2; j >= 2; --j)
		{
			if (i % j == 0)
			{
				//ret.push_back(i);
				sum += j;
			}
		}
		if (i == sum)
		{
			count++;
		}
	}

	cout << count << endl;
	return 0;
}

#endif


#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

unordered_map<char, int> helper{ {'3',1},{'4',2},{ '5',3 },{ '6',4 },{ '7',5 },{ '8',6 },
{ '9',7 },{ '1',8 },{ 'J',9 },{ 'Q',10 },{ 'K',11 },{ 'A',12 },{'2',13} };

string del_0(string str) {
	while (str.find('0') != string::npos)
		str.erase(str.find('0'), 1);
	return str;
}
int main() {
	string str, s1, s2, s1_, s2_;
	while (getline(cin, str)) {
		s1_ = str.substr(0, str.find('-'));
		s1 = del_0(s1_);//��ȡ�������ݲ�����ָ�,ɾȥ�ո�
		s2_ = str.substr(str.find('-') + 1);
		s2 = del_0(s2_);
		if (s1 == "joker JOKER" || s2 == "joker JOKER") 
			cout << "joker JOKER" << endl;
		else 
			if (s1.size() == 7 || s2.size() == 7) {//��ը��
				if (s1.size() == 7 && s2.size() == 7)//ը���Ƚ�
					if (helper[s1[0]] > helper[s2[0]])
						cout << s1_ << endl;
					else 
						cout << s2_ << endl;
				else
					if (s1.size() == 7) 
						cout << s1_ << endl;
				else 
						cout << s2_ << endl;
			}
		else 
			if (s1.size() == s2.size())//����ֻ��ͬ�ȳ��ȱȽ�
				if (helper[s1[0]] > helper[s2[0]])
					cout << s1_ << endl;
				else 
					cout << s2_ << endl;
		else 
				cout << "ERROR" << endl;
	}
}
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main() {
//	string line;
//	while (getline(cin, line)) {
//		//��ը���ֱ�����
//		if (line.find("joker JOKER") != -1)
//			cout << "joker JOKER" << endl;
//		else {
//			int dash = line.find('-');
//			//�ֿ�������
//			string car1 = line.substr(0, dash);
//			string car2 = line.substr(dash + 1);
//			//��ȡ�ո�Ĵ���������Ϊc + 1
//			int c1 = count(car1.begin(), car1.end(), ' ');
//			int c2 = count(car2.begin(), car2.end(), ' ');
//			//�õ���һ����
//			string first1 = car1.substr(0, car1.find(' '));
//			string first2 = car2.substr(0, car2.find(' '));
//			string str = "345678910JQKA2jokerJOKER";
//			if (c1 == c2) {
//				//ֻҪ������ȣ����һ���ƴ�ļ�Ϊ��
//				if (str.find(first1) > str.find(first2))
//					cout << car1 << endl;
//				else
//					cout << car2 << endl;
//			}
//			else
//			{
//				//��������ͬ��˵�����Ͳ�ͬ,ֻ��ը�����Ժ������ƱȽ�
//				//�������Ͷ��Ǵ����
//				if (c1 == 3)
//					cout << car1 << endl;
//				else if (c2 == 3)
//					cout << car2 << endl;
//				else
//					cout << "ERROR" << endl;
//			}
//		}
//	}
//}