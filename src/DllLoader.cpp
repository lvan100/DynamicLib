#include <stdio.h>
#include <assert.h>

/**
* 封装assert宏，提供运行时级别的友好的错误信息
*/

#define ASSERT_STRING(_Expression, ...) \
	(void)((!!(_Expression)) || (printf(__VA_ARGS__), printf("\n"), 0) || (assert(_Expression), 0))

#include "DllLoader.h"

#ifndef WIN32
#include <dlfcn.h>
#endif

namespace /* 匿名命名空间保护本文件内部函数 */ {

	HMODULE Load(const char* path) {
#ifdef WIN32
		return ::LoadLibraryA(path);
#else
		return dlopen(path, RTLD_LAZY);
#endif
	}

	void Free(HMODULE hModule) {
#ifdef WIN32
		::FreeLibrary(hModule);
#else
		dlclose(hModule);
#endif
	}

	void* GetProc(HMODULE hModule, const char* procName) {
		void* addr =
#ifdef WIN32
			::GetProcAddress(hModule, procName);
#else
			dlsym(hModule, procName);
#endif
		return addr;
	}

}

DllLoader::DllLoader() :
	m_hModule(nullptr) {
}

DllLoader::~DllLoader(void) {
	Free();
}

bool DllLoader::Load(const char* path) {
	if (m_hModule == nullptr) {
		m_hModule = ::Load(path);
	} else {
		ASSERT_STRING(false, "already load, please use Free() before.");
	}
	return (m_hModule != nullptr);
}

void DllLoader::Free() {
	if (m_hModule != nullptr) {
		::Free(m_hModule);
		m_hModule = nullptr;
	}
}

void* DllLoader::GetProcAddress(const char* name) {
	if (m_hModule == nullptr) {
		return nullptr;
	}
	return ::GetProc(m_hModule, name);
}