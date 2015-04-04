#ifdef WIN32
#define DLL_API __declspec(dllexport)
#else
#define DLL_API
#endif

extern "C" DLL_API int fnDllTest(void)
{
	return 2;
}
