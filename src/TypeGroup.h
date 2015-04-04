#ifndef Type_Group_H
#define Type_Group_H

/**
 * 定义空类型，用于模板参数占位
 */
struct _Null{};

/**
 * 单参数模板声明，用于模板选型
 */
template<class _Tx>
struct _Get_TypeGroup;

/**
 * 13个参数的模板
 */
template
	< typename _Result
	, typename _Arg1
	, typename _Arg2
	, typename _Arg3
	, typename _Arg4
	, typename _Arg5
	, typename _Arg6
	, typename _Arg7
	, typename _Arg8
	, typename _Arg9
	, typename _Arg10
	, typename _Arg11
	, typename _Arg12
	, typename _Arg13 >
struct BaseTypeGroup_13
{
	typedef _Result	Type_Result;
		
	typedef _Arg1	Type_Arg1;
	typedef _Arg2	Type_Arg2;
	typedef _Arg3	Type_Arg3;
	typedef _Arg4	Type_Arg4;
	typedef _Arg5	Type_Arg5;
	typedef _Arg6	Type_Arg6;
	typedef _Arg7	Type_Arg7;
	typedef _Arg8	Type_Arg8;
	typedef _Arg9	Type_Arg9;
	typedef _Arg10	Type_Arg10;
	typedef _Arg11	Type_Arg11;
	typedef _Arg12	Type_Arg12;
	typedef _Arg13	Type_Arg13;

	static const int Args = 13;

	typedef _Result(_stdcall *_stdcall_Ptr)(Type_Arg1
		, Type_Arg2
		, Type_Arg3
		, Type_Arg4
		, Type_Arg5
		, Type_Arg6
		, Type_Arg7
		, Type_Arg8
		, Type_Arg9
		, Type_Arg10
		, Type_Arg11
		, Type_Arg12
		, Type_Arg13);

	typedef _Result(__cdecl *__cdecl_Ptr)(Type_Arg1
		, Type_Arg2
		, Type_Arg3
		, Type_Arg4
		, Type_Arg5
		, Type_Arg6
		, Type_Arg7
		, Type_Arg8
		, Type_Arg9
		, Type_Arg10
		, Type_Arg11
		, Type_Arg12
		, Type_Arg13);
};

template
	< typename _Result
	, typename _Arg1
	, typename _Arg2
	, typename _Arg3
	, typename _Arg4
	, typename _Arg5
	, typename _Arg6
	, typename _Arg7
	, typename _Arg8
	, typename _Arg9
	, typename _Arg10
	, typename _Arg11
	, typename _Arg12
	, typename _Arg13 >
struct _Get_TypeGroup<_Result(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13)>
{
	typedef BaseTypeGroup_13 < _Result
	, _Arg1
	, _Arg2
	, _Arg3
	, _Arg4
	, _Arg5
	, _Arg6
	, _Arg7
	, _Arg8
	, _Arg9
	, _Arg10
	, _Arg11
	, _Arg12
	, _Arg13 > _Type;
};

/**
 * 12个参数的模板
 */
template
	< typename _Result
	, typename _Arg1
	, typename _Arg2
	, typename _Arg3
	, typename _Arg4
	, typename _Arg5
	, typename _Arg6
	, typename _Arg7
	, typename _Arg8
	, typename _Arg9
	, typename _Arg10
	, typename _Arg11
	, typename _Arg12 >
struct BaseTypeGroup_12
{
	typedef _Result	Type_Result;

	typedef _Arg1	Type_Arg1;
	typedef _Arg2	Type_Arg2;
	typedef _Arg3	Type_Arg3;
	typedef _Arg4	Type_Arg4;
	typedef _Arg5	Type_Arg5;
	typedef _Arg6	Type_Arg6;
	typedef _Arg7	Type_Arg7;
	typedef _Arg8	Type_Arg8;
	typedef _Arg9	Type_Arg9;
	typedef _Arg10	Type_Arg10;
	typedef _Arg11	Type_Arg11;
	typedef _Arg12	Type_Arg12;
	typedef _Null	Type_Arg13;

	static const int Args = 12;

	typedef _Result(_stdcall *_stdcall_Ptr)(Type_Arg1
		, Type_Arg2
		, Type_Arg3
		, Type_Arg4
		, Type_Arg5
		, Type_Arg6
		, Type_Arg7
		, Type_Arg8
		, Type_Arg9
		, Type_Arg10
		, Type_Arg11
		, Type_Arg12);

	typedef _Result(__cdecl *__cdecl_Ptr)(Type_Arg1
		, Type_Arg2
		, Type_Arg3
		, Type_Arg4
		, Type_Arg5
		, Type_Arg6
		, Type_Arg7
		, Type_Arg8
		, Type_Arg9
		, Type_Arg10
		, Type_Arg11
		, Type_Arg12);
};

template
	< typename _Result
	, typename _Arg1
	, typename _Arg2
	, typename _Arg3
	, typename _Arg4
	, typename _Arg5
	, typename _Arg6
	, typename _Arg7
	, typename _Arg8
	, typename _Arg9
	, typename _Arg10
	, typename _Arg11
	, typename _Arg12 >
struct _Get_TypeGroup<_Result(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12)>
{
	typedef BaseTypeGroup_12 < _Result
	, _Arg1
	, _Arg2
	, _Arg3
	, _Arg4
	, _Arg5
	, _Arg6
	, _Arg7
	, _Arg8
	, _Arg9
	, _Arg10
	, _Arg11
	, _Arg12 > _Type;
};

/**
 * 11个参数的模板
 */
template
	< typename _Result
	, typename _Arg1
	, typename _Arg2
	, typename _Arg3
	, typename _Arg4
	, typename _Arg5
	, typename _Arg6
	, typename _Arg7
	, typename _Arg8
	, typename _Arg9
	, typename _Arg10
	, typename _Arg11 >
struct BaseTypeGroup_11
{
	typedef _Result	Type_Result;
		
	typedef _Arg1	Type_Arg1;
	typedef _Arg2	Type_Arg2;
	typedef _Arg3	Type_Arg3;
	typedef _Arg4	Type_Arg4;
	typedef _Arg5	Type_Arg5;
	typedef _Arg6	Type_Arg6;
	typedef _Arg7	Type_Arg7;
	typedef _Arg8	Type_Arg8;
	typedef _Arg9	Type_Arg9;
	typedef _Arg10	Type_Arg10;
	typedef _Arg11	Type_Arg11;
	typedef _Null	Type_Arg12;
	typedef _Null	Type_Arg13;

	static const int Args = 11;

	typedef _Result(_stdcall *_stdcall_Ptr)(Type_Arg1
		, Type_Arg2
		, Type_Arg3
		, Type_Arg4
		, Type_Arg5
		, Type_Arg6
		, Type_Arg7
		, Type_Arg8
		, Type_Arg9
		, Type_Arg10
		, Type_Arg11);

	typedef _Result(__cdecl *__cdecl_Ptr)(Type_Arg1
		, Type_Arg2
		, Type_Arg3
		, Type_Arg4
		, Type_Arg5
		, Type_Arg6
		, Type_Arg7
		, Type_Arg8
		, Type_Arg9
		, Type_Arg10
		, Type_Arg11);
};

template
	< typename _Result
	, typename _Arg1
	, typename _Arg2
	, typename _Arg3
	, typename _Arg4
	, typename _Arg5
	, typename _Arg6
	, typename _Arg7
	, typename _Arg8
	, typename _Arg9
	, typename _Arg10
	, typename _Arg11 >
struct _Get_TypeGroup<_Result(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11)>
{
	typedef BaseTypeGroup_11 < _Result
	, _Arg1
	, _Arg2
	, _Arg3
	, _Arg4
	, _Arg5
	, _Arg6
	, _Arg7
	, _Arg8
	, _Arg9
	, _Arg10
	, _Arg11 > _Type;
};

/**
 * 10个参数的模板
 */
template
	< typename _Result
	, typename _Arg1
	, typename _Arg2
	, typename _Arg3
	, typename _Arg4
	, typename _Arg5
	, typename _Arg6
	, typename _Arg7
	, typename _Arg8
	, typename _Arg9
	, typename _Arg10 >
struct BaseTypeGroup_10
{
	typedef _Result	Type_Result;
		
	typedef _Arg1	Type_Arg1;
	typedef _Arg2	Type_Arg2;
	typedef _Arg3	Type_Arg3;
	typedef _Arg4	Type_Arg4;
	typedef _Arg5	Type_Arg5;
	typedef _Arg6	Type_Arg6;
	typedef _Arg7	Type_Arg7;
	typedef _Arg8	Type_Arg8;
	typedef _Arg9	Type_Arg9;
	typedef _Arg10	Type_Arg10;
	typedef _Null	Type_Arg11;
	typedef _Null	Type_Arg12;
	typedef _Null	Type_Arg13;

	static const int Args = 10;

	typedef _Result(_stdcall *_stdcall_Ptr)(Type_Arg1
		, Type_Arg2
		, Type_Arg3
		, Type_Arg4
		, Type_Arg5
		, Type_Arg6
		, Type_Arg7
		, Type_Arg8
		, Type_Arg9
		, Type_Arg10);

	typedef _Result(__cdecl *__cdecl_Ptr)(Type_Arg1
		, Type_Arg2
		, Type_Arg3
		, Type_Arg4
		, Type_Arg5
		, Type_Arg6
		, Type_Arg7
		, Type_Arg8
		, Type_Arg9
		, Type_Arg10);
};

template
	< typename _Result
	, typename _Arg1
	, typename _Arg2
	, typename _Arg3
	, typename _Arg4
	, typename _Arg5
	, typename _Arg6
	, typename _Arg7
	, typename _Arg8
	, typename _Arg9
	, typename _Arg10 >
struct _Get_TypeGroup<_Result(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10)>
{
	typedef BaseTypeGroup_10<_Result
	, _Arg1
	, _Arg2
	, _Arg3
	, _Arg4
	, _Arg5
	, _Arg6
	, _Arg7
	, _Arg8
	, _Arg9
	, _Arg10> _Type;
};

/**
 * 9个参数的模板
 */
template
	< typename _Result
	, typename _Arg1
	, typename _Arg2
	, typename _Arg3
	, typename _Arg4
	, typename _Arg5
	, typename _Arg6
	, typename _Arg7
	, typename _Arg8
	, typename _Arg9 >
struct BaseTypeGroup_9
{
	typedef _Result	Type_Result;
		
	typedef _Arg1	Type_Arg1;
	typedef _Arg2	Type_Arg2;
	typedef _Arg3	Type_Arg3;
	typedef _Arg4	Type_Arg4;
	typedef _Arg5	Type_Arg5;
	typedef _Arg6	Type_Arg6;
	typedef _Arg7	Type_Arg7;
	typedef _Arg8	Type_Arg8;
	typedef _Arg9	Type_Arg9;
	typedef _Null	Type_Arg10;
	typedef _Null	Type_Arg11;
	typedef _Null	Type_Arg12;
	typedef _Null	Type_Arg13;

	static const int Args = 9;

	typedef _Result(_stdcall *_stdcall_Ptr)(Type_Arg1
		, Type_Arg2
		, Type_Arg3
		, Type_Arg4
		, Type_Arg5
		, Type_Arg6
		, Type_Arg7
		, Type_Arg8
		, Type_Arg9);

	typedef _Result(__cdecl *__cdecl_Ptr)(Type_Arg1
		, Type_Arg2
		, Type_Arg3
		, Type_Arg4
		, Type_Arg5
		, Type_Arg6
		, Type_Arg7
		, Type_Arg8
		, Type_Arg9);
};

template
	< typename _Result
	, typename _Arg1
	, typename _Arg2
	, typename _Arg3
	, typename _Arg4
	, typename _Arg5
	, typename _Arg6
	, typename _Arg7
	, typename _Arg8
	, typename _Arg9 >
struct _Get_TypeGroup<_Result(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9)>
{
	typedef BaseTypeGroup_9<_Result
	, _Arg1
	, _Arg2
	, _Arg3
	, _Arg4
	, _Arg5
	, _Arg6
	, _Arg7
	, _Arg8
	, _Arg9> _Type;
};

/**
 * 8个参数的模板
 */
template
	< typename _Result
	, typename _Arg1
	, typename _Arg2
	, typename _Arg3
	, typename _Arg4
	, typename _Arg5
	, typename _Arg6
	, typename _Arg7
	, typename _Arg8 >
struct BaseTypeGroup_8
{
	typedef _Result	Type_Result;
		
	typedef _Arg1	Type_Arg1;
	typedef _Arg2	Type_Arg2;
	typedef _Arg3	Type_Arg3;
	typedef _Arg4	Type_Arg4;
	typedef _Arg5	Type_Arg5;
	typedef _Arg6	Type_Arg6;
	typedef _Arg7	Type_Arg7;
	typedef _Arg8	Type_Arg8;
	typedef _Null	Type_Arg9;
	typedef _Null	Type_Arg10;
	typedef _Null	Type_Arg11;
	typedef _Null	Type_Arg12;
	typedef _Null	Type_Arg13;

	static const int Args = 8;

	typedef _Result(_stdcall *_stdcall_Ptr)(Type_Arg1
		, Type_Arg2
		, Type_Arg3
		, Type_Arg4
		, Type_Arg5
		, Type_Arg6
		, Type_Arg7
		, Type_Arg8);

	typedef _Result(__cdecl *__cdecl_Ptr)(Type_Arg1
		, Type_Arg2
		, Type_Arg3
		, Type_Arg4
		, Type_Arg5
		, Type_Arg6
		, Type_Arg7
		, Type_Arg8);
};

template
	< typename _Result
	, typename _Arg1
	, typename _Arg2
	, typename _Arg3
	, typename _Arg4
	, typename _Arg5
	, typename _Arg6
	, typename _Arg7
	, typename _Arg8 >
struct _Get_TypeGroup<_Result(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8)>
{
	typedef BaseTypeGroup_8<_Result
	, _Arg1
	, _Arg2
	, _Arg3
	, _Arg4
	, _Arg5
	, _Arg6
	, _Arg7
	, _Arg8> _Type;
};

/**
 * 7个参数的模板
 */
template
	< typename _Result
	, typename _Arg1
	, typename _Arg2
	, typename _Arg3
	, typename _Arg4
	, typename _Arg5
	, typename _Arg6
	, typename _Arg7 >
struct BaseTypeGroup_7
{
	typedef _Result	Type_Result;
		
	typedef _Arg1	Type_Arg1;
	typedef _Arg2	Type_Arg2;
	typedef _Arg3	Type_Arg3;
	typedef _Arg4	Type_Arg4;
	typedef _Arg5	Type_Arg5;
	typedef _Arg6	Type_Arg6;
	typedef _Arg7	Type_Arg7;
	typedef _Null	Type_Arg8;
	typedef _Null	Type_Arg9;
	typedef _Null	Type_Arg10;
	typedef _Null	Type_Arg11;
	typedef _Null	Type_Arg12;
	typedef _Null	Type_Arg13;

	static const int Args = 7;

	typedef _Result(_stdcall *_stdcall_Ptr)(Type_Arg1
		, Type_Arg2
		, Type_Arg3
		, Type_Arg4
		, Type_Arg5
		, Type_Arg6
		, Type_Arg7);

	typedef _Result(__cdecl *__cdecl_Ptr)(Type_Arg1
		, Type_Arg2
		, Type_Arg3
		, Type_Arg4
		, Type_Arg5
		, Type_Arg6
		, Type_Arg7);
};

template
	< typename _Result
	, typename _Arg1
	, typename _Arg2
	, typename _Arg3
	, typename _Arg4
	, typename _Arg5
	, typename _Arg6
	, typename _Arg7 >
struct _Get_TypeGroup<_Result(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7)>
{
	typedef BaseTypeGroup_7<_Result
	, _Arg1
	, _Arg2
	, _Arg3
	, _Arg4
	, _Arg5
	, _Arg6
	, _Arg7> _Type;
};

/**
 * 6个参数的模板
 */
template
	< typename _Result
	, typename _Arg1
	, typename _Arg2
	, typename _Arg3
	, typename _Arg4
	, typename _Arg5
	, typename _Arg6 >
struct BaseTypeGroup_6
{
	typedef _Result	Type_Result;
		
	typedef _Arg1	Type_Arg1;
	typedef _Arg2	Type_Arg2;
	typedef _Arg3	Type_Arg3;
	typedef _Arg4	Type_Arg4;
	typedef _Arg5	Type_Arg5;
	typedef _Arg6	Type_Arg6;
	typedef _Null	Type_Arg7;
	typedef _Null	Type_Arg8;
	typedef _Null	Type_Arg9;
	typedef _Null	Type_Arg10;
	typedef _Null	Type_Arg11;
	typedef _Null	Type_Arg12;
	typedef _Null	Type_Arg13;

	static const int Args = 6;

	typedef _Result(_stdcall *_stdcall_Ptr)(Type_Arg1
		, Type_Arg2
		, Type_Arg3
		, Type_Arg4
		, Type_Arg5
		, Type_Arg6);

	typedef _Result(__cdecl *__cdecl_Ptr)(Type_Arg1
		, Type_Arg2
		, Type_Arg3
		, Type_Arg4
		, Type_Arg5
		, Type_Arg6);
};

template
	< typename _Result
	, typename _Arg1
	, typename _Arg2
	, typename _Arg3
	, typename _Arg4
	, typename _Arg5
	, typename _Arg6 >
struct _Get_TypeGroup<_Result(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6)>
{
	typedef BaseTypeGroup_6<_Result
	, _Arg1
	, _Arg2
	, _Arg3
	, _Arg4
	, _Arg5
	, _Arg6> _Type;
};

/**
 * 5个参数的模板
 */
template
	< typename _Result
	, typename _Arg1
	, typename _Arg2
	, typename _Arg3
	, typename _Arg4
	, typename _Arg5 >
struct BaseTypeGroup_5
{
	typedef _Result	Type_Result;
		
	typedef _Arg1	Type_Arg1;
	typedef _Arg2	Type_Arg2;
	typedef _Arg3	Type_Arg3;
	typedef _Arg4	Type_Arg4;
	typedef _Arg5	Type_Arg5;
	typedef _Null	Type_Arg6;
	typedef _Null	Type_Arg7;
	typedef _Null	Type_Arg8;
	typedef _Null	Type_Arg9;
	typedef _Null	Type_Arg10;
	typedef _Null	Type_Arg11;
	typedef _Null	Type_Arg12;
	typedef _Null	Type_Arg13;

	static const int Args = 5;

	typedef _Result(_stdcall *_stdcall_Ptr)(Type_Arg1
		, Type_Arg2
		, Type_Arg3
		, Type_Arg4
		, Type_Arg5);

	typedef _Result(__cdecl *__cdecl_Ptr)(Type_Arg1
		, Type_Arg2
		, Type_Arg3
		, Type_Arg4
		, Type_Arg5);
};

template
	< typename _Result
	, typename _Arg1
	, typename _Arg2
	, typename _Arg3
	, typename _Arg4
	, typename _Arg5 >
struct _Get_TypeGroup<_Result(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5)>
{
	typedef BaseTypeGroup_5<_Result
	, _Arg1
	, _Arg2
	, _Arg3
	, _Arg4
	, _Arg5> _Type;
};

/**
 * 4个参数的模板
 */
template
	< typename _Result
	, typename _Arg1
	, typename _Arg2
	, typename _Arg3
	, typename _Arg4 >
struct BaseTypeGroup_4
{
	typedef _Result	Type_Result;
		
	typedef _Arg1	Type_Arg1;
	typedef _Arg2	Type_Arg2;
	typedef _Arg3	Type_Arg3;
	typedef _Arg4	Type_Arg4;
	typedef _Null	Type_Arg5;
	typedef _Null	Type_Arg6;
	typedef _Null	Type_Arg7;
	typedef _Null	Type_Arg8;
	typedef _Null	Type_Arg9;
	typedef _Null	Type_Arg10;
	typedef _Null	Type_Arg11;
	typedef _Null	Type_Arg12;
	typedef _Null	Type_Arg13;

	static const int Args = 4;

	typedef _Result(_stdcall *_stdcall_Ptr)(Type_Arg1
		, Type_Arg2
		, Type_Arg3
		, Type_Arg4);

	typedef _Result(__cdecl *__cdecl_Ptr)(Type_Arg1
		, Type_Arg2
		, Type_Arg3
		, Type_Arg4);
};

template
	< typename _Result
	, typename _Arg1
	, typename _Arg2
	, typename _Arg3
	, typename _Arg4 >
struct _Get_TypeGroup<_Result(_Arg1, _Arg2, _Arg3, _Arg4)>
{
	typedef BaseTypeGroup_4<_Result
	, _Arg1
	, _Arg2
	, _Arg3
	, _Arg4> _Type;
};

/**
 * 3个参数的模板
 */
template
	< typename _Result
	, typename _Arg1
	, typename _Arg2
	, typename _Arg3 >
struct BaseTypeGroup_3
{
	typedef _Result	Type_Result;

	typedef _Arg1	Type_Arg1;
	typedef _Arg2	Type_Arg2;
	typedef _Arg3	Type_Arg3;
	typedef _Null	Type_Arg4;
	typedef _Null	Type_Arg5;
	typedef _Null	Type_Arg6;
	typedef _Null	Type_Arg7;
	typedef _Null	Type_Arg8;
	typedef _Null	Type_Arg9;
	typedef _Null	Type_Arg10;
	typedef _Null	Type_Arg11;
	typedef _Null	Type_Arg12;
	typedef _Null	Type_Arg13;

	static const int Args = 3;

	typedef _Result(_stdcall *_stdcall_Ptr)(Type_Arg1
		, Type_Arg2
		, Type_Arg3);

	typedef _Result(__cdecl *__cdecl_Ptr)(Type_Arg1
		, Type_Arg2
		, Type_Arg3);
};

template
	< typename _Result
	, typename _Arg1
	, typename _Arg2
	, typename _Arg3 >
struct _Get_TypeGroup<_Result(_Arg1, _Arg2, _Arg3)>
{
	typedef BaseTypeGroup_3<_Result
	, _Arg1
	, _Arg2
	, _Arg3> _Type;
};

/**
 * 2个参数的模板
 */
template
	< typename _Result
	, typename _Arg1
	, typename _Arg2>
struct BaseTypeGroup_2
{
	typedef _Result	Type_Result;
		
	typedef _Arg1	Type_Arg1;
	typedef _Arg2	Type_Arg2;
	typedef _Null	Type_Arg3;
	typedef _Null	Type_Arg4;
	typedef _Null	Type_Arg5;
	typedef _Null	Type_Arg6;
	typedef _Null	Type_Arg7;
	typedef _Null	Type_Arg8;
	typedef _Null	Type_Arg9;
	typedef _Null	Type_Arg10;
	typedef _Null	Type_Arg11;
	typedef _Null	Type_Arg12;
	typedef _Null	Type_Arg13;

	static const int Args = 2;

	typedef _Result(_stdcall *_stdcall_Ptr)(Type_Arg1
		, Type_Arg2);

	typedef _Result(__cdecl *__cdecl_Ptr)(Type_Arg1
		, Type_Arg2);
};

template
	< typename _Result
	, typename _Arg1
	, typename _Arg2>
struct _Get_TypeGroup<_Result(_Arg1, _Arg2)>
{
	typedef BaseTypeGroup_2<_Result
	, _Arg1
	, _Arg2> _Type;
};

/**
 * 1个参数的模板
 */
template
	< typename _Result
	, typename _Arg1 >
struct BaseTypeGroup_1
{
	typedef _Result	Type_Result;
		
	typedef _Arg1	Type_Arg1;
	typedef _Null	Type_Arg2;
	typedef _Null	Type_Arg3;
	typedef _Null	Type_Arg4;
	typedef _Null	Type_Arg5;
	typedef _Null	Type_Arg6;
	typedef _Null	Type_Arg7;
	typedef _Null	Type_Arg8;
	typedef _Null	Type_Arg9;
	typedef _Null	Type_Arg10;
	typedef _Null	Type_Arg11;
	typedef _Null	Type_Arg12;
	typedef _Null	Type_Arg13;

	static const int Args = 1;

	typedef _Result(_stdcall *_stdcall_Ptr)(Type_Arg1);

	typedef _Result(__cdecl *__cdecl_Ptr)(Type_Arg1);
};

template
	< typename _Result
	, typename _Arg1 >
struct _Get_TypeGroup<_Result(_Arg1)>
{
	typedef BaseTypeGroup_1<_Result
	, _Arg1> _Type;
};

/**
 * 无参数的模板
 */
template<typename _Result>
struct BaseTypeGroup_0
{
	typedef _Result	Type_Result;

	typedef _Null	Type_Arg1;
	typedef _Null	Type_Arg2;
	typedef _Null	Type_Arg3;
	typedef _Null	Type_Arg4;
	typedef _Null	Type_Arg5;
	typedef _Null	Type_Arg6;
	typedef _Null	Type_Arg7;
	typedef _Null	Type_Arg8;
	typedef _Null	Type_Arg9;
	typedef _Null	Type_Arg10;
	typedef _Null	Type_Arg11;
	typedef _Null	Type_Arg12;
	typedef _Null	Type_Arg13;

	static const int Args = 0;

	typedef _Result(_stdcall *_stdcall_Ptr)();

	typedef _Result(__cdecl *__cdecl_Ptr)();
};

template<typename _Result>
struct _Get_TypeGroup<_Result()>
{
	typedef BaseTypeGroup_0<_Result> _Type;
};

/**
 * 分型模板，根据函数指针分辨详细类型
 */
template<class _Fty>
struct TypeGroup : public _Get_TypeGroup<_Fty>::_Type
{};

/**
 * 判断左右类型是否相同
 */
template<typename _Left, typename _Right>
struct TypeIsSame
{
	static const bool Value = false;
};

/**
 * 左右类型相同的特化模板
 */
template<typename _Left>
struct TypeIsSame<_Left, _Left>
{
	static const bool Value = true;
};

/**
 * 默认值
 */
template<typename _Type>
struct Default
{
	_Type operator()() { return _Type(); }
};

/**
 * 默认值，指针特化模板
 */
template<typename _Type>
struct Default<_Type*>
{
	_Type* operator()() { return nullptr; }
};

/**
 * 默认值，指针特化模板
 */
template<typename _Type>
struct Default<const _Type*>
{
	const _Type* operator()() { return nullptr; }
};

#endif /* Type_Group_H */