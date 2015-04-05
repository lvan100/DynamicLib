APP_STL = system
LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog
LOCAL_C_INCLUDES := $(ANDROID_NDK_HOME)/sources/cxx-stl/system/include