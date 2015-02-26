#ifndef DynamicLib_H
#define DynamicLib_H

#include "TypeGroup.h"

#if !defined( STORAGE_TYPE )
	#error "不要直接包括本文件，请使用“StaticStore.h”或者“ShareStore.h”"
#endif

/**
 * 声明导出函数
 * 
 * @Param _Name
 *        导出函数的名称
 * @Param _Pointer
 *        函数参数的原型
 * @Param _CallType
 *        函数的调用规则
 */
#define DEFINE_FUNCTION(_Name, _Pointer, _CallType) \
public: \
	template<typename _Type> \
	STORAGE_TYPE TypeGroup<_Pointer>::Type_Result _Name(TypeGroup<_Pointer>::Type_Arg1 arg1, TypeGroup<_Pointer>::Type_Arg2 arg2, TypeGroup<_Pointer>::Type_Arg3 arg3, TypeGroup<_Pointer>::Type_Arg4 arg4, TypeGroup<_Pointer>::Type_Arg5 arg5, TypeGroup<_Pointer>::Type_Arg6 arg6, TypeGroup<_Pointer>::Type_Arg7 arg7, TypeGroup<_Pointer>::Type_Arg8 arg8, TypeGroup<_Pointer>::Type_Arg9 arg9, TypeGroup<_Pointer>::Type_Arg10 arg10, TypeGroup<_Pointer>::Type_Arg11 arg11, TypeGroup<_Pointer>::Type_Arg12 arg12, TypeGroup<_Pointer>::Type_Arg13 arg13) \
	{ \
		typedef TypeGroup<_Pointer>::_CallType##_Ptr _##_Name; \
		/*STORAGE_TYPE*/ _##_Name dll_export = (_##_Name)GetProcAddress(#_Name); \
		return (dll_export != nullptr) ? dll_export(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13) : Default<TypeGroup<_Pointer>::Type_Result>()(); \
	} \
	\
	template<typename _Type> \
	STORAGE_TYPE TypeGroup<_Pointer>::Type_Result _Name(TypeGroup<_Pointer>::Type_Arg1 arg1, TypeGroup<_Pointer>::Type_Arg2 arg2, TypeGroup<_Pointer>::Type_Arg3 arg3, TypeGroup<_Pointer>::Type_Arg4 arg4, TypeGroup<_Pointer>::Type_Arg5 arg5, TypeGroup<_Pointer>::Type_Arg6 arg6, TypeGroup<_Pointer>::Type_Arg7 arg7, TypeGroup<_Pointer>::Type_Arg8 arg8, TypeGroup<_Pointer>::Type_Arg9 arg9, TypeGroup<_Pointer>::Type_Arg10 arg10, TypeGroup<_Pointer>::Type_Arg11 arg11, TypeGroup<_Pointer>::Type_Arg12 arg12) \
	{ \
		static_assert(TypeIsSame<TypeGroup<_Pointer>::Type_Arg13, _Null>::Value, "too few arguments in function call!"); \
		typedef TypeGroup<_Pointer>::_CallType##_Ptr _##_Name; \
		/*STORAGE_TYPE*/ _##_Name dll_export = (_##_Name)GetProcAddress(#_Name); \
		return (dll_export != nullptr) ? dll_export(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12) : Default<TypeGroup<_Pointer>::Type_Result>()(); \
	} \
	\
	template<typename _Type> \
	STORAGE_TYPE TypeGroup<_Pointer>::Type_Result _Name(TypeGroup<_Pointer>::Type_Arg1 arg1, TypeGroup<_Pointer>::Type_Arg2 arg2, TypeGroup<_Pointer>::Type_Arg3 arg3, TypeGroup<_Pointer>::Type_Arg4 arg4, TypeGroup<_Pointer>::Type_Arg5 arg5, TypeGroup<_Pointer>::Type_Arg6 arg6, TypeGroup<_Pointer>::Type_Arg7 arg7, TypeGroup<_Pointer>::Type_Arg8 arg8, TypeGroup<_Pointer>::Type_Arg9 arg9, TypeGroup<_Pointer>::Type_Arg10 arg10, TypeGroup<_Pointer>::Type_Arg11 arg11) \
	{ \
		static_assert(TypeIsSame<TypeGroup<_Pointer>::Type_Arg12, _Null>::Value, "too few arguments in function call!"); \
		typedef TypeGroup<_Pointer>::_CallType##_Ptr _##_Name; \
		/*STORAGE_TYPE*/ _##_Name dll_export = (_##_Name)GetProcAddress(#_Name); \
		return (dll_export != nullptr) ? dll_export(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11) : Default<TypeGroup<_Pointer>::Type_Result>()(); \
	} \
	\
	template<typename _Type> \
	STORAGE_TYPE TypeGroup<_Pointer>::Type_Result _Name(TypeGroup<_Pointer>::Type_Arg1 arg1, TypeGroup<_Pointer>::Type_Arg2 arg2, TypeGroup<_Pointer>::Type_Arg3 arg3, TypeGroup<_Pointer>::Type_Arg4 arg4, TypeGroup<_Pointer>::Type_Arg5 arg5, TypeGroup<_Pointer>::Type_Arg6 arg6, TypeGroup<_Pointer>::Type_Arg7 arg7, TypeGroup<_Pointer>::Type_Arg8 arg8, TypeGroup<_Pointer>::Type_Arg9 arg9, TypeGroup<_Pointer>::Type_Arg10 arg10) \
	{ \
		static_assert(TypeIsSame<TypeGroup<_Pointer>::Type_Arg11, _Null>::Value, "too few arguments in function call!"); \
		typedef TypeGroup<_Pointer>::_CallType##_Ptr _##_Name; \
		/*STORAGE_TYPE*/ _##_Name dll_export = (_##_Name)GetProcAddress(#_Name); \
		return (dll_export != nullptr) ? dll_export(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) : Default<TypeGroup<_Pointer>::Type_Result>()(); \
	} \
	\
	template<typename _Type> \
	STORAGE_TYPE TypeGroup<_Pointer>::Type_Result _Name(TypeGroup<_Pointer>::Type_Arg1 arg1, TypeGroup<_Pointer>::Type_Arg2 arg2, TypeGroup<_Pointer>::Type_Arg3 arg3, TypeGroup<_Pointer>::Type_Arg4 arg4, TypeGroup<_Pointer>::Type_Arg5 arg5, TypeGroup<_Pointer>::Type_Arg6 arg6, TypeGroup<_Pointer>::Type_Arg7 arg7, TypeGroup<_Pointer>::Type_Arg8 arg8, TypeGroup<_Pointer>::Type_Arg9 arg9) \
	{ \
		static_assert(TypeIsSame<TypeGroup<_Pointer>::Type_Arg10, _Null>::Value, "too few arguments in function call!"); \
		typedef TypeGroup<_Pointer>::_CallType##_Ptr _##_Name; \
		/*STORAGE_TYPE*/ _##_Name dll_export = (_##_Name)GetProcAddress(#_Name); \
		return (dll_export != nullptr) ? dll_export(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) : Default<TypeGroup<_Pointer>::Type_Result>()(); \
	} \
	\
	template<typename _Type> \
	STORAGE_TYPE TypeGroup<_Pointer>::Type_Result _Name(TypeGroup<_Pointer>::Type_Arg1 arg1, TypeGroup<_Pointer>::Type_Arg2 arg2, TypeGroup<_Pointer>::Type_Arg3 arg3, TypeGroup<_Pointer>::Type_Arg4 arg4, TypeGroup<_Pointer>::Type_Arg5 arg5, TypeGroup<_Pointer>::Type_Arg6 arg6, TypeGroup<_Pointer>::Type_Arg7 arg7, TypeGroup<_Pointer>::Type_Arg8 arg8) \
	{ \
		static_assert(TypeIsSame<TypeGroup<_Pointer>::Type_Arg9, _Null>::Value, "too few arguments in function call!"); \
		typedef TypeGroup<_Pointer>::_CallType##_Ptr _##_Name; \
		/*STORAGE_TYPE*/ _##_Name dll_export = (_##_Name)GetProcAddress(#_Name); \
		return (dll_export != nullptr) ? dll_export(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) : Default<TypeGroup<_Pointer>::Type_Result>()(); \
	} \
	\
	template<typename _Type> \
	STORAGE_TYPE TypeGroup<_Pointer>::Type_Result _Name(TypeGroup<_Pointer>::Type_Arg1 arg1, TypeGroup<_Pointer>::Type_Arg2 arg2, TypeGroup<_Pointer>::Type_Arg3 arg3, TypeGroup<_Pointer>::Type_Arg4 arg4, TypeGroup<_Pointer>::Type_Arg5 arg5, TypeGroup<_Pointer>::Type_Arg6 arg6, TypeGroup<_Pointer>::Type_Arg7 arg7) \
	{ \
		static_assert(TypeIsSame<TypeGroup<_Pointer>::Type_Arg8, _Null>::Value, "too few arguments in function call!"); \
		typedef TypeGroup<_Pointer>::_CallType##_Ptr _##_Name; \
		/*STORAGE_TYPE*/ _##_Name dll_export = (_##_Name)GetProcAddress(#_Name); \
		return (dll_export != nullptr) ? dll_export(arg1, arg2, arg3, arg4, arg5, arg6, arg7) : Default<TypeGroup<_Pointer>::Type_Result>()(); \
	} \
	\
	template<typename _Type> \
	STORAGE_TYPE TypeGroup<_Pointer>::Type_Result _Name(TypeGroup<_Pointer>::Type_Arg1 arg1, TypeGroup<_Pointer>::Type_Arg2 arg2, TypeGroup<_Pointer>::Type_Arg3 arg3, TypeGroup<_Pointer>::Type_Arg4 arg4, TypeGroup<_Pointer>::Type_Arg5 arg5, TypeGroup<_Pointer>::Type_Arg6 arg6) \
	{ \
		static_assert(TypeIsSame<TypeGroup<_Pointer>::Type_Arg7, _Null>::Value, "too few arguments in function call!"); \
		typedef TypeGroup<_Pointer>::_CallType##_Ptr _##_Name; \
		/*STORAGE_TYPE*/ _##_Name dll_export = (_##_Name)GetProcAddress(#_Name); \
		return (dll_export != nullptr) ? dll_export(arg1, arg2, arg3, arg4, arg5, arg6) : Default<TypeGroup<_Pointer>::Type_Result>()(); \
	} \
	\
	template<typename _Type> \
	STORAGE_TYPE TypeGroup<_Pointer>::Type_Result _Name(TypeGroup<_Pointer>::Type_Arg1 arg1, TypeGroup<_Pointer>::Type_Arg2 arg2, TypeGroup<_Pointer>::Type_Arg3 arg3, TypeGroup<_Pointer>::Type_Arg4 arg4, TypeGroup<_Pointer>::Type_Arg5 arg5) \
	{ \
		static_assert(TypeIsSame<TypeGroup<_Pointer>::Type_Arg6, _Null>::Value, "too few arguments in function call!"); \
		typedef TypeGroup<_Pointer>::_CallType##_Ptr _##_Name; \
		/*STORAGE_TYPE*/ _##_Name dll_export = (_##_Name)GetProcAddress(#_Name); \
		return (dll_export != nullptr) ? dll_export(arg1, arg2, arg3, arg4, arg5) : Default<TypeGroup<_Pointer>::Type_Result>()(); \
	} \
	\
	template<typename _Type> \
	STORAGE_TYPE TypeGroup<_Pointer>::Type_Result _Name(TypeGroup<_Pointer>::Type_Arg1 arg1, TypeGroup<_Pointer>::Type_Arg2 arg2, TypeGroup<_Pointer>::Type_Arg3 arg3, TypeGroup<_Pointer>::Type_Arg4 arg4) \
	{ \
		static_assert(TypeIsSame<TypeGroup<_Pointer>::Type_Arg5, _Null>::Value, "too few arguments in function call!"); \
		typedef TypeGroup<_Pointer>::_CallType##_Ptr _##_Name; \
		/*STORAGE_TYPE*/ _##_Name dll_export = (_##_Name)GetProcAddress(#_Name); \
		return (dll_export != nullptr) ? dll_export(arg1, arg2, arg3, arg4) : Default<TypeGroup<_Pointer>::Type_Result>()(); \
	} \
	\
	template<typename _Type> \
	STORAGE_TYPE TypeGroup<_Pointer>::Type_Result _Name(TypeGroup<_Pointer>::Type_Arg1 arg1, TypeGroup<_Pointer>::Type_Arg2 arg2, TypeGroup<_Pointer>::Type_Arg3 arg3) \
	{ \
		static_assert(TypeIsSame<TypeGroup<_Pointer>::Type_Arg4, _Null>::Value, "too few arguments in function call!"); \
		typedef TypeGroup<_Pointer>::_CallType##_Ptr _##_Name; \
		/*STORAGE_TYPE*/ _##_Name dll_export = (_##_Name)GetProcAddress(#_Name); \
		return (dll_export != nullptr) ? dll_export(arg1, arg2, arg3) : Default<TypeGroup<_Pointer>::Type_Result>()(); \
	} \
	\
	template<typename _Type> \
	STORAGE_TYPE TypeGroup<_Pointer>::Type_Result _Name(TypeGroup<_Pointer>::Type_Arg1 arg1, TypeGroup<_Pointer>::Type_Arg2 arg2) \
	{ \
		static_assert(TypeIsSame<TypeGroup<_Pointer>::Type_Arg3, _Null>::Value, "too few arguments in function call!"); \
		typedef TypeGroup<_Pointer>::_CallType##_Ptr _##_Name; \
		/*STORAGE_TYPE*/ _##_Name dll_export = (_##_Name)GetProcAddress(#_Name); \
		return (dll_export != nullptr) ? dll_export(arg1, arg2) : Default<TypeGroup<_Pointer>::Type_Result>()(); \
	} \
	\
	template<typename _Type> \
	STORAGE_TYPE TypeGroup<_Pointer>::Type_Result _Name(TypeGroup<_Pointer>::Type_Arg1 arg1) \
	{ \
		static_assert(TypeIsSame<TypeGroup<_Pointer>::Type_Arg2, _Null>::Value, "too few arguments in function call!"); \
		typedef TypeGroup<_Pointer>::_CallType##_Ptr _##_Name; \
		/*STORAGE_TYPE*/ _##_Name dll_export = (_##_Name)GetProcAddress(#_Name); \
		return (dll_export != nullptr) ? dll_export(arg1) : Default<TypeGroup<_Pointer>::Type_Result>()(); \
	} \
	\
	template<typename _Type> \
	STORAGE_TYPE TypeGroup<_Pointer>::Type_Result _Name() \
	{ \
		static_assert(TypeIsSame<TypeGroup<_Pointer>::Type_Arg1, _Null>::Value, "too few arguments in function call!"); \
		typedef TypeGroup<_Pointer>::_CallType##_Ptr _##_Name; \
		/*STORAGE_TYPE*/ _##_Name dll_export = (_##_Name)GetProcAddress(#_Name); \
		return (dll_export != nullptr) ? dll_export() : Default<TypeGroup<_Pointer>::Type_Result>()(); \
	}

/**
 * 声明 __cdecl 导出函数
 * 
 * @Param _Name
 *        导出函数的名称
 * @Param _Pointer
 *        函数参数的原型
 */
#define DEFINE_CDECL_FUNCTION(_Name, _Pointer) \
	DEFINE_FUNCTION(_Name, _Pointer, __cdecl)

/**
 * 声明 _stdcall 导出函数
 * 
 * @Param _Name
 *        导出函数的名称
 * @Param _Pointer
 *        函数参数的原型
 */
#define DEFINE_STDCALL_FUNCTION(_Name, _Pointer) \
	DEFINE_FUNCTION(_Name, _Pointer, _stdcall)

/**
 * 启动懒加载模式，只针对 ShareDllWrapper 有效
 */
#define DEFINE_DEFAULT_FILE(_FileName) \
	OVERRIDE_TYPE bool LazyLoad() { return true; } \
	OVERRIDE_TYPE void TryLoad() { Load(_FileName); }

#endif /* DynamicLib_H */