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
	//父类WindowImplBase 提供的
protected:
	//xml文件对应的目录
	virtual CDuiString GetSkinFolder();

	//xml文件的名字
	virtual CDuiString GetSkinFile();
	//窗口类的名字: 在注册窗口时必须提供
	virtual LPCTSTR GetWindowClassName(void) const;

	void SelectceshiInfo();

	void InsertceshiInfo();

	//void Updatainfo();

	void Deleteceshiinfo();


private:
	MySQL* m_pMySQL;
};