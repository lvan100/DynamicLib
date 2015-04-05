APP_STL = c++_shared
LIBCXX_FORCE_REBUILD := false
LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog $(ANDROID_NDK_HOME)/sources/cxx-stl/llvm-libc++/libs/armeabi/libc++_shared.so
LOCAL_C_INCLUDES := $(ANDROID_NDK_HOME)/sources/cxx-stl/llvm-libc++/libcxx/include