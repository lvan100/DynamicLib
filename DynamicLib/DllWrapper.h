#ifndef Dll_Wrapper_H
#define Dll_Wrapper_H

#include <map>
#include <string>
using namespace std;

#ifndef WIN32
typedef void* HMODULE;
#else
#include <Windows.h>
#endif

/**
 * 定义标准字符串类
 */
#ifndef STD_STRING_TYPE
typedef std::string StdString;
#endif

/**
 * 定义函数映射列表
 */
typedef std::map<StdString, void*> FuncMap;

/**
 * 动态链接/共享库包装类,静态存储策略
 */
template<typename _Type>
class StaticDllWrapper {

public:

	/**
	 * 加载模块。重复加载前务必
	 * 调用Free()释放已加载模块。
	 *
	 * @Param path
	 *        模块的绝对路径
	 */
	static bool Load(StdString path);

	/**
	 * 释放模块
	 */
	static void Free();

	/**
	 * 获取函数入口
	 * 
	 * @Param procName
	 *        导出函数的名称
	 */
	static void* GetProcAddress(StdString procName);

	/**
	 * 检查入口点是否存在，该函数只用于调试模式
	 * 
	 * @Param procName
	 *        导出函数的名称
	 * @Return 存在返回 true，不存在返回 false
	 */
	static bool CheckProcAddress(StdString procName) {
#ifdef _DEBUG
		return (GetProcAddress(procName) != nullptr);
#else
		return true;
#endif
	}

	/**
	 * 获取当前模块的标签
	 * 
	 * @Return 返回当前模块的标签
	 */
	static StdString GetTag() {
		return _tag;
	}

	/**
	 * 设置当前模块的标签
	 *
	 * @Param tag
	 *         模块的标签
	 */
	static void SetTag(StdString tag) {
		_tag = tag;
	}

	/**
	 * 获取当前模块的文件句柄
	 * 
	 * @Return 返回当前模块的句柄
	 */
	static HMODULE GetHandle() {
		return m_hModule;
	}

protected:
	/**
	 * 是否使用懒加载模式
	 */
	static bool LazyLoad() { 
		return false; 
	}

	/**
	 * 尝试加载模块文件
	 */ 
	static void TryLoad() {
	}

private:
	/**
	 * 模块句柄
	 */
	static HMODULE m_hModule;

	/**
	 * 当前模块的标签
	 */
	static StdString _tag;

	/**
	 * 函数入口表
	 */
	static FuncMap procs;
};

/**
 * 动态链接/共享库包装类,动态存储策略
 */
template<typename _Type>
 class ShareDllWrapper {

public:
	/**
	 * 构造函数
	 */
	ShareDllWrapper(StdString tag);

	/**
	 * 析构函数
	 */
	~ShareDllWrapper(void);

	/**
	 * 构造函数
	 */
	ShareDllWrapper();

	/**
	 * 加载模块。重复加载前务必
	 * 调用Free()释放已加载模块。
	 *
	 * @Param path
	 *        模块的绝对路径
	 */
	bool Load(StdString path);

	/**
	 * 释放模块
	 */
	void Free();

	/**
	 * 获取函数入口
	 * 
	 * @Param procName
	 *        导出函数的名称
	 */
	void* GetProcAddress(StdString procName);

	/**
	 * 检查入口点是否存在，该函数只用于调试模式
	 * 
	 * @Param procName
	 *        导出函数的名称
	 * @Return 存在返回 true，不存在返回 false
	 */
	bool CheckProcAddress(StdString procName) {
#ifdef _DEBUG
		return (GetProcAddress(procName) != nullptr);
#else
		return true;
#endif
	}

	/**
	 * 获取当前模块的标签
	 * 
	 * @Return 返回当前模块的标签
	 */
	StdString GetTag() {
		return _tag;
	}

	/**
	 * 设置当前模块的标签
	 *
	 * @Param tag
	 *         模块的标签
	 */
	void SetTag(StdString tag) {
		_tag = tag;
	}

	/**
	 * 获取当前模块的文件句柄
	 * 
	 * @Return 返回当前模块的句柄
	 */
	HMODULE GetHandle() {
		return m_hModule;
	}

protected:
	/**
	 * 是否使用懒加载模式
	 */
	virtual bool LazyLoad() { 
		return false; 
	}

	/**
	 * 尝试加载模块文件
	 */ 
	virtual void TryLoad() {
	}

private:
	/**
	 * 模块句柄
	 */
	HMODULE m_hModule;

	/**
	 * 当前模块的标签
	 */
	StdString _tag;

	/**
	 * 函数入口表
	 */
	FuncMap procs;
};

#endif /* Dll_Wrapper_H */