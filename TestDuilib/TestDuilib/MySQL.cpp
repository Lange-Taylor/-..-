
#include "MySQL.h"
using namespace std;
MySQL::MySQL()
{
	_mySQL = mysql_init(nullptr);
}

bool MySQL::ConnectMySQL(const char* host, const char*  user, const char*passward, const char* bdName)
{
	if (!mysql_real_connect(_mySQL, host, user, passward, bdName, 3306,  nullptr, 0))  //  
		//mysql_real_connect() :连接MYSQL，有8个参数，
		//第一个参数是MYSQL变量的地址，
		//第二个参数是主机名或IP地址，如果“host”是NULL或字符串"localhost"或“127.0.0.1”，连接将被视为与本地主机的连接，
		//第三个参数是MySQL登录ID
		//第四个参数是用户的密码
		//第五个参数是数据库名称
		//第六个参数是TCP / IP连接的端口号
		//第七个参数一般为NULL，不需要了解
		//第八个参数一般为0，不需要了解
		
	{
		cout << "数据库连接失败" << endl;
		return false;
	}
	mysql_query(_mySQL, "set names 'gbk'");
	return true;
}

vector<vector<string>> MySQL::Select(const string& strSQL)
{
	vector<vector<string>> vvRet;
	if (mysql_query(_mySQL, strSQL.c_str()))
	{
		//SQL命令响应失败
		cout << mysql_error(_mySQL) << endl;
		return vvRet;
	}
	//配合其他函数获取查询记录集
	MYSQL_RES * mySQLRES = mysql_store_result(_mySQL);    //将查询到的结果集储存到result中  
														  //返回值具有多个结果的MYSQL_RES结果集合,出现错误返回NULL
	if (mySQLRES== nullptr)
	{
		cout << mysql_error(_mySQL) << endl;
		return vvRet;
	}
	int   num = mysql_num_fields(mySQLRES);        //将结果集列数存放到num中     字段个数
	MYSQL_ROW  mysqlRow;
	while ((mysqlRow = mysql_fetch_row(mySQLRES)))  //遇到最后一行，则中止循环
	{
		vector<string> vItem;
		for (int i = 0; i < num; i++)         //利用for循环，输出该行的每一列
		{
			vItem.push_back(mysqlRow[i]);
			//cout << mysqlRow[i] << "\t";    //mysqlRow是MYSQL_ROW变量，可以当做数组使用，i为列数
		}
		vvRet.push_back(vItem);
		////////////cout << endl;
	}
	mysql_free_result(mySQLRES);     //释放结果集所占用的内存           必须操作
	//mysql_close(&ceshi);          //关闭与mysql的连接
	return vvRet;
}

bool MySQL::Insert(const string& strSQL)
{
	if (mysql_query(_mySQL, strSQL.c_str()))
	{
		//SQL命令响应失败
		cout << mysql_error(_mySQL) << endl;
		return false;
	}
	return true;
}

bool MySQL::Delete(const string& strSQL)
{
	if (mysql_query(_mySQL, strSQL.c_str()))
	{
		//SQL命令响应失败
		cout << mysql_error(_mySQL) << endl;
		return false;
	}
	return true;
}

bool MySQL::UpDate(const string& strSQL)
{
	if (mysql_query(_mySQL, strSQL.c_str()))
	{
		//SQL命令响应失败
		cout << mysql_error(_mySQL) << endl;
		return false;
	}
	return true;
}

MySQL::~MySQL()
{

}