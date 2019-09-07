#include "Login.h"
#include "MainWnd.h"
#include "CashierWnd.h"
//xml�ļ���Ӧ��Ŀ¼
CDuiString LogInWnd::GetSkinFolder()
{
	return _T("");
}
//xml�ļ�������
CDuiString LogInWnd::GetSkinFile()
{
	return _T("LogInWnd.xml");
}
//�����������: ��ע�ᴰ��ʱ�����ṩ
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
			 //��С����
			 ::SendMessage(m_hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0);
		 //MessageBox(NULL,_T("MIN"), _T("Cashier"),IDOK);   �����𲽲���
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
	 //�ӱ༭���ȡ�û���������
	 //��Ҫǿת
	 CEditUI * pEditUserName = (CEditUI*)m_PaintManager.FindControl(_T("EDIT_USER_NAME"));
	 CDuiString strUserName = pEditUserName->GetText();


	 CEditUI * pEditPassword = (CEditUI*)m_PaintManager.FindControl(_T("EDIT_USER_PASSWORD"));
	 CDuiString strUserPassword = pEditPassword->GetText();
	 //��ѯ���ݿ�,����û��Ƿ����

	 string strSQL("select * from ceshi where name1 = '");
	 //ascII UNICODE
	 strSQL += UnicodeToANSI(strUserName);
	 strSQL += "';";
	vector<vector<string>> vRet = m_pMySQL->Select(strSQL);
	 if (vRet.empty())
	 {
		 MessageBox(m_hWnd, _T("�û�������"), _T("Cashier"), IDOK);
		 return;
	 }
	 string userpassward = UnicodeToANSI(strUserPassword);

	 if (userpassward != vRet[0][4])
	 {
		 MessageBox(m_hWnd, _T("�û��������"), _T("Cashier"), IDOK);
		 return;
	 }

	 //���ص�½����

	 ShowWindow(false);

	
	 if (vRet[0][5] == "����Ա")
	 {
	 //����������
		 MainWnd mainWnd(m_pMySQL);
		 mainWnd.Create(NULL, _T("MainWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
		 mainWnd.CenterWindow();
		 mainWnd.ShowModal();
	 }  
	 else
	 {
		//����������
	 CCashierWnd mainWnd(m_pMySQL);
	 mainWnd.Create(NULL, _T("CashierWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	 mainWnd.CenterWindow();
	 mainWnd.ShowModal();
	  }
	// �ؼ�  tablayoue 

	 

 }