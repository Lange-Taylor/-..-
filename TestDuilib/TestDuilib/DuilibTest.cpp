#if 0
#include <Windows.h>
#include <tchar.h>
//��Ϣ�ص�����
LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)   ///////////���ش�����Ϣ
	{
	case WM_CLOSE:
		if (IDOK == MessageBox(hWnd, _T("��ȷ���˳���"), _T("�˳�"), MB_OKCANCEL))
		{
			DestroyWindow(hWnd);
			return 0;
		}

	case WM_LBUTTONDOWN:
		MessageBox(NULL, _T("0.0"), _T("leihoua"), IDOK);
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:                //δ����������Ϣ����ʽ    
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}
int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int
	nCmdShow)
{
	//Step1:ע��һ��������
	HWND hwnd; //���ڵľ��
	WNDCLASSEX wc; //������ṹ
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_VREDRAW | CS_HREDRAW;
	wc.lpszMenuName = 0;
	wc.lpszClassName = _T("Win32");   //���������൱�ڱ��
	wc.lpfnWndProc = WinProc; //��Ϣ�ص�����
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = NULL;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.cbWndExtra = 0;
	wc.cbClsExtra = 0;
	wc.hIconSm = NULL;


	RegisterClassEx(&wc); //ע�ᴰ��


	//Step2:����һ������
	hwnd = CreateWindow(
		_T("Win32"), //���ڵ�������Ҳ�������������Զ���Ĵ����������
		_T("nice"), //���ڵı���
		WS_OVERLAPPEDWINDOW, //����style
		500, //����λ��x����
		300, //����λ��y����
		800, //���ڿ��
		600, //���ڸ߶�
		NULL, //�����ھ��
		NULL, //�˵����
		hInstance, //ʵ�����
		NULL //��������
	);
	if (!hwnd)
	{
		return FALSE;
	}
	ShowWindow(hwnd, SW_SHOW); //��ʾ����
	UpdateWindow(hwnd); //ˢ��
	//Step3:��Ϣѭ��
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))       //�Լ�ά����
	{
		TranslateMessage(&msg);//������Ϣ
		DispatchMessage(&msg);//�ɷ���Ϣ��win32����
	}
	return 0;
}
#endif

#pragma once
#include <UIlib.h>
using namespace DuiLib;

#ifdef _DEBUG
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_ud.lib")
#   else
#       pragma comment(lib, "DuiLib_d.lib")
#   endif
#else
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_u.lib")
#   else
#       pragma comment(lib, "DuiLib.lib")
#   endif
#endif
#if 0
class CDuiFrameWnd : public CWindowWnd, public INotifyUI
{
public:
	//�����ര������
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }

	//������Ϣ:duilib�Լ���װ��
	virtual void    Notify(TNotifyUI& msg) 
	{
		if (msg.sType == _T("click"))
		{
			MessageBox(NULL, _T("TestBTN"), _T("Cashier"), IDOK);
		}
	}
	//����ϵͳ��Ϣ  
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;

		if (uMsg == WM_CREATE)
		{
#if 0
			//���ش��ں�Ĵ���
			CControlUI *pWnd = new CButtonUI;   //
			pWnd->SetText(_T("NICE"));   // ��������    
			//RGB
			pWnd->SetBkColor(0xFF00FF00);       // ���ñ���ɫ    

			m_PaintManager.Init(m_hWnd);
			m_PaintManager.AttachDialog(pWnd);
			//��ӿؼ�����Ϣ��Ӧ��������Ϣ�ͻᴫ�ﵽduilib����Ϣѭ�������ǿ�����Notify����������Ϣ����
			m_PaintManager.AddNotifier(this);
#endif
			m_PaintManager.Init(m_hWnd);

			CDialogBuilder builder;
			CControlUI* pRoot = builder.Create(_T("duilib.xml"), (UINT)0, NULL, &m_PaintManager);   // duilib.xml��Ҫ�ŵ�exeĿ¼��
			ASSERT(pRoot && "Failed to parse XML");

			m_PaintManager.AttachDialog(pRoot);
			m_PaintManager.AddNotifier(this);   // ��ӿؼ�����Ϣ��Ӧ��������Ϣ�ͻᴫ�ﵽduilib����Ϣѭ�������ǿ�����Notify����������Ϣ����
			return lRes;
		}
		// ����3����ϢWM_NCACTIVATE��WM_NCCALCSIZE��WM_NCPAINT��������ϵͳ������
		else if (uMsg == WM_NCACTIVATE)
		{
			if (!::IsIconic(m_hWnd))
			{
				return (wParam == 0) ? TRUE : FALSE;
			}
		}
		else if (uMsg == WM_NCCALCSIZE)
		{
			return 0;
		}
		else if (uMsg == WM_NCPAINT)
		{
			return 0;
		}

		//����ϵͳ��Ϣ
		//else if (uMsg == WM_CLOSE)
		//{
			//MessageBox(NULL, _T("TestCloseBTN"), _T("Cashier"), IDOK);
			//Close();
		//	return lRes;
		//}

		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
		{
			return lRes;
		}

		return __super::HandleMessage(uMsg, wParam, lParam);
	}

protected:
	CPaintManagerUI m_PaintManager;
};

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);

	CDuiFrameWnd duiFrame;
	duiFrame.Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame.ShowModal();
	return 0;
}
#endif



#if 0
class CDuiFrameWnd : public CWindowWnd, public INotifyUI
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }
	virtual void    Notify(TNotifyUI& msg)
	{
		if (msg.sType == _T("click"))
		{
			if (msg.pSender->GetName() == _T("btnHello"))
			{
				::MessageBox(NULL, _T("���ǰ�ť"), _T("����˰�ť"), NULL);
			}
		}
	}

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;

		if (uMsg == WM_CREATE)
		{
			m_PaintManager.Init(m_hWnd);

			CDialogBuilder builder;
			CControlUI* pRoot = builder.Create(_T("duilib.xml"), (UINT)0, NULL, &m_PaintManager);   // duilib.xml��Ҫ�ŵ�exeĿ¼��
			ASSERT(pRoot && "Failed to parse XML");

			m_PaintManager.AttachDialog(pRoot);
			m_PaintManager.AddNotifier(this);   // ��ӿؼ�����Ϣ��Ӧ��������Ϣ�ͻᴫ�ﵽduilib����Ϣѭ�������ǿ�����Notify����������Ϣ����
			return lRes;
		}
		// ����3����ϢWM_NCACTIVATE��WM_NCCALCSIZE��WM_NCPAINT��������ϵͳ������
		else if (uMsg == WM_NCACTIVATE)
		{
			if (!::IsIconic(m_hWnd))
			{
				return (wParam == 0) ? TRUE : FALSE;
			}
		}
		else if (uMsg == WM_NCCALCSIZE)
		{
			return 0;
		}
		else if (uMsg == WM_NCPAINT)
		{
			return 0;
		}

		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
		{
			return lRes;
		}

		return __super::HandleMessage(uMsg, wParam, lParam);
	}

protected:
	CPaintManagerUI m_PaintManager;
};

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());   // ������Դ��Ĭ��·�����˴�����Ϊ��exe��ͬһĿ¼��

	CDuiFrameWnd duiFrame;
	duiFrame.Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame.CenterWindow();
	duiFrame.ShowModal();
	return 0;
}
#endif


#if 1
class CDuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR    GetWindowClassName() const { return _T("DUIMainFrame"); }
	virtual CDuiString GetSkinFile() { return _T("duilib.xml"); }
	virtual CDuiString GetSkinFolder() { return _T(""); }

	//������Ϣ:duilib�Լ���װ��
	virtual void    Notify(TNotifyUI& msg)
	{
		if (msg.sType == _T("click"))
		{
			//MessageBox(NULL, _T("TestBTN"), _T("Cashier"), IDOK);
			if (msg.pSender == m_PaintManager.FindControl(_T("BTN_CLOSE")))
			{
				Close();
			}
		}
	}
};


#include "MainWnd.h"
#include "Login.h"
#include "MySQL.h"

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	CPaintManagerUI::SetInstance(hInstance);

	/*MainWnd duiFrame;
	duiFrame.Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame.CenterWindow();
	duiFrame.ShowModal();*/
	MySQL mysql;
	mysql.ConnectMySQL("localhost", "root", "12345", "cashier");

	LogInWnd duiFrame(&mysql);
	duiFrame.Create(NULL, _T("LOGINWND"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame.CenterWindow();
	duiFrame.ShowModal();
	return 0;
}
#endif