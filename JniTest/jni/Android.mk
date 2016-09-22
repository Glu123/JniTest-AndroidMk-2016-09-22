
LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/lua \
    $(LOCAL_PATH)/include

LOCAL_SRC_FILES += glapi_crc.c

LOCAL_SRC_FILES := lua/lapi.c \
		lua/lauxlib.c \
		lua/lbaselib.c \
		lua/lcode.c \
		lua/ldblib.c \
		lua/ldebug.c \
		lua/ldo.c \
		lua/ldump.c \
		lua/lfunc.c \
		lua/lgc.c \
		lua/linit.c \
		lua/liolib.c \
		lua/llex.c \
		lua/lmathlib.c \
		lua/lmem.c \
		lua/loadlib.c \
		lua/lobject.c \
		lua/lopcodes.c \
		lua/loslib.c \
		lua/lparser.c \
		lua/lstate.c \
		lua/lstring.c \
		lua/lstrlib.c \
		lua/ltable.c \
		lua/ltablib.c \
		lua/ltm.c \
		lua/lundump.c \
		lua/lvm.c \
		lua/lzio.c

LOCAL_SHARED_LIBRARIES := \
  liblog \
	libandroid_runtime \
	libnativehelper \
    libcutils \
    libutils \
    libbinder \
    libgui \
	libskia \
	libGLESv2 \
	libui \
	libdl


#ifeq ($(PROJECT_MODEL),abc)#条件编译
	PLATFORM_SRC_FILES += \
		external/Platform.c
	LOCAL_C_INCLUDES += $(LOCAL_PATH)/external
#endif

LOCAL_SRC_FILES += $(PLATFORM_SRC_FILES)

LOCAL_MODULE	:= my_jni

include $(BUILD_SHARED_LIBRARY)



