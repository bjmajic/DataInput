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
	virtual unsigned int Start(void* pFun, void* pParam) = 0;

	/*
	���ã��ر��߳�
	����win32����ָʾ�������������ص��¼�, nThreadFlag ���߳̾��
	����Linux���򣬷���ֵ���̵߳�ID���ݶ���
	*/
	virtual unsigned int Join(unsigned int  nTime) = 0;
};

