#include "DllFunc.h"

#ifdef WIN32

struct ShareUser32 {
	ShareUser32();
	DllFunc<HWND()> GetDesktopWindow;
	DllFunc<BOOL(HWND, LPRECT)> GetClientRect;
};

ShareUser32::ShareUser32()
	: GetClientRect("User32.dll", "GetClientRect", DllFuncType::DTF_STDCALL)
	, GetDesktopWindow("User32.dll", "GetDesktopWindow", DllFuncType::DTF_STDCALL)
{}

struct StaticUser32 {
	static DllFunc<HWND()> GetDesktopWindow;
	static DllFunc<BOOL(HWND, LPRECT)> GetClientRect;
};

DllFunc<HWND()> StaticUser32::GetDesktopWindow("User32.dll", "GetDesktopWindow", DllFuncType::DTF_STDCALL);
DllFunc<BOOL(HWND, LPRECT)> StaticUser32::GetClientRect("User32.dll", "GetClientRect", DllFuncType::DTF_STDCALL);

#endif /* WIN32 */


struct DllTest {
	DllFunc<int()> fnDllTest;
	DllTest() : fnDllTest("fnDllTest") {}
};


#ifdef WIN32
#include <direct.h>
#else
#include <unistd.h>
#endif /* WIN32 */

#include <string>


int main(int argc, char* argv[]) {

#ifdef WIN32

	RECT rcWnd;

	// 动态存储懒加载
	ShareUser32 mUser32;
	HWND hWnd = mUser32.GetDesktopWindow();
	mUser32.GetClientRect(hWnd, &rcWnd);

	// 静态存储懒加载
	hWnd = StaticUser32::GetDesktopWindow();
	StaticUser32::GetClientRect(hWnd, &rcWnd);

#endif

	char buffer[256];
	_getcwd(buffer, sizeof(buffer));

	//////////////////////////////////////////////////////////////////////////

	DllTest DllTestInst;

	// 动态存储切换加载资源
#ifdef WIN32
	DllTestInst.fnDllTest.Load("DllTestOne.dll");
#else
	std::string OnePath(buffer);
#ifdef __APPLE__
	OnePath.append("/DllTestOne.dylib");
#else
	OnePath.append("/DllTestOne.so");
#endif
	DllTestInst.fnDllTest.Load(OnePath.c_str());
#endif

	DllTestInst.fnDllTest();
	DllTestInst.fnDllTest.Free();

	// 动态存储切换加载资源
#ifdef WIN32
	DllTestInst.fnDllTest.Load("DllTestTwo.dll");
#else
	std::string TwoPath(buffer);
#ifdef __APPLE__
	TwoPath.append("/DllTestTwo.dylib");
#else
	TwoPath.append("/DllTestTwo.so");
#endif
	DllTestInst.fnDllTest.Load(TwoPath.c_str());
#endif
	DllTestInst.fnDllTest();
	DllTestInst.fnDllTest.Free();

	return 0;
}