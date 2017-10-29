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
	作用：开启线程
	对于win32程序，返回值是线程的句柄, pFun 是线程函数指针, pParam是线程函数参数.
	对于Linux程序，返回值是线程的ID（暂定）
	*/
	virtual unsigned int Start(void* pFun, void* pParam) = 0;

	/*
	作用：关闭线程
	对于win32程序，指示出引发函数返回的事件, nThreadFlag 是线程句柄
	对于Linux程序，返回值是线程的ID（暂定）
	*/
	virtual unsigned int Join(unsigned int  nTime) = 0;
};

