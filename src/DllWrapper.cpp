#ifndef Dll_Wrapper_Cpp
#define Dll_Wrapper_Cpp

#include "DllWrapper.h"
#include "AssertString.h"

#ifndef WIN32
#include <dlfcn.h>
#endif

namespace /* 匿名命名空间保护本文件内部函数 */{

HMODULE Load(StdString path) {
#ifdef WIN32
	return ::LoadLibraryA(path.c_str());
#else
	return dlopen(path.c_str(), RTLD_LAZY);
#endif
}

void Free(HMODULE hModule) {
#ifdef WIN32
	::FreeLibrary (hModule);
#else
	dlclose(hModule);
#endif
}

void* GetProc(HMODULE hModule, StdString procName) {
	void* addr =
#ifdef WIN32
			::GetProcAddress(hModule, procName.c_str());
#else
			dlsym(hModule, procName.c_str());
#endif
	return addr;
}

}

/************************************************************************/
/*                         StaticDllWrapper                             */
/************************************************************************/

template<typename _Type>
StdString StaticDllWrapper<_Type>::_tag;

template<typename _Type>
SafeFuncList StaticDllWrapper<_Type>::procs;

template<typename _Type>
HMODULE StaticDllWrapper<_Type>::m_hModule = nullptr;

template<typename _Type>
PtrHolder* StaticDllWrapper<_Type>::MakePtrHolder() {
	std::shared_ptr<PtrHolder> ptr(new PtrHolder());
	procs.push_back(ptr);
	return ptr.get();
}

template<typename _Type>
bool StaticDllWrapper<_Type>::Load(StdString path) {
	if (m_hModule == nullptr) {
		m_hModule = ::Load(path);
	} else {
		ASSERT_STRING(false, "already load, please use Free() before.");
	}
	return (m_hModule != nullptr);
}

template<typename _Type>
void StaticDllWrapper<_Type>::Free() {
	if (m_hModule != nullptr) {
		::Free(m_hModule);
		m_hModule = nullptr;

		for (auto iter = procs.begin(); iter != procs.end(); iter++) {
			(*iter)->ptr = nullptr;
		}
	}
}

template<typename _Type>
bool StaticDllWrapper<_Type>::GetProcAddress(PtrHolder* funcPtr,
		StdString procName) {
	if (m_hModule == nullptr) {
		if (_Type::LazyLoad()) {
			_Type::TryLoad();
		}
	}
	if (m_hModule == nullptr) {
		return false;
	}
	return ((funcPtr->ptr = ::GetProc(m_hModule, procName)) != nullptr);
}

/************************************************************************/
/*                          ShareDllWrapper                             */
/************************************************************************/

template<typename _Type>
ShareDllWrapper<_Type>::ShareDllWrapper() :
		m_hModule(nullptr) {
}

template<typename _Type>
ShareDllWrapper<_Type>::ShareDllWrapper(StdString tag) :
		_tag(tag), m_hModule(nullptr) {
}

template<typename _Type>
ShareDllWrapper<_Type>::~ShareDllWrapper(void) {
	Free();
}

template<typename _Type>
bool ShareDllWrapper<_Type>::Load(StdString path) {
	if (m_hModule == nullptr) {
		m_hModule = ::Load(path);
	} else {
		ASSERT_STRING(false, "already load, please use Free() before.");
	}
	return (m_hModule != nullptr);
}

template<typename _Type>
void ShareDllWrapper<_Type>::Free() {
	if (m_hModule != nullptr) {
		::Free(m_hModule);
		m_hModule = nullptr;

		for (auto iter = procs.begin(); iter != procs.end(); iter++) {
			(*iter)->ptr = nullptr;
		}

		procs.clear();
	}
}

template<typename _Type>
bool ShareDllWrapper<_Type>::GetProcAddress(PtrHolder* funcPtr,
		StdString procName) {
	if (m_hModule == nullptr) {
		if (LazyLoad()) {
			TryLoad();
		}
	}
	if (m_hModule == nullptr) {
		return false;
	}
	return ((funcPtr->ptr = ::GetProc(m_hModule, procName)) != nullptr);
}

#endif /* Dll_Wrapper_Cpp */
