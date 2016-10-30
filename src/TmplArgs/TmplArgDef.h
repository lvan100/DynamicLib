/*
 * 作者：梁欢（lvan100@yeah.net）
 * 博客：http://blog.163.com/lvan100@yeah/
 * 授权：您可以使用这份文档进行任何用途，但原作者不承担任何责任。
 */


// 定义逗号（,）

#if _ArgNum_ == 0
#define COMMA		
#else
#define COMMA		,
#endif


// 定义类的名称

#ifndef _CLASS_NAME_
#define _CLASS_NAME_(x)		_YNAME_(x, _ArgNum_)
#endif


/*
 * template_cTcT(x)			--> class _T0 , class _T1 ... class _T9
 * template_cRcTcT(x)		--> class _ResultType , class _T0 ... class _T9
 * template_T(x)			--> _T9
 * template_TT(x)			--> _T0 , _T1 ... _T9
 * template_RTT(x)			--> _ResultType, _T0 , _T1 ... _T9
 * template_a(x)			--> arg9
 * template_Ta(x)			--> _T9 arg9
 * template_aa(x)			--> arg0 , arg1 ... arg9
 * template_TaTa(x)			--> _T0 arg0 , _T1 arg1 ... _T9 arg9
 * template_Func(x)			--> _TResult(_T0, _T1 ... _T9)
 * template_FuncPtrC(x)		--> _TResult(__cdecl *_ptr)(_T0, _T1 ... _T9)
 * template_FuncPtrS(x)		--> _TResult(_stdcall *_ptr)(_T0, _T1 ... _T9)
*/

#define templateX_cTcT		_YNAME_(template_cTcT, _ArgNum_)
#define templateX_cRcTcT	_YNAME_(template_cRcTcT, _ArgNum_)
#define templateX_T			_YNAME_(template_T, _ArgNum_)
#define templateX_TT		_YNAME_(template_TT, _ArgNum_)
#define templateX_RTT		_YNAME_(template_RTT, _ArgNum_)
#define templateX_a			_YNAME_(template_a, _ArgNum_)
#define templateX_Ta		_YNAME_(template_Ta, _ArgNum_)
#define templateX_aa		_YNAME_(template_aa, _ArgNum_)
#define templateX_TaTa		_YNAME_(template_TaTa, _ArgNum_)
#define templateX_Func		_YNAME_(template_Func, _ArgNum_)
#define templateX_FuncPtrC	_YNAME_(template_FuncPtrC, _ArgNum_)
#define templateX_FuncPtrS	_YNAME_(template_FuncPtrS, _ArgNum_)


/*
 * 将下面的文件替换成你自己的类型定义文档
 */

#include "..\\DllFuncT.h"


#undef COMMA
#undef templateX_cTcT
#undef templateX_cRcTcT
#undef templateX_T
#undef templateX_TT
#undef templateX_RTT
#undef templateX_a
#undef templateX_Ta
#undef templateX_aa
#undef templateX_TaTa
#undef templateX_Func
#undef templateX_FuncPtrC
#undef templateX_FuncPtrS