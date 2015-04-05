LOCAL_PATH := $(call my-dir)
$(warning $(LOCAL_PATH))

include $(CLEAR_VARS)

LOCAL_MODULE := DllTestTwo

LOCAL_SRC_FILES := ../../../DllTestTwo.cpp

include $(BUILD_SHARED_LIBRARY)
