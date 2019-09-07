#pragma once

#include "Common.h"
#include "MySQL.h"

class MainWnd  : public WindowImplBase
{

public:
	MainWnd(MySQL* pMySQL = nullptr)
		:m_pMySQL(pMySQL)
	{}
	
	virtual void Notify(TNotifyUI& msg);
	//����WindowImplBase �ṩ��
protected:
	//xml�ļ���Ӧ��Ŀ¼
	virtual CDuiString GetSkinFolder();

	//xml�ļ�������
	virtual CDuiString GetSkinFile();
	//�����������: ��ע�ᴰ��ʱ�����ṩ
	virtual LPCTSTR GetWindowClassName(void) const;

	void SelectceshiInfo();

	void InsertceshiInfo();

	//void Updatainfo();

	void Deleteceshiinfo();


private:
	MySQL* m_pMySQL;
};