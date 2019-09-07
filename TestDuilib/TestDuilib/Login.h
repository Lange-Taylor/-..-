#include "Common.h"
#include "MySQL.h"

class LogInWnd : public WindowImplBase
{
public:
	LogInWnd(MySQL* pMySQL = nullptr)
		:m_pMySQL(pMySQL)
	{}
	virtual void Notify(TNotifyUI& msg);
	void LogIn();

protected:
	//父类WindowImplBase 提供的

	//xml文件对应的目录
	virtual CDuiString GetSkinFolder();

	//xml文件的名字
	virtual CDuiString GetSkinFile();
	//窗口类的名字: 在注册窗口时必须提供
	virtual LPCTSTR GetWindowClassName(void) const;
private:
	MySQL* m_pMySQL;
};