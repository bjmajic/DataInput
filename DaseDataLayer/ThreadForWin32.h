/*
windows �̺߳����࣬��ʱֻ֧���̺߳���������Ϊ DWORD WINPAI Fun(LPVOID)����ʽ
*/

#pragma once
#include "IThread.h"
#include <Windows.h>
//typedef DWORD WINADVAPI(*pThreadFun)(LPVOID);

class CThreadForWin32 : public IThread
{
public:
	CThreadForWin32();
	virtual ~CThreadForWin32();
	//virtual bool Start(pCallBack pCallBackFun, void* pParam);
	virtual bool Start(pCallBack callback_fun);
	virtual unsigned int Join(unsigned int nTime);

	HANDLE hThreadHandle;
	DWORD dThreadID;
private:
	static DWORD WINAPI StartFun(LPVOID pParam);
};

