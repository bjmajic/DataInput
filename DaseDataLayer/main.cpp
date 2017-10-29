#include <iostream>
#include "its_lock.h"
#include "ThreadForWin32.h"
#include "ImageDateType.h"
using namespace std;
DWORD WINAPI MyFun(LPVOID)
{
	//WaitForSingleObject()
	//int* b = (int *)a;
	//cout << "b = " << *b << endl;
	cout << __FUNCTION__ << endl;
	//return *b;
	return 0;
}

void main()
{
	its_lock mylock;
	its_auto_lock seclock(mylock);
	CThreadForWin32 myThread;
	
	/*myThread.Start(MyFun, 0);
	myThread.Join(INFINITE);
	ImageDateType* imageDAta = new ImageDateType;*/
}