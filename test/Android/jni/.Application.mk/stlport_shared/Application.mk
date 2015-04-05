APP_STL = stlport_shared
LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog $(ANDROID_NDK_HOME)/sources/cxx-stl/stlport/libs/armeabi/libstlport_shared.so
LOCAL_C_INCLUDES := $(ANDROID_NDK_HOME)/sources/cxx-stl/stlport/stlport
