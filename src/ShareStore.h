#ifdef BaseDllWrapper
#undef BaseDllWrapper
#endif

#include "DllWrapper.h"
#include "DllWrapper.cpp"

/**
 * 定义和存储策略相同的包装类型
 */
#define BaseDllWrapper ShareDllWrapper

#ifdef DEFINE_FUNCTION
#undef DEFINE_FUNCTION
#endif

#include "TypeGroup.h"

/**
 * 声明导出函数
 * 
 * @param _Name
 *        导出函数的名称
 * @param _Pointer
 *        函数参数的原型
 * @param _CallType
 *        函数的调用规则
 */

#if !((defined DEBUG) || (defined _DEBUG))

#define DEFINE_FUNCTION(_Name, _Pointer, _CallType) protected: \
	\
	PtrHolder _Name##_PtrHolder; /* 函数指针容器对象 */ \
	\
public: \
	\
	TypeGroup<_Pointer>::Type_Result _Name( \
		TypeGroup<_Pointer>::Type_Arg1 arg1 = Default<TypeGroup<_Pointer>::Type_Arg1>::Value, \
		TypeGroup<_Pointer>::Type_Arg2 arg2 = Default<TypeGroup<_Pointer>::Type_Arg2>::Value, \
		TypeGroup<_Pointer>::Type_Arg3 arg3 = Default<TypeGroup<_Pointer>::Type_Arg3>::Value, \
		TypeGroup<_Pointer>::Type_Arg4 arg4 = Default<TypeGroup<_Pointer>::Type_Arg4>::Value, \
		TypeGroup<_Pointer>::Type_Arg5 arg5 = Default<TypeGroup<_Pointer>::Type_Arg5>::Value, \
		TypeGroup<_Pointer>::Type_Arg6 arg6 = Default<TypeGroup<_Pointer>::Type_Arg6>::Value, \
		TypeGroup<_Pointer>::Type_Arg7 arg7 = Default<TypeGroup<_Pointer>::Type_Arg7>::Value, \
		TypeGroup<_Pointer>::Type_Arg8 arg8 = Default<TypeGroup<_Pointer>::Type_Arg8>::Value, \
		TypeGroup<_Pointer>::Type_Arg9 arg9 = Default<TypeGroup<_Pointer>::Type_Arg9>::Value) \
	{ \
		if (_Name##_PtrHolder.ptr == nullptr) { \
			if (GetProcAddress(&_Name##_PtrHolder, #_Name)) { \
				procs.push_back(&_Name##_PtrHolder); \
			} \
		} \
		if (_Name##_PtrHolder.ptr == nullptr){ \
			return Default<TypeGroup<_Pointer>::Type_Result>()(); /* 针对void特殊处理 */ \
		} \
		return TypeGroup<_Pointer>::_CallType##_Call(_Name##_PtrHolder.ptr, \
					arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9); \
	} \

#else

#define DEFINE_FUNCTION(_Name, _Pointer, _CallType) protected: \
	\
	PtrHolder _Name##_PtrHolder; /* 函数指针容器对象 */ \
	\
public: \
	\
	TypeGroup<_Pointer>::Type_Result _Name(\
		TypeGroup<_Pointer>::Type_Arg1 arg1 = Default<TypeGroup<_Pointer>::Type_Arg1>()(), \
		TypeGroup<_Pointer>::Type_Arg2 arg2 = Default<TypeGroup<_Pointer>::Type_Arg2>()(), \
		TypeGroup<_Pointer>::Type_Arg3 arg3 = Default<TypeGroup<_Pointer>::Type_Arg3>()(), \
		TypeGroup<_Pointer>::Type_Arg4 arg4 = Default<TypeGroup<_Pointer>::Type_Arg4>()(), \
		TypeGroup<_Pointer>::Type_Arg5 arg5 = Default<TypeGroup<_Pointer>::Type_Arg5>()(), \
		TypeGroup<_Pointer>::Type_Arg6 arg6 = Default<TypeGroup<_Pointer>::Type_Arg6>()(), \
		TypeGroup<_Pointer>::Type_Arg7 arg7 = Default<TypeGroup<_Pointer>::Type_Arg7>()(), \
		TypeGroup<_Pointer>::Type_Arg8 arg8 = Default<TypeGroup<_Pointer>::Type_Arg8>()(), \
		TypeGroup<_Pointer>::Type_Arg9 arg9 = Default<TypeGroup<_Pointer>::Type_Arg9>(1)()) \
	{ \
		if (DefaultCount::num + TypeGroup<_Pointer>::N > 9) { \
			ASSERT_STRING(false, "the function call (%s) needs %d arguments but only %d!", #_Name, TypeGroup<_Pointer>::N, 9 - DefaultCount::num);  \
		} \
		\
		DefaultCount::num = -1; /* 为什么不是0？如果该函数返回默认值会让num加1. */ \
		\
		if (_Name##_PtrHolder.ptr == nullptr) { \
			if (GetProcAddress(&_Name##_PtrHolder, #_Name)) { \
				procs.push_back(&_Name##_PtrHolder); \
			} \
		} \
		if (_Name##_PtrHolder.ptr == nullptr){ \
			return Default<TypeGroup<_Pointer>::Type_Result>()(); /* 针对void特殊处理 */ \
		} \
		return TypeGroup<_Pointer>::_CallType##_Call(_Name##_PtrHolder.ptr, \
			arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9); \
	} \

#endif

#ifdef OVERRIDE_TYPE
#undef OVERRIDE_TYPE
#endif

#define OVERRIDE_TYPE virtual

#include "OtherStore.h"
