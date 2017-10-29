/*
windows 线程函数类，暂时只支持线程函数的类型为 DWORD WINPAI Fun(LPVOID)的形式
*/

#pragma once
#include "IThread.h"
#include <Windows.h>
typedef DWORD WINADVAPI(*pThreadFun)(LPVOID);

class CThreadForWin32 : public IThread
{
public:
	CThreadForWin32();
	virtual ~CThreadForWin32();
	virtual unsigned int Start(void* pFun, void* pParam);
	virtual unsigned int Join(unsigned int nTime);

	HANDLE hThreadHandle;
	DWORD dThreadID;
};

