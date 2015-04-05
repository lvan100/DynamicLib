LOCAL_PATH := $(call my-dir)
$(warning $(LOCAL_PATH))

include $(CLEAR_VARS)

LOCAL_MODULE := DynamicLib

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../../src

LOCAL_SRC_FILES := ../../../DynamicLib.cpp

LOCAL_LDLIBS := -lz -llog

include $(BUILD_EXECUTABLE)
