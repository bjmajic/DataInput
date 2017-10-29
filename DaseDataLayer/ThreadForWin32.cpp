#include "ThreadForWin32.h"


CThreadForWin32::CThreadForWin32()
{
	hThreadHandle = INVALID_HANDLE_VALUE;
	dThreadID = 0;
}


CThreadForWin32::~CThreadForWin32()
{
#ifdef _DEBUG
	std::cout << "执行 CThreadForWin32 的析构函数" << std::endl;
#endif
	Join(INFINITE);
}

bool CThreadForWin32::Start(pCallBack callback_fun)
{
	DWORD threadID;
	HANDLE hThread;
	if (callback_fun == nullptr)
	{
		return false;
	}

	//pThreadFun threadFun = (pThreadFun)pFun;
	//m_pCallBackFun = pCallBackFun;

	hThread = CreateThread(NULL, 0, StartFun, callback_fun, 0, &threadID);
	//return (unsigned int)hThread;
	hThreadHandle = hThread;
	dThreadID = threadID;

	return true;
}

unsigned int CThreadForWin32::Join(unsigned int nTime)
{
	/*
	返回值需要判断 WAIT_OBJECT_0 和 WAIT_TIMEOUT;
	*/
	DWORD retVal = 0;
	if (hThreadHandle != INVALID_HANDLE_VALUE)
	{
		retVal = WaitForSingleObject(hThreadHandle, (DWORD)nTime);
		CloseHandle(hThreadHandle);
		hThreadHandle = INVALID_HANDLE_VALUE;
	}
	
	return (unsigned int)retVal;
}

DWORD WINAPI CThreadForWin32::StartFun(LPVOID pParam)
{
	//m_FunInfo.pClassObj = threadFunInfo.pClassObj;
	//m_FunInfo.pFuntion = threadFunInfo.pFuntion;
	//m_FunInfo.pParam = threadFunInfo.pParam;
	pCallBack threadFun = (pCallBack)pParam;
	//CThreadForWin32* pThread = (CThreadForWin32*)pParam;
	return threadFun();
}
