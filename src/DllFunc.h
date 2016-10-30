#pragma once

#include "DllLoader.h"

/**
 * 函数调用类型
 */
enum DllFuncType {
	DTF_CDECL,
	DTF_STDCALL
};

#include "TmplArgs/TmplArgUtil.h"

/**
 * 函数封装类型
 */
template<class _Fty> class DllFunc : public _Get_Base_Impl<_Fty>::_Type, public DllLoader {

	typedef typename _Get_Base_Impl<_Fty>::_Type DllFuncBase;

public:
	DllFunc(const char* name, DllFuncType type = DllFuncType::DTF_CDECL)
		: _name(name), _type(type) {
	}

	DllFunc(const char* path, const char* name, DllFuncType type = DllFuncType::DTF_CDECL)
		: _name(name), _type(type) {
		Load(path);
	}

	template<class... Arg>
	typename DllFuncBase::_R operator() (Arg... arg) {

		if (callback == nullptr) {
			callback = GetProcAddress(_name);
		}

		if (callback != nullptr) {
			if (_type == DllFuncType::DTF_CDECL) {
				return ((_cdecl_ptr)callback)(arg...);
			}
			if (_type == DllFuncType::DTF_STDCALL) {
				return ((_stdcall_ptr)callback)(arg...);
			}
		}

		return DllFuncBase::_R();
	}

private:
	/**
	 * 函数调用类型
	 */
	DllFuncType _type;

	/**
	 * 函数指针
	 */
	void* callback = nullptr;

	/**
	 * 函数名称
	 */
	const char* _name = nullptr;

};