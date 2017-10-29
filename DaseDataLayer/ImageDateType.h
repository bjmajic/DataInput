#pragma once
#include "BaseData.h"

typedef float* (*pTransFun)(float*);
class ImageDateType : public BaseData
{
	friend void LoadImage();
	friend void ProcessImage();

public:
	ImageDateType(bool bUseNetFile = false, unsigned int nThreadLoadNum = 1);
	virtual ~ImageDateType();
	virtual void SetLoadFun(pThreadFun pFun);
	virtual void SetLoadFunParam(LPVOID pParam);
	virtual void SetProcessFun(pThreadFun pFun);
	virtual void SetProcessFunParam(LPVOID pParam);

private:
	bool m_bMirror;
	int  m_nCropType;  // 0: 无crop  1：中心crop  2： 随机crop
	std::vector<pTransFun> m_vecTransFun;
};

