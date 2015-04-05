LOCAL_PATH := $(call my-dir)
$(warning $(LOCAL_PATH))

include $(CLEAR_VARS)

LOCAL_MODULE := DllTestOne

LOCAL_SRC_FILES := ../../../DllTestOne.cpp

include $(BUILD_SHARED_LIBRARY)
