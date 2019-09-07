
#pragma once

#include "Common.h"
#include "MySQL.h"

class CCashierWnd : public WindowImplBase
{

public:
	CCashierWnd(MySQL* pMySQL = nullptr)
		:m_pMySQL(pMySQL)
	{}

	//virtual void Notify(TNotifyUI& msg);
	//����WindowImplBase �ṩ��
protected:
	//xml�ļ���Ӧ��Ŀ¼
	virtual CDuiString GetSkinFolder();

	//xml�ļ�������
	virtual CDuiString GetSkinFile();
	//�����������: ��ע�ᴰ��ʱ�����ṩ
	virtual LPCTSTR GetWindowClassName(void) const;

	virtual void Notify(TNotifyUI& msg);
	void SelectGoods();
	void AddGoodsCount();
	void SubGoodsCount();
	void IsertGoodsList();
	void CancelOrder();
	void CommitOrder();
private:
	MySQL* m_pMySQL;
};