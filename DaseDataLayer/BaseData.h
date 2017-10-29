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

	virtual int LoadFun();
	virtual int ProcessFun();

	friend int StartLoad(){ return LoadFun(); }
	friend int StartProcess(){ return ProcessFun(); }
	
	bool Run();
protected:
	std::vector<IThread*> m_vecThreadLoad;
	IThread* m_ThreadProcess;

	bool m_bUseNetFile;
	int  m_nThreadLoadNum;

};

