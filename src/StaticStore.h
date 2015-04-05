#ifdef BaseDllWrapper
#undef BaseDllWrapper
#endif

#include "DllWrapper.h"
#include "DllWrapper.cpp"

/**
 * 定义和存储策略相同的包装类型
 */
#define BaseDllWrapper StaticDllWrapper

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
#define DEFINE_FUNCTION(_Name, _Pointer, _CallType) \
	\
public: \
	\
	static TypeGroup<_Pointer>::Type_Result _Name( \
			TypeGroup<_Pointer>::Type_Arg1 arg1 = Default<TypeGroup<_Pointer>::Type_Arg1>()(), \
			TypeGroup<_Pointer>::Type_Arg2 arg2 = Default<TypeGroup<_Pointer>::Type_Arg2>()(), \
			TypeGroup<_Pointer>::Type_Arg3 arg3 = Default<TypeGroup<_Pointer>::Type_Arg3>()(), \
			TypeGroup<_Pointer>::Type_Arg4 arg4 = Default<TypeGroup<_Pointer>::Type_Arg4>()(), \
			TypeGroup<_Pointer>::Type_Arg5 arg5 = Default<TypeGroup<_Pointer>::Type_Arg5>()(), \
			TypeGroup<_Pointer>::Type_Arg6 arg6 = Default<TypeGroup<_Pointer>::Type_Arg6>()(), \
			TypeGroup<_Pointer>::Type_Arg7 arg7 = Default<TypeGroup<_Pointer>::Type_Arg7>()(), \
			TypeGroup<_Pointer>::Type_Arg8 arg8 = Default<TypeGroup<_Pointer>::Type_Arg8>()(), \
			TypeGroup<_Pointer>::Type_Arg9 arg9 = Default<TypeGroup<_Pointer>::Type_Arg9>()()) \
	{ \
		static PtrHolder* ptrHolder = MakePtrHolder(); \
		if (ptrHolder->ptr == nullptr){ \
			GetProcAddress(ptrHolder, #_Name); \
		} \
		if (ptrHolder->ptr == nullptr){ \
			return Default<TypeGroup<_Pointer>::Type_Result>()(); \
		} \
		return TypeGroup<_Pointer>::_CallType##_Call(ptrHolder->ptr, \
					arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9); \
	}

#ifdef OVERRIDE_TYPE
#undef OVERRIDE_TYPE
#endif

#define OVERRIDE_TYPE static

#include "OtherStore.h"
