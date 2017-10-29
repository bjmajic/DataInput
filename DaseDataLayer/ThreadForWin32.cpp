#include "ThreadForWin32.h"


CThreadForWin32::CThreadForWin32()
{
	hThreadHandle = INVALID_HANDLE_VALUE;
	dThreadID = 0;
}


CThreadForWin32::~CThreadForWin32()
{
#ifdef _DEBUG
	std::cout << "ִ�� CThreadForWin32 ����������" << std::endl;
#endif
	Join(INFINITE);
}

unsigned int CThreadForWin32::Start(void* pFun, void* pParam)
{
	DWORD threadID;
	HANDLE hThread;
	pThreadFun threadFun = (pThreadFun)pFun;

	hThread = CreateThread(NULL, 0, threadFun, pParam, 0, &threadID);
	//return (unsigned int)hThread;
	hThreadHandle = hThread;
	dThreadID = threadID;
	
	return 0;
}

unsigned int CThreadForWin32::Join(unsigned int nTime)
{
	/*
	����ֵ��Ҫ�ж� WAIT_OBJECT_0 �� WAIT_TIMEOUT;
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
