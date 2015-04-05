#ifdef WIN32
#define DLL_API __declspec(dllexport)
#else
#define DLL_API
#endif

#include <stdio.h>

extern "C" DLL_API int fnDllTest(void)
{
	return printf("this fnDllTest() return (1) \n");
}
