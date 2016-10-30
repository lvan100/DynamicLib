/*
 * 作者：梁欢（lvan100@yeah.net）
 * 博客：http://blog.163.com/lvan100@yeah/
 * 授权：您可以使用这份文档进行任何用途，但原作者不承担任何责任。
 */


#ifndef STDCALL
#ifdef WIN32
#define STDCALL _stdcall
#else
#define STDCALL __attribute__((__stdcall__))
#endif /* WIN32 */
#endif /* STDCALL */


#ifndef CDECL
#ifdef WIN32
#define CDECL __cdecl
#else
#define CDECL __attribute__((__cdecl__))
#endif /* WIN32 */
#endif /* CDECL */


#if _ArgNum_Max_ > 10
#	error bad number of arguments
#endif


 //////////////////////////////////////////////////////////////////////////
 // 0

 // ==> 
#define template_cTcT0

 // ==> class _TResult
#define template_cRcTcT0	template_cR

 // ==> 
#define template_T0			

 // ==> 
#define template_TT0		

 // ==> _TResult
#define template_RTT0		template_R

 // ==> 
#define template_a0			

 // ==> 
#define template_Ta0		template_T0 template_a0

 // ==> 
#define template_aa0		

 // ==> 
#define template_TaTa0		

 // ==> _TResult()
#define template_Func0		template_R(template_TT0)

 // ==> _TResult(__cdecl *_ptr)()
#define template_FuncPtrC0	typedef template_R(CDECL *_cdecl_ptr)(template_TT0);

 // ==> _TResult(_stdcall *_ptr)()
#define template_FuncPtrS0	typedef template_R(STDCALL *_stdcall_ptr)(template_TT0);


//////////////////////////////////////////////////////////////////////////
// 1

// ==> class _T0
#define template_cTcT1		template_cT(0)

// ==> class _TResult , class _T0
#define template_cRcTcT1	template_cR , template_cTcT1

// ==> _T0
#define template_T1			template_T(0)

// ==> _T0
#define template_TT1		template_T1

// ==> _TResult, _T0
#define template_RTT1		template_R , template_TT1

// ==> arg0
#define template_a1			template_a(0)

// ==> _T0 arg0
#define template_Ta1		template_T1 template_a1

// ==> arg0
#define template_aa1		template_a1

// ==> _T0 arg0
#define template_TaTa1		template_Ta1

// ==> _TResult(_T0)
#define template_Func1		template_R(template_TT1)

// ==> _TResult(__cdecl *_ptr)(_T0)
#define template_FuncPtrC1	typedef template_R(CDECL *_cdecl_ptr)(template_TT1);

// ==> _TResult(_stdcall *_ptr)(_T0)
#define template_FuncPtrS1	typedef template_R(STDCALL *_stdcall_ptr)(template_TT1);


//////////////////////////////////////////////////////////////////////////
// 2

// ==> class _T0 , class _T1
#define template_cTcT2		template_cTcT1 , template_cT(1)

// ==> class _TResult , class _T0 , class _T1
#define template_cRcTcT2	template_cR , template_cTcT2

// ==> _T1
#define template_T2			template_T(1)

// ==> _T0 , _T1
#define template_TT2		template_TT1 , template_T2

// ==> _TResult, _T0 , _T1
#define template_RTT2		template_R , template_TT2

// ==> arg1
#define template_a2			template_a(1)

// ==> _T1 arg1
#define template_Ta2		template_T2 template_a2

// ==> arg0 , arg1
#define template_aa2		template_aa1 , template_a2

// ==> _T0 arg0 , _T1 arg1
#define template_TaTa2		template_TaTa1 , template_Ta2

// ==> _TResult(_T0, _T1)
#define template_Func2		template_R(template_TT2)

// ==> _TResult(__cdecl *_ptr)(_T0, _T1)
#define template_FuncPtrC2	typedef template_R(CDECL *_cdecl_ptr)(template_TT2);

// ==> _TResult(_stdcall *_ptr)(_T0, _T1)
#define template_FuncPtrS2	typedef template_R(STDCALL *_stdcall_ptr)(template_TT2);


//////////////////////////////////////////////////////////////////////////
// 3

// ==> class _T0 , class _T1 , class _T2
#define template_cTcT3		template_cTcT2 , template_cT(2)

// ==> class _TResult , class _T0 , class _T1 , class _T2
#define template_cRcTcT3	template_cR , template_cTcT3

// ==> _T2
#define template_T3			template_T(2)

// ==> _T0 , _T1 , _T2
#define template_TT3		template_TT2 , template_T3

// ==> _TResult, _T0 , _T1 , _T2
#define template_RTT3		template_R , template_TT3

// ==> arg2
#define template_a3			template_a(2)

// ==> _T2 arg2
#define template_Ta3		template_T3 template_a3

// ==> arg0 , arg1 , arg2
#define template_aa3		template_aa2 , template_a3

// ==> _T0 arg0 , _T1 arg1 , _T2 arg2
#define template_TaTa3		template_TaTa2 , template_Ta3

// ==> _TResult(_T0, _T1, _T2)
#define template_Func3		template_R(template_TT3)

// ==> _TResult(__cdecl *_ptr)(_T0, _T1, _T2)
#define template_FuncPtrC3	typedef template_R(CDECL *_cdecl_ptr)(template_TT3);

// ==> _TResult(_stdcall *_ptr)(_T0, _T1, _T2)
#define template_FuncPtrS3	typedef template_R(STDCALL *_stdcall_ptr)(template_TT3);


//////////////////////////////////////////////////////////////////////////
// 4

// ==> class _T0 , class _T1 , class _T2 , class _T3
#define template_cTcT4		template_cTcT3 , template_cT(3)

// ==> class _TResult , class _T0 , ... , class _T3
#define template_cRcTcT4	template_cR , template_cTcT4

// ==> _T3
#define template_T4			template_T(3)

// ==> _T0 , _T1 , _T2 , _T3
#define template_TT4		template_TT3 , template_T4

// ==> _TResult, _T0 , ... , _T3
#define template_RTT4		template_R , template_TT4

// ==> arg3
#define template_a4			template_a(3)

// ==> _T3 arg3
#define template_Ta4		template_T4 template_a4

// ==> arg0 , arg1 , arg2 , arg3
#define template_aa4		template_aa3 , template_a4

// ==> _T0 arg0 , _T1 arg1 , ... , _T3 arg3
#define template_TaTa4		template_TaTa3 , template_Ta4

// ==> _TResult(_T0, _T1, _T2, _T3)
#define template_Func4		template_R(template_TT4)

// ==> _TResult(__cdecl *_ptr)(_T0, _T1, _T2, _T3)
#define template_FuncPtrC4	typedef template_R(CDECL *_cdecl_ptr)(template_TT4);

// ==> _TResult(_stdcall *_ptr)(_T0, _T1, _T2, _T3)
#define template_FuncPtrS4	typedef template_R(STDCALL *_stdcall_ptr)(template_TT4);


//////////////////////////////////////////////////////////////////////////
// 5

// ==> class _T0 , class _T1 , ... , class _T4
#define template_cTcT5		template_cTcT4 , template_cT(4)

// ==> class _TResult , class _T0 , ... , class _T4
#define template_cRcTcT5	template_cR , template_cTcT5

// ==> _T4
#define template_T5			template_T(4)

// ==> _T0 , ... , _T4
#define template_TT5		template_TT4 , template_T5

// ==> _TResult, _T0 , ... , _T4
#define template_RTT5		template_R , template_TT5

// ==> arg4
#define template_a5			template_a(4)

// ==> _T4 arg4
#define template_Ta5		template_T5 template_a5

// ==> arg0 , ... , arg4
#define template_aa5		template_aa4 , template_a5

// ==> _T0 arg0 , ... , _T4 arg4
#define template_TaTa5		template_TaTa4 , template_Ta5

// ==> _TResult(_T0, ..., _T4)
#define template_Func5		template_R(template_TT5)

// ==> _TResult(*Ptr)(_T0, ..., _T4)
#define template_FuncPtr5	typedef template_R(*_ptr)(template_TT5);

// ==> _TResult(__cdecl *_ptr)(_T0, ..., _T4)
#define template_FuncPtrC5	typedef template_R(CDECL *_cdecl_ptr)(template_TT5);

// ==> _TResult(_stdcall *_ptr)(_T0, ..., _T4)
#define template_FuncPtrS5	typedef template_R(STDCALL *_stdcall_ptr)(template_TT5);


//////////////////////////////////////////////////////////////////////////
// 6

// ==> class _T0 , class _T1 , ... , class _T5
#define template_cTcT6		template_cTcT5 , template_cT(5)

// ==> class _TResult , class _T0 , ... , class _T5
#define template_cRcTcT6	template_cR , template_cTcT6

// ==> _T5
#define template_T6			template_T(5)

// ==> _T0 , ... , _T5
#define template_TT6		template_TT5 , template_T6

// ==> _TResult, _T0 , ... , _T5
#define template_RTT6		template_R , template_TT6

// ==> arg5
#define template_a6			template_a(5)

// ==> _T5 arg5
#define template_Ta6		template_T6 template_a6

// ==> arg0 , ... , arg5
#define template_aa6		template_aa5 , template_a6

// ==> _T0 arg0 , ... , _T5 arg5
#define template_TaTa6		template_TaTa5 , template_Ta6

// ==> _TResult(_T0, ..., _T5)
#define template_Func6		template_R(template_TT6)

// ==> _TResult(__cdecl *_ptr)(_T0, ..., _T5)
#define template_FuncPtrC6	typedef template_R(CDECL *_cdecl_ptr)(template_TT6);

// ==> _TResult(_stdcall *_ptr)(_T0, ..., _T5)
#define template_FuncPtrS6	typedef template_R(STDCALL *_stdcall_ptr)(template_TT6);


//////////////////////////////////////////////////////////////////////////
// 7

// ==> class _T0 , class _T1 , ... , class _T6
#define template_cTcT7		template_cTcT6 , template_cT(6)

// ==> class _TResult , class _T0 , ... , class _T6
#define template_cRcTcT7	template_cR , template_cTcT7

// ==> _T6
#define template_T7			template_T(6)

// ==> _T0 , ... , _T6
#define template_TT7		template_TT6 , template_T7

// ==> _TResult, _T0 , ... , _T6
#define template_RTT7		template_R , template_TT7

// ==> arg6
#define template_a7			template_a(6)

// ==> _T6 arg6
#define template_Ta7		template_T7 template_a7

// ==> arg0 , ... , arg6
#define template_aa7		template_aa6 , template_a7

// ==> _T0 arg0 , ... , _T6 arg6
#define template_TaTa7		template_TaTa6 , template_Ta7

// ==> _TResult(_T0, ..., _T6)
#define template_Func7		template_R(template_TT7)

// ==> _TResult(__cdecl *_ptr)(_T0, ..., _T6)
#define template_FuncPtrC7	typedef template_R(CDECL *_cdecl_ptr)(template_TT7);

// ==> _TResult(_stdcall *_ptr)(_T0, ..., _T6)
#define template_FuncPtrS7	typedef template_R(STDCALL *_stdcall_ptr)(template_TT7);


//////////////////////////////////////////////////////////////////////////
// 8

// ==> class _T0 , class _T1 , ... , class _T7
#define template_cTcT8		template_cTcT7 , template_cT(7)

// ==> class _TResult , class _T0 , ... , class _T7
#define template_cRcTcT8	template_cR , template_cTcT8

// ==> _T7
#define template_T8			template_T(7)

// ==> _T0 , ... , _T7
#define template_TT8		template_TT7 , template_T8

// ==> _TResult, _T0 , ... , _T7
#define template_RTT8		template_R , template_TT8

// ==> arg7
#define template_a8			template_a(7)

// ==> _T7 arg7
#define template_Ta8		template_T8 template_a8

// ==> arg0 , ... , arg7
#define template_aa8		template_aa7 , template_a8

// ==> _T0 arg0 , ... , _T7 arg7
#define template_TaTa8		template_TaTa7 , template_Ta8

// ==> _TResult(_T0, ..., _T7)
#define template_Func8		template_R(template_TT8)

// ==> _TResult(__cdecl *_ptr)(_T0, ..., _T7)
#define template_FuncPtrC8	typedef template_R(CDECL *_cdecl_ptr)(template_TT8);

// ==> _TResult(_stdcall *_ptr)(_T0, ..., _T7)
#define template_FuncPtrS8	typedef template_R(STDCALL *_stdcall_ptr)(template_TT8);


//////////////////////////////////////////////////////////////////////////
// 9

// ==> class _T0 , class _T1 , ... , class _T8
#define template_cTcT9		template_cTcT8 , template_cT(8)

// ==> class _TResult , class _T0 , ... , class _T8
#define template_cRcTcT9	template_cR , template_cTcT9

// ==> _T8
#define template_T9		template_T(8)

// ==> _T0 , ... , _T8
#define template_TT9		template_TT8 , template_T9

// ==> _TResult, _T0 , ... , _T8
#define template_RTT9		template_R , template_TT9

// ==> arg8
#define template_a9			template_a(8)

// ==> _T8 arg8
#define template_Ta9		template_T9 template_a9

// ==> arg0 , ... , arg8
#define template_aa9		template_aa8 , template_a9

// ==> _T0 arg0 , ... , _T8 arg8
#define template_TaTa9		template_TaTa8 , template_Ta9

// ==> _TResult(_T0, ..., _T8)
#define template_Func9		template_R(template_TT9)

// ==> _TResult(__cdecl *_ptr)(_T0, ..., _T8)
#define template_FuncPtrC9	typedef template_R(CDECL *_cdecl_ptr)(template_TT9);

// ==> _TResult(_stdcall *_ptr)(_T0, ..., _T8)
#define template_FuncPtrS9	typedef template_R(STDCALL *_stdcall_ptr)(template_TT9);


//////////////////////////////////////////////////////////////////////////
// 10

// ==> class _T0 , class _T1 , ... , class _T9
#define template_cTcT10		template_cTcT9 , template_cT(9)

// ==> class _TResult , class _T0 , ... , class _T9
#define template_cRcTcT10	template_cR , template_cTcT10

// ==> _T9
#define template_T10		template_T(9)

// ==> _T0 , ... , _T9
#define template_TT10		template_TT9 , template_T10

// ==> _TResult, _T0 , ... , _T9
#define template_RTT10		template_R , template_TT10

// ==> arg9
#define template_a10		template_a(9)

// ==> _T9 arg9
#define template_Ta10		template_T10 template_a10

// ==> arg0 , ... , arg9
#define template_aa10		template_aa9 , template_a10

// ==> _T0 arg0 , ... , _T9 arg9
#define template_TaTa10		template_TaTa9 , template_Ta10

// ==> _TResult(_T0, ..., _T9)
#define template_Func10		template_R(template_TT10)

// ==> _TResult(__cdecl *_ptr)(_T0, ..., _T9)
#define template_FuncPtrC10	typedef template_R(CDECL *_cdecl_ptr)(template_TT10);

// ==> _TResult(_stdcall *_ptr)(_T0, ..., _T9)
#define template_FuncPtrS10	typedef template_R(STDCALL *_stdcall_ptr)(template_TT10);