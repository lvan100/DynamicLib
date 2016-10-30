/*
 * 作者：梁欢（lvan100@yeah.net）
 * 博客：http://blog.163.com/lvan100@yeah/
 * 授权：您可以使用这份文档进行任何用途，但原作者不承担任何责任。
 */


#ifndef __Tmpl_Arg_Util_H__
#define __Tmpl_Arg_Util_H__


// 支持最多参数个数（除返回值外）:10

#define _ArgNum_Max_	10


// 连字符

#define _XNAME_(x, z)	x ## z

// 可以将一个宏参数解释成该宏代表的真实含义.
// 比如 : (#define _ArgNum_ 0)
// _YNAME_(Tmpl, _ArgNum_) ==> Tmpl0
// _XNAME_(Tmpl, _ArgNum_) ==> Tmpl_ArgNum_

#define _YNAME_(x, z)	_XNAME_(x, z)


// 定义 typename 关键字. 在模板参数定义
// 的时候使用class关键字有时候会报错.

#define template_c		typename

// ==> _TResult

#define template_R		_TResult

// ==> class _TResult

#define template_cR		template_c template_R

// ==> _T0

#define template_T(x)	_T##x

// ==> class _T0

#define template_cT(x)	template_c template_T(x)

// ==> arg0

#define template_a(x)	arg##x

// ==> _T0 arg0

#define template_Ta(x)	template_T(x) template_a(x)


// 非常关键的类型声明(注意不是类型定义,没有后面的{}) :
// _Get_Base_Impl 在实例化的时候只能有一个模板实参.

template<class _Tx> struct _Get_Base_Impl;


// 详细的宏定义列表

#include "TmplArgList.h"


// 定义0个函数参数的模板函数
// template<class _TResult>

#define _ArgNum_ 0
#include "TmplArgDef.h"
#undef _ArgNum_


// 定义1个函数参数的模板函数
// template<class _TResult, class _T0>

#define _ArgNum_ 1
#include "TmplArgDef.h"
#undef _ArgNum_


// 定义2个函数参数的模板函数
// template<class _TResult, class _T0, class _T1>

#define _ArgNum_ 2
#include "TmplArgDef.h"
#undef _ArgNum_


// 定义3个函数参数的模板函数
// template<class _TResult, class _T0, ... class _T2>

#define _ArgNum_ 3
#include "TmplArgDef.h"
#undef _ArgNum_


// 定义4个函数参数的模板函数
// template<class _TResult, class _T0, ... class _T3>

#define _ArgNum_ 4
#include "TmplArgDef.h"
#undef _ArgNum_


// 定义5个函数参数的模板函数
// template<class _TResult, class _T0, ... class _T4>

#define _ArgNum_ 5
#include "TmplArgDef.h"
#undef _ArgNum_


// 定义6个函数参数的模板函数
// template<class _TResult, class _T0, ... class _T5>

#define _ArgNum_ 6
#include "TmplArgDef.h"
#undef _ArgNum_


// 定义7个函数参数的模板函数
// template<class _TResult, class _T0, ... class _T6>

#define _ArgNum_ 7
#include "TmplArgDef.h"
#undef _ArgNum_


// 定义8个函数参数的模板函数
// template<class _TResult, class _T0, ... class _T7>

#define _ArgNum_ 8
#include "TmplArgDef.h"
#undef _ArgNum_


// 定义9个函数参数的模板函数
// template<class _TResult, class _T0, ... class _T8>

#define _ArgNum_ 9
#include "TmplArgDef.h"
#undef _ArgNum_


// 定义10个函数参数的模板函数
// template<class _TResult, class _T0, ... class _T9>

#define _ArgNum_ 10
#include "TmplArgDef.h"
#undef _ArgNum_


#endif /*__Tmpl_Arg_Util_H__*/