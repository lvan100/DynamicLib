APP_STL = c++_static
LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog $(ANDROID_NDK_HOME)/sources/cxx-stl/llvm-libc++/libs/armeabi/libc++_static.a
LOCAL_C_INCLUDES := $(ANDROID_NDK_HOME)/sources/cxx-stl/llvm-libc++/libcxx/include