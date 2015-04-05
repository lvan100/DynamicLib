APP_STL = gabi++_shared
LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog $(ANDROID_NDK_HOME)/sources/cxx-stl/gabi++/libs/armeabi/libgabi++_shared.so
LOCAL_C_INCLUDES := $(ANDROID_NDK_HOME)/sources/cxx-stl/gabi++/include