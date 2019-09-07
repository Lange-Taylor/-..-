
#include "MySQL.h"
using namespace std;
MySQL::MySQL()
{
	_mySQL = mysql_init(nullptr);
}

bool MySQL::ConnectMySQL(const char* host, const char*  user, const char*passward, const char* bdName)
{
	if (!mysql_real_connect(_mySQL, host, user, passward, bdName, 3306,  nullptr, 0))  //  
		//mysql_real_connect() :����MYSQL����8��������
		//��һ��������MYSQL�����ĵ�ַ��
		//�ڶ�����������������IP��ַ�������host����NULL���ַ���"localhost"��127.0.0.1�������ӽ�����Ϊ�뱾�����������ӣ�
		//������������MySQL��¼ID
		//���ĸ��������û�������
		//��������������ݿ�����
		//������������TCP / IP���ӵĶ˿ں�
		//���߸�����һ��ΪNULL������Ҫ�˽�
		//�ڰ˸�����һ��Ϊ0������Ҫ�˽�
		
	{
		cout << "���ݿ�����ʧ��" << endl;
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
		//SQL������Ӧʧ��
		cout << mysql_error(_mySQL) << endl;
		return vvRet;
	}
	//�������������ȡ��ѯ��¼��
	MYSQL_RES * mySQLRES = mysql_store_result(_mySQL);    //����ѯ���Ľ�������浽result��  
														  //����ֵ���ж�������MYSQL_RES�������,���ִ��󷵻�NULL
	if (mySQLRES== nullptr)
	{
		cout << mysql_error(_mySQL) << endl;
		return vvRet;
	}
	int   num = mysql_num_fields(mySQLRES);        //�������������ŵ�num��     �ֶθ���
	MYSQL_ROW  mysqlRow;
	while ((mysqlRow = mysql_fetch_row(mySQLRES)))  //�������һ�У�����ֹѭ��
	{
		vector<string> vItem;
		for (int i = 0; i < num; i++)         //����forѭ����������е�ÿһ��
		{
			vItem.push_back(mysqlRow[i]);
			//cout << mysqlRow[i] << "\t";    //mysqlRow��MYSQL_ROW���������Ե�������ʹ�ã�iΪ����
		}
		vvRet.push_back(vItem);
		////////////cout << endl;
	}
	mysql_free_result(mySQLRES);     //�ͷŽ������ռ�õ��ڴ�           �������
	//mysql_close(&ceshi);          //�ر���mysql������
	return vvRet;
}

bool MySQL::Insert(const string& strSQL)
{
	if (mysql_query(_mySQL, strSQL.c_str()))
	{
		//SQL������Ӧʧ��
		cout << mysql_error(_mySQL) << endl;
		return false;
	}
	return true;
}

bool MySQL::Delete(const string& strSQL)
{
	if (mysql_query(_mySQL, strSQL.c_str()))
	{
		//SQL������Ӧʧ��
		cout << mysql_error(_mySQL) << endl;
		return false;
	}
	return true;
}

bool MySQL::UpDate(const string& strSQL)
{
	if (mysql_query(_mySQL, strSQL.c_str()))
	{
		//SQL������Ӧʧ��
		cout << mysql_error(_mySQL) << endl;
		return false;
	}
	return true;
}

MySQL::~MySQL()
{

}