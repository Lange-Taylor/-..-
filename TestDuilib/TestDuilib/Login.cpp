#include "Login.h"
#include "MainWnd.h"
#include "CashierWnd.h"
//xml文件对应的目录
CDuiString LogInWnd::GetSkinFolder()
{
	return _T("");
}
//xml文件的名字
CDuiString LogInWnd::GetSkinFile()
{
	return _T("LogInWnd.xml");
}
//窗口类的名字: 在注册窗口时必须提供
LPCTSTR LogInWnd::GetWindowClassName(void) const
{
	return _T("LogInWnd");
}

 void LogInWnd::Notify(TNotifyUI& msg)
{
	 CDuiString strName =  msg.pSender->GetName();
	 if (msg.sType == _T("click"))
	 {
		 if (strName == _T("BTN_MIN"))
			 //缩小窗口
			 ::SendMessage(m_hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0);
		 //MessageBox(NULL,_T("MIN"), _T("Cashier"),IDOK);   用来逐步测试
		 else if (strName == _T("BTN_CLOSE"))

			 //MessageBox(NULL, _T("CLOSE"), _T("Cashier"), IDOK);
			 Close();
		 else if (strName == _T("BTN_LOGIN"))

			 //MessageBox(NULL, _T("LOGIN"), _T("Cashier"), IDOK);
			 LogIn();
	 }
}

 void LogInWnd::LogIn()
 {
	 //从编辑框获取用户名和密码
	 //需要强转
	 CEditUI * pEditUserName = (CEditUI*)m_PaintManager.FindControl(_T("EDIT_USER_NAME"));
	 CDuiString strUserName = pEditUserName->GetText();


	 CEditUI * pEditPassword = (CEditUI*)m_PaintManager.FindControl(_T("EDIT_USER_PASSWORD"));
	 CDuiString strUserPassword = pEditPassword->GetText();
	 //查询数据库,检测用户是否存在

	 string strSQL("select * from ceshi where name1 = '");
	 //ascII UNICODE
	 strSQL += UnicodeToANSI(strUserName);
	 strSQL += "';";
	vector<vector<string>> vRet = m_pMySQL->Select(strSQL);
	 if (vRet.empty())
	 {
		 MessageBox(m_hWnd, _T("用户名错误"), _T("Cashier"), IDOK);
		 return;
	 }
	 string userpassward = UnicodeToANSI(strUserPassword);

	 if (userpassward != vRet[0][4])
	 {
		 MessageBox(m_hWnd, _T("用户密码错误"), _T("Cashier"), IDOK);
		 return;
	 }

	 //隐藏登陆窗口

	 ShowWindow(false);

	
	 if (vRet[0][5] == "管理员")
	 {
	 //创建主窗口
		 MainWnd mainWnd(m_pMySQL);
		 mainWnd.Create(NULL, _T("MainWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
		 mainWnd.CenterWindow();
		 mainWnd.ShowModal();
	 }  
	 else
	 {
		//创建主窗口
	 CCashierWnd mainWnd(m_pMySQL);
	 mainWnd.Create(NULL, _T("CashierWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	 mainWnd.CenterWindow();
	 mainWnd.ShowModal();
	  }
	// 控件  tablayoue 

	 

 }