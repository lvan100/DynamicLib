APP_STL = gnustl_static
LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog $(ANDROID_NDK_HOME)/sources/cxx-stl/gnu-libstdc++/4.8/libs/armeabi/libgnustl_static.a
LOCAL_C_INCLUDES := $(ANDROID_NDK_HOME)/sources/cxx-stl/gnu-libstdc++/4.8/include