#ifdef DEFINE_CDECL_FUNCTION
#undef DEFINE_CDECL_FUNCTION
#endif

/**
 * 声明 __cdecl 导出函数
 * 
 * @param _Name
 *        导出函数的名称
 * @param _Pointer
 *        函数参数的原型
 */
#define DEFINE_CDECL_FUNCTION(_Name, _Pointer) \
	DEFINE_FUNCTION(_Name, _Pointer, __cdecl)

#ifdef DEFINE_STDCALL_FUNCTION
#undef DEFINE_STDCALL_FUNCTION
#endif

/**
 * 声明 _stdcall 导出函数
 * 
 * @param _Name
 *        导出函数的名称
 * @param _Pointer
 *        函数参数的原型
 */
#define DEFINE_STDCALL_FUNCTION(_Name, _Pointer) \
	DEFINE_FUNCTION(_Name, _Pointer, _stdcall)

#ifdef DEFINE_DEFAULT_FILE
#undef DEFINE_DEFAULT_FILE
#endif

/**
 * 启动懒加载模式，只针对 ShareDllWrapper 有效
 */
#define DEFINE_DEFAULT_FILE(_FileName) \
	OVERRIDE_TYPE bool LazyLoad() { return true; } \
	OVERRIDE_TYPE void TryLoad() { Load(_FileName); }

