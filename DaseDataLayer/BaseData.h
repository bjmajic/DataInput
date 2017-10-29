#pragma once
/************************************************************************/
/* 数据输入的基类，具体的数据输入需要继承此类，完成自己的线程函数。           */
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

