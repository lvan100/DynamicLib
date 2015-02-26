#ifdef STORAGE_TYPE
#undef STORAGE_TYPE
#endif

/**
 * 定义存储策略
 */
#define STORAGE_TYPE static

#include "DynamicLib.h"

#ifdef BaseDllWrapper
#undef BaseDllWrapper
#endif

#include "DllWrapper.h"
#include "DllWrapper.cpp"

/**
 * 定义和存储策略相同的包装类型
 */
#define BaseDllWrapper StaticDllWrapper

#ifdef OVERRIDE_TYPE
#undef OVERRIDE_TYPE
#endif

#define OVERRIDE_TYPE static