#ifndef Dll_Wrapper_H
#define Dll_Wrapper_H

#ifndef WIN32
typedef void* HMODULE;
#else
#include <Windows.h>
#endif

#include <vector>
#include <string>
#include <memory>

/**
 * 函数指针的容器
 */
struct PtrHolder {

	/**
	 * 真正的指针
	 */
	void* ptr;

	/**
	 * 构造函数
	 */
	PtrHolder(){
		ptr = nullptr;
	}

	/**
	 * 赋值构造函数
	 */
	PtrHolder(const PtrHolder& other) {
		ptr = other.ptr;
	}

};

/**
 * 定义标准字符串类
 */
#ifndef STD_STRING_TYPE
typedef std::string StdString;
#endif

/**
 * 定义导出函数列表，存储一般的函数指针
 */
typedef std::vector<PtrHolder*> FuncList;

/**
 * 定义导出函数列表，存储安全的函数指针
 */
typedef std::vector<std::shared_ptr<PtrHolder>> SafeFuncList;

/**
 * 动态链接/共享库包装类,静态存储策略
 */
template<typename _Type>
class StaticDllWrapper {

public:

	/**
	 * 获取当前模块的标签
	 * 
	 * @return 返回当前模块的标签
	 */
	static StdString GetTag() {
		return _tag;
	}

	/**
	 * 设置当前模块的标签
	 *
	 * @param tag
	 *         模块的标签
	 */
	static void SetTag(StdString tag) {
		_tag = tag;
	}

	/**
	 * 加载模块。重复加载前务必
	 * 调用Free()释放已加载模块。
	 *
	 * @param path
	 *        模块的绝对路径
	 * @return 加载成功返回 true，失败返回 false。
	 */
	static bool Load(StdString path);

	/**
	 * 获取当前模块的文件句柄
	 * 
	 * @return 返回当前模块的句柄
	 */
	static HMODULE GetHandle() {
		return m_hModule;
	}

	/**
	 * 释放模块
	 */
	static void Free();

	/**
	 * 获取函数入口
	 * 
	 * @param funcPtr
	 *        函数指针的容器
	 * @param procName
	 *        导出函数的名称
	 * @return 成功获得地址返回 true，否则返回 false。
	 */
	static bool GetProcAddress(PtrHolder* funcPtr, StdString procName);

protected:
	/**
	 * 生成函数指针的容器对象
	 *
	 * @return 返回生成的指针容器对象
	 */
	static PtrHolder* MakePtrHolder();

	/**
	 * 是否使用懒加载模式
	 *
	 * @return 使用懒加载模式返回 true，否则返回 false。
	 */
	static bool LazyLoad() { 
		return false; 
	}

	/**
	 * 尝试加载模块文件
	 */ 
	static void TryLoad() {
	}

protected:
	/**
	 * 模块句柄
	 */
	static HMODULE m_hModule;

	/**
	 * 函数入口表
	 */
	static SafeFuncList procs;

	/**
	 * 当前模块的标签
	 */
	static StdString _tag;
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
	 * 获取当前模块的标签
	 * 
	 * @return 返回当前模块的标签
	 */
	StdString GetTag() {
		return _tag;
	}

	/**
	 * 设置当前模块的标签
	 *
	 * @param tag
	 *         模块的标签
	 */
	void SetTag(StdString tag) {
		_tag = tag;
	}

	/**
	 * 加载模块。重复加载前务必
	 * 调用Free()释放已加载模块。
	 *
	 * @param path
	 *        模块的绝对路径
	 */
	bool Load(StdString path);

	/**
	 * 获取当前模块的文件句柄
	 * 
	 * @return 返回当前模块的句柄
	 */
	HMODULE GetHandle() {
		return m_hModule;
	}

	/**
	 * 释放模块
	 */
	void Free();

	/**
	 * 获取函数入口
	 * 
	 * @param funcPtr
	 *        函数指针的容器
	 * @param procName
	 *        导出函数的名称
	 * @return 成功获得地址返回 true，否则返回 false。
	 */
	bool GetProcAddress(PtrHolder* funcPtr, StdString procName);

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

protected:
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
	FuncList procs;
};

#endif /* Dll_Wrapper_H */