#ifndef Dll_Loader_H
#define Dll_Loader_H

#ifndef WIN32
typedef void* HMODULE;
#else
#include <Windows.h>
#endif

/**
 * 动态链接/共享库包装类
 */
class DllLoader {

public:
	/**
	 * 构造函数
	 */
	DllLoader();

	/**
	 * 析构函数
	 */
	virtual ~DllLoader();

	/**
	 * 加载模块。重复加载前务必
	 * 调用Free()释放已加载模块。
	 *
	 * @param path
	 *        模块的绝对路径
	 */
	bool Load(const char* path);

	/**
	 * 释放模块
	 */
	void Free();

	/**
	 * 获取函数入口
	 *
	 * @param name
	 *        导出函数的名称
	 * @return 返回加载的函数指针。
	 */
	void* GetProcAddress(const char* name);

private:
	/**
	 * 绝对不需要拷贝使用!
	 */
	DllLoader(const DllLoader&) = delete;
	DllLoader operator=(const DllLoader&) = delete;

protected:
	/**
	 * 模块句柄
	 */
	HMODULE m_hModule;

};

#endif /* Dll_Loader_H */