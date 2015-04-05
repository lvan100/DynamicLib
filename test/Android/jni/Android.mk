LOCAL_PATH := $(call my-dir)
$(warning $(LOCAL_PATH))

include $(call all-makefiles-under,$(LOCAL_PATH))