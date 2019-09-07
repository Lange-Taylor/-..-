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
	//����WindowImplBase �ṩ��

	//xml�ļ���Ӧ��Ŀ¼
	virtual CDuiString GetSkinFolder();

	//xml�ļ�������
	virtual CDuiString GetSkinFile();
	//�����������: ��ע�ᴰ��ʱ�����ṩ
	virtual LPCTSTR GetWindowClassName(void) const;
private:
	MySQL* m_pMySQL;
};