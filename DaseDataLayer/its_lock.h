#pragma once
#include <Windows.h>
#include "NonCopyable.h"
class its_auto_lock;

class its_lock : public NonCopyable
{
public:
	its_lock()
	{
		InitializeCriticalSection(&cs_lock);
	}
	~its_lock()
	{
		DeleteCriticalSection(&cs_lock);
	}
	void lock()
	{
		EnterCriticalSection(&cs_lock);
	}
	void unlock()
	{
		LeaveCriticalSection(&cs_lock);
	}
private:
	CRITICAL_SECTION cs_lock;
};

class its_auto_lock : public NonCopyable
{
private:
	its_lock &lock_obj;

public:
	its_auto_lock(its_lock &lock_object) : lock_obj(lock_object)
	{
		lock_obj.lock();
	}
	~its_auto_lock()
	{
		lock_obj.unlock();
	}
};