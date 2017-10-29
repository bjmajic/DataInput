#pragma once
#include "NonCopyable.h"
#include <iostream>
//
//#ifdef _WIN32
//#include <Windows.h>
//#define SKINT HANDLE
//#else
//#define SKINT int
//#endif
//typedef DWORD WINADVAPI(*pThreadFun)(LPVOID);
typedef int(*pCallBack)();

class ThreadFunInfo 
{
public:
	pCallBack pFuntion;
	void* pParam;
	ThreadFunInfo()
	{
		pFuntion = nullptr;
		pParam = nullptr;
	}
};

class IThread : public NonCopyable
{
public:
	IThread(){}
	virtual ~IThread(){}
	/*
	���ã������߳�
	����win32���򣬷���ֵ���̵߳ľ��, pFun ���̺߳���ָ��, pParam���̺߳�������.
	����Linux���򣬷���ֵ���̵߳�ID���ݶ���
	*/
	virtual bool Start(pCallBack callback_fun) = 0;

	/*
	���ã��ر��߳�
	����win32����ָʾ�������������ص��¼�, nThreadFlag ���߳̾��
	����Linux���򣬷���ֵ���̵߳�ID���ݶ���
	*/
	virtual unsigned int Join(unsigned int  nTime) = 0;
protected:
	//ThreadFunInfo m_ThreadFunInfo;
	pCallBack m_callBackFun;
};

