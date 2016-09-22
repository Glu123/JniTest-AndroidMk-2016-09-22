LOCAL_PATH:= $(call my-dir)#获取当前路径
$(warning "8888======== $(LOCAL_PATH)")#print
include $(CLEAR_VARS)
LOCAL_CERTIFICATE := platform

LOCAL_JNI_SHARED_LIBRARIES := my_jni#编译成的jni库的名字
LOCAL_REQUIRED_MODULES := my_jni

include $(wildcard $(LOCAL_PATH)/jni/Android.mk)#根据编译规则，将相应的jni源文件编译成jni库文件
