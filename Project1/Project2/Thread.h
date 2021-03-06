/**
CSC5801
Thread.h
Purpose: Generic declaration of a thread class, also contains
the mutex class used by the thread class

@author Michael Yiangou (B7064124)
@version
*/

#pragma once
#include <windows.h>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

/**
* Abstract Thread
*/
class Thread
{
public:
	Thread() {}
	virtual ~Thread() { CloseHandle(thread_handle); }
	virtual void start();
	virtual void join();
	virtual DWORD get_id() const { return tid; }
protected:
	virtual void run() = 0;
	friend DWORD thread_ftn(LPVOID T);
	HANDLE thread_handle;
	DWORD tid;
private:
	Thread(const Thread& src);
	Thread& operator=(const Thread& rhs);
};

/**
* some mutex class
*/
class MutexClass
{
public:
	MutexClass();
	virtual ~MutexClass();
	virtual void lock_mutex();
	virtual void unlock_mutex();
protected:
	HANDLE mutex;
};