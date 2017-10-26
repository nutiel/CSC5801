/**
CSC5801
Thread.cpp
Purpose: Generic declaration of a thread class, also contains 
the mutex class used by the thread class

@author Michael Yiangou (B7064124)
@version
*/

#include "CW2.h"
#include "Expression.h"
#include "Game.h"
#include "Gang.h"
#include "IfNode.h"
#include "Leader.h"
#include "Prisoner.h"
#include "Thread.h"
#include "Tournament.h"

/**
* standard thread function
*/
DWORD thread_ftn(LPVOID T) {
	Thread* t = static_cast<Thread*>(T);
	t->run();
	return NULL;
}

void Thread::start() {
	thread_handle = CreateThread(
		NULL, // default security
		0, // default stack size
		(LPTHREAD_START_ROUTINE)&thread_ftn, // thread function name
		(LPVOID)this, // argument to thread function
		0, // use default creation flags
		&tid);
}

void Thread::join() {
	WaitForSingleObject(thread_handle, INFINITE);
}

MutexClass::MutexClass() {
	mutex = CreateMutex(
		NULL, // default security
		FALSE, // initially not owned
		NULL); // unamed mutex
}

MutexClass::~MutexClass() {
	CloseHandle(mutex);
}

void MutexClass::lock_mutex() {
	DWORD wait_result;
	wait_result = WaitForSingleObject(
		mutex, // handle to mutex
		INFINITE); // no time-out interval
}

void MutexClass::unlock_mutex() {
	ReleaseMutex(mutex);
}