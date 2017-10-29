/*
windows �̺߳����࣬��ʱֻ֧���̺߳���������Ϊ DWORD WINPAI Fun(LPVOID)����ʽ
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

