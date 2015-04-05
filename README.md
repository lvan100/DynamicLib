# DynamicLib
DynamicLib，极简的方式从dll或者so或者dylib文件获取导出（C）函数。下面展示的是一个简单的例子。

## 最多支持9个参数

    #include "ShareStore.h"
    class A : public BaseDllWrapper<A> {
    	DEFINE_CDECL_FUNCTION(Func0, void());
    	DEFINE_CDECL_FUNCTION(Func1, void(int));
    	DEFINE_CDECL_FUNCTION(Func2, void(int, int));
    	DEFINE_CDECL_FUNCTION(Func3, void(int, int, int));
    	DEFINE_CDECL_FUNCTION(Func4, void(int, int, int, int));
    	DEFINE_CDECL_FUNCTION(Func5, void(int, int, int, int, int));
    	DEFINE_CDECL_FUNCTION(Func6, void(int, int, int, int, int, int));
    	DEFINE_CDECL_FUNCTION(Func7, void(int, int, int, int, int, int, int));
    	DEFINE_CDECL_FUNCTION(Func8, void(int, int, int, int, int, int, int, int));
    	DEFINE_CDECL_FUNCTION(Func9, void(int, int, int, int, int, int, int, int, int));
    };

## 动态存储的方式导出User32.dll中的函数

    #include "ShareStore.h"
    class ShareUser32 : public BaseDllWrapper<ShareUser32> {
    	DEFINE_STDCALL_FUNCTION(GetClientRect, BOOL(HWND, LPRECT));
    	DEFINE_STDCALL_FUNCTION(GetDesktopWindow, HWND());
    	
    	// 动态存储使用懒加载模式
    	DEFINE_DEFAULT_FILE("User32.dll");
    };

## 静态存储方式导出User32.dll中的函数

    #include "StaticStore.h"
    class StaticUser32 : public BaseDllWrapper<StaticUser32> {
    	DEFINE_STDCALL_FUNCTION(GetClientRect, BOOL(HWND, LPRECT));
    	DEFINE_STDCALL_FUNCTION(GetDesktopWindow, HWND());
    	
    	// 静态存储使用懒加载模式
    	DEFINE_DEFAULT_FILE("User32.dll");
    };

## 使用动态存储方式可以很方便的在相同接口不同实现的dll文件间自由切换

    #include "ShareStore.h"
    class DllTest : public BaseDllWrapper<DllTest> {
    	DEFINE_CDECL_FUNCTION(fnDllTest, int());
    };

## 调用示例

    int main(int argc, char* argv[])
    {
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
         	OnePath.append("/DllTestOne.so");
        	DllTestInst.Load(OnePath.c_str());
    	#endif
        assert(1 == DllTestInst.fnDllTest());
    	DllTestInst.Free();
    	
    	// 动态存储切换加载资源
    	#ifdef WIN32
    	    DllTestInst.Load("DllTestTwo.dll");
    	#else
    		StdString TwoPath(buffer);
    		TwoPath.append("/DllTestTwo.so");
    		DllTestInst.Load(TwoPath.c_str());
    	#endif
    	assert(2 == DllTestInst.fnDllTest());
    	DllTestInst.Free();
    		
        return 0;
    }
    														
