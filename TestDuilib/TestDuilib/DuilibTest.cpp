#if 0
#include <Windows.h>
#include <tchar.h>
//消息回调函数
LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)   ///////////拦截处理消息
	{
	case WM_CLOSE:
		if (IDOK == MessageBox(hWnd, _T("你确定退出？"), _T("退出"), MB_OKCANCEL))
		{
			DestroyWindow(hWnd);
			return 0;
		}

	case WM_LBUTTONDOWN:
		MessageBox(NULL, _T("0.0"), _T("leihoua"), IDOK);
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:                //未自主拦截消息处理方式    
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}
int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int
	nCmdShow)
{
	//Step1:注册一个窗口类
	HWND hwnd; //窗口的句柄
	WNDCLASSEX wc; //窗口类结构
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_VREDRAW | CS_HREDRAW;
	wc.lpszMenuName = 0;
	wc.lpszClassName = _T("Win32");   //窗口名字相当于标记
	wc.lpfnWndProc = WinProc; //消息回调函数
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = NULL;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.cbWndExtra = 0;
	wc.cbClsExtra = 0;
	wc.hIconSm = NULL;


	RegisterClassEx(&wc); //注册窗口


	//Step2:创建一个窗口
	hwnd = CreateWindow(
		_T("Win32"), //窗口的类名，也就是上面我们自定义的窗口类的名字
		_T("nice"), //窗口的标题
		WS_OVERLAPPEDWINDOW, //窗口style
		500, //窗口位置x坐标
		300, //窗口位置y坐标
		800, //窗口宽度
		600, //窗口高度
		NULL, //父窗口句柄
		NULL, //菜单句柄
		hInstance, //实例句柄
		NULL //创建数据
	);
	if (!hwnd)
	{
		return FALSE;
	}
	ShowWindow(hwnd, SW_SHOW); //显示窗口
	UpdateWindow(hwnd); //刷新
	//Step3:消息循环
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))       //自己维护的
	{
		TranslateMessage(&msg);//处理消息
		DispatchMessage(&msg);//派发消息给win32窗口
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
	//设置类窗口名称
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }

	//捕获消息:duilib自己封装的
	virtual void    Notify(TNotifyUI& msg) 
	{
		if (msg.sType == _T("click"))
		{
			MessageBox(NULL, _T("TestBTN"), _T("Cashier"), IDOK);
		}
	}
	//拦截系统消息  
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;

		if (uMsg == WM_CREATE)
		{
#if 0
			//拦截窗口后的处理
			CControlUI *pWnd = new CButtonUI;   //
			pWnd->SetText(_T("NICE"));   // 设置文字    
			//RGB
			pWnd->SetBkColor(0xFF00FF00);       // 设置背景色    

			m_PaintManager.Init(m_hWnd);
			m_PaintManager.AttachDialog(pWnd);
			//添加控件等消息响应，这样消息就会传达到duilib的消息循环，我们可以在Notify函数里做消息处理
			m_PaintManager.AddNotifier(this);
#endif
			m_PaintManager.Init(m_hWnd);

			CDialogBuilder builder;
			CControlUI* pRoot = builder.Create(_T("duilib.xml"), (UINT)0, NULL, &m_PaintManager);   // duilib.xml需要放到exe目录下
			ASSERT(pRoot && "Failed to parse XML");

			m_PaintManager.AttachDialog(pRoot);
			m_PaintManager.AddNotifier(this);   // 添加控件等消息响应，这样消息就会传达到duilib的消息循环，我们可以在Notify函数里做消息处理
			return lRes;
		}
		// 以下3个消息WM_NCACTIVATE、WM_NCCALCSIZE、WM_NCPAINT用于屏蔽系统标题栏
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

		//拦截系统消息
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
				::MessageBox(NULL, _T("我是按钮"), _T("点击了按钮"), NULL);
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
			CControlUI* pRoot = builder.Create(_T("duilib.xml"), (UINT)0, NULL, &m_PaintManager);   // duilib.xml需要放到exe目录下
			ASSERT(pRoot && "Failed to parse XML");

			m_PaintManager.AttachDialog(pRoot);
			m_PaintManager.AddNotifier(this);   // 添加控件等消息响应，这样消息就会传达到duilib的消息循环，我们可以在Notify函数里做消息处理
			return lRes;
		}
		// 以下3个消息WM_NCACTIVATE、WM_NCCALCSIZE、WM_NCPAINT用于屏蔽系统标题栏
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
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());   // 设置资源的默认路径（此处设置为和exe在同一目录）

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

	//捕获消息:duilib自己封装的
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