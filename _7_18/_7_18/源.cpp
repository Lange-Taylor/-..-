//完全数
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
		s1 = del_0(s1_);//获取输入数据并将其分割,删去空格
		s2_ = str.substr(str.find('-') + 1);
		s2 = del_0(s2_);
		if (s1 == "joker JOKER" || s2 == "joker JOKER") 
			cout << "joker JOKER" << endl;
		else 
			if (s1.size() == 7 || s2.size() == 7) {//有炸弹
				if (s1.size() == 7 && s2.size() == 7)//炸弹比较
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
			if (s1.size() == s2.size())//其余只能同等长度比较
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
//		//王炸最大，直接输出
//		if (line.find("joker JOKER") != -1)
//			cout << "joker JOKER" << endl;
//		else {
//			int dash = line.find('-');
//			//分开两手牌
//			string car1 = line.substr(0, dash);
//			string car2 = line.substr(dash + 1);
//			//获取空格的次数，牌数为c + 1
//			int c1 = count(car1.begin(), car1.end(), ' ');
//			int c2 = count(car2.begin(), car2.end(), ' ');
//			//拿到第一张牌
//			string first1 = car1.substr(0, car1.find(' '));
//			string first2 = car2.substr(0, car2.find(' '));
//			string str = "345678910JQKA2jokerJOKER";
//			if (c1 == c2) {
//				//只要牌数相等，则第一张牌大的即为大
//				if (str.find(first1) > str.find(first2))
//					cout << car1 << endl;
//				else
//					cout << car2 << endl;
//			}
//			else
//			{
//				//牌数不相同，说明类型不同,只有炸弹可以和其它牌比较
//				//其它类型都是错误的
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