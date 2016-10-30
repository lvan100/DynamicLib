#define _DLL_FUNC_T		_CLASS_NAME_(_DllFuncT)

template<templateX_cRcTcT> struct _DLL_FUNC_T {

	typedef template_R _R;

	templateX_FuncPtrC
	templateX_FuncPtrS

};

template<templateX_cRcTcT>
struct _Get_Base_Impl<templateX_Func>
{
	typedef _DLL_FUNC_T<templateX_RTT> _Type;
};

#undef _DLL_FUNC_T