#include "BaseData.h"

BaseData::BaseData(bool bUseNetFile /*= false*/, unsigned int nThreadLoadNum /*= 1*/) : m_bUseNetFile(bUseNetFile), m_nThreadLoadNum(nThreadLoadNum)
{
#ifdef _WIN32
	m_vecThreadLoad.resize(m_nThreadLoadNum, new CThreadForWin32());
	m_ThreadProcess = new CThreadForWin32();
#endif

	pLoadFun = nullptr;
	pProcessFun = nullptr;
	pLoadFunParam = nullptr;
	pProcessFunParam = nullptr;
}

BaseData::~BaseData()
{
	for (int i = 0; i < m_nThreadLoadNum; i++)
	{
		if (m_vecThreadLoad[i] != nullptr)
		{
			delete m_vecThreadLoad[i];
			m_vecThreadLoad[i] = nullptr;
		}
	}

	if (m_ThreadProcess != nullptr)
	{
		delete m_ThreadProcess;
		m_ThreadProcess = nullptr;
	}

}

bool BaseData::Run()
{
	if (pLoadFun != nullptr && pProcessFun != nullptr)
	{
		for (int i = 0; i < m_nThreadLoadNum; i++)
		{
			m_vecThreadLoad[i]->Start(pLoadFun, pLoadFunParam);
		}

		m_ThreadProcess->Start(pProcessFun, pProcessFunParam);

		return true;
	}
	else
	{
		return false;
	}
}
