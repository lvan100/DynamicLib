#include "ShareStore.h"

class A: public BaseDllWrapper<A> {
	DEFINE_CDECL_FUNCTION(Func0, void())
	DEFINE_CDECL_FUNCTION(Func1, void(int))
	DEFINE_CDECL_FUNCTION(Func2, void(int, int))
	DEFINE_CDECL_FUNCTION(Func3, void(int, int, int))
	DEFINE_CDECL_FUNCTION(Func4, void(int, int, int, int))
	DEFINE_CDECL_FUNCTION(Func5, void(int, int, int, int, int))
	DEFINE_CDECL_FUNCTION(Func6, void(int, int, int, int, int, int))
	DEFINE_CDECL_FUNCTION(Func7, void(int, int, int, int, int, int, int))
	DEFINE_CDECL_FUNCTION(Func8, void(int, int, int, int, int, int, int, int))
	DEFINE_CDECL_FUNCTION(Func9, void(int, int, int, int, int, int, int, int, int))
};

#ifdef WIN32

#include "ShareStore.h"

class ShareUser32 : public BaseDllWrapper<ShareUser32> {
	DEFINE_STDCALL_FUNCTION(GetClientRect, BOOL(HWND, LPRECT));
	DEFINE_STDCALL_FUNCTION(GetDesktopWindow, HWND());

	// 动态存储使用懒加载模式
	DEFINE_DEFAULT_FILE("User32.dll");
};

#include "StaticStore.h"

class StaticUser32 : public BaseDllWrapper<StaticUser32> {
	DEFINE_STDCALL_FUNCTION(GetClientRect, BOOL(HWND, LPRECT));
	DEFINE_STDCALL_FUNCTION(GetDesktopWindow, HWND());

	// 静态存储使用懒加载模式
	DEFINE_DEFAULT_FILE("User32.dll");
};

#endif /* WIN32 */

#include "ShareStore.h"

class DllTest: public BaseDllWrapper<DllTest> {
	DEFINE_CDECL_FUNCTION(fnDllTest, int())
};

#ifdef WIN32
#include <direct.h>
#else
#include <unistd.h>
#endif /* WIN32 */

int main(int argc, char* argv[]) {

	A().Func0();

	A().Func1();
	A().Func1(1);

	A().Func2();
	A().Func2(1);
	A().Func2(1, 2);

	A().Func3();
	A().Func3(1);
	A().Func3(1, 2);
	A().Func3(1, 2, 3);

	A().Func4();
	A().Func4(1);
	A().Func4(1, 2);
	A().Func4(1, 2, 3);
	A().Func4(1, 2, 3, 4);

	A().Func5();
	A().Func5(1);
	A().Func5(1, 2);
	A().Func5(1, 2, 3);
	A().Func5(1, 2, 3, 4);
	A().Func5(1, 2, 3, 4, 5);

	A().Func6();
	A().Func6(1);
	A().Func6(1, 2);
	A().Func6(1, 2, 3);
	A().Func6(1, 2, 3, 4);
	A().Func6(1, 2, 3, 4, 5);
	A().Func6(1, 2, 3, 4, 5, 6);

	A().Func7();
	A().Func7(1);
	A().Func7(1, 2);
	A().Func7(1, 2, 3);
	A().Func7(1, 2, 3, 4);
	A().Func7(1, 2, 3, 4, 5);
	A().Func7(1, 2, 3, 4, 5, 6);
	A().Func7(1, 2, 3, 4, 5, 6, 7);

	A().Func8();
	A().Func8(1, 2);
	A().Func8(1, 2, 3);
	A().Func8(1, 2, 3, 4);
	A().Func8(1, 2, 3, 4, 5);
	A().Func8(1, 2, 3, 4, 5, 6);
	A().Func8(1, 2, 3, 4, 5, 6, 7);
	A().Func8(1, 2, 3, 4, 5, 6, 7, 8);

	A().Func9();
	A().Func9(1);
	A().Func9(1, 2);
	A().Func9(1, 2, 3);
	A().Func9(1, 2, 3, 4);
	A().Func9(1, 2, 3, 4, 5);
	A().Func9(1, 2, 3, 4, 5, 6);
	A().Func9(1, 2, 3, 4, 5, 6, 7);
	A().Func9(1, 2, 3, 4, 5, 6, 7, 8);
	A().Func9(1, 2, 3, 4, 5, 6, 7, 8, 9);

	//////////////////////////////////////////////////////////////////////////

#ifdef WIN32

	RECT rcWnd;

	// 动态存储懒加载
	ShareUser32 mUser32;
	HWND hWnd = mUser32.GetDesktopWindow();
	mUser32.GetClientRect(hWnd, &rcWnd);
	mUser32.Free();

	// 静态存储懒加载
	hWnd = StaticUser32::GetDesktopWindow();
	StaticUser32::GetClientRect(hWnd, &rcWnd);
	StaticUser32::Free();

#endif

	//////////////////////////////////////////////////////////////////////////

	char buffer[256];
	getcwd(buffer, sizeof(buffer));

	//////////////////////////////////////////////////////////////////////////

	DllTest DllTestInst;

	// 动态存储切换加载资源
#ifdef WIN32
	DllTestInst.Load("DllTestOne.dll");
#else
	StdString OnePath(buffer);
#ifdef __APPLE__
	OnePath.append("/DllTestOne.dylib");
#else
    	OnePath.append("/DllTestOne.so");
#endif
	DllTestInst.Load(OnePath.c_str());
#endif
	DllTestInst.fnDllTest();
	DllTestInst.Free();

	// 动态存储切换加载资源
#ifdef WIN32
	DllTestInst.Load("DllTestTwo.dll");
#else
	StdString TwoPath(buffer);
#ifdef __APPLE__
	TwoPath.append("/DllTestTwo.dylib");
#else
    	TwoPath.append("/DllTestTwo.so");
#endif
	DllTestInst.Load(TwoPath.c_str());
#endif
	DllTestInst.fnDllTest();
	DllTestInst.Free();

	return 0;
}
