#pragma once
/************************************************************************/
/* ��������Ļ��࣬���������������Ҫ�̳д��࣬����Լ����̺߳�����           */
/************************************************************************/

#include <vector>

#ifdef _WIN32
#include "ThreadForWin32.h"
#endif

class BaseData
{
public:
	BaseData(bool bUseNetFile = false, unsigned int nThreadLoadNum = 1);
	virtual ~BaseData();
	
#ifdef _WIN32
	virtual void SetLoadFun(pThreadFun pFun) = 0;
	virtual void SetLoadFunParam(LPVOID pParam) = 0;
	virtual void SetProcessFun(pThreadFun pFun) = 0;
	virtual void SetProcessFunParam(LPVOID pParam) = 0;
#endif
	bool Run();
protected:
	std::vector<IThread*> m_vecThreadLoad;
	IThread* m_ThreadProcess;

	bool m_bUseNetFile;
	int  m_nThreadLoadNum;

#ifdef _WIN32
	pThreadFun pLoadFun;
	pThreadFun pProcessFun;
	LPVOID     pLoadFunParam;
	LPVOID     pProcessFunParam;
#endif
};

