# JniTest-AndroidMk-2016-09-22
Android.mk文件的编写-jni包含多个源文件和源文件文件夹

1-前言
==================
引用地址：
原创
	
2-实验目的：
=============
Android.mk文件的编写-jni包含多个源文件和源文件文件夹
3-开发工具：
=============
Notepad++
android-ndk-r8b

4-工程目录：
=============
		JniTest
			│  Android.mk
			│  
			├─jni
			│  │  Android.mk
			│  │  glapi_crc.c
			│  │  
			│  ├─external
			│  │      Platform.c
			│  │      
			│  ├─include
			│  │      glapi_crc.h
			│  │      
			│  ├─lua
			│  │      lapi.c
			│  │      lapi.h
			│  │      lauxlib.c
			│  │      lauxlib.h
			│  │      lbaselib.c
			│  │      lcode.c
			│  │      lcode.h
			│  │      ldblib.c
			│  │      ldebug.c
			│  │      ldebug.h
			│  │      ldo.c
			│  │      ldo.h
			│  │      ldump.c
			│  │      lfunc.c
			│  │      lfunc.h
			│  │      lgc.c
			│  │      lgc.h
			│  │      linit.c
			│  │      liolib.c
			│  │      llex.c
			│  │      llex.h
			│  │      llimits.h
			│  │      lmathlib.c
			│  │      lmem.c
			│  │      lmem.h
			│  │      loadlib.c
			│  │      lobject.c
			│  │      lobject.h
			│  │      lopcodes.c
			│  │      lopcodes.h
			│  │      loslib.c
			│  │      lparser.c
			│  │      lparser.h
			│  │      lstate.c
			│  │      lstate.h
			│  │      lstring.c
			│  │      lstring.h
			│  │      lstrlib.c
			│  │      ltable.c
			│  │      ltable.h
			│  │      ltablib.c
			│  │      ltm.c
			│  │      ltm.h
			│  │      lua.h
			│  │      luaconf.h
			│  │      lualib.h
			│  │      lundump.c
			│  │      lundump.h
			│  │      lvm.c
			│  │      lvm.h
			│  │      lzio.c
			│  │      lzio.h
			│  │      
			│  └─luajava
			│          Android.mk
			│          luajava.c
			
5-编译与运行结果：
==============
CMD窗口：
			C:\Users\tom\Desktop\JniTest>ndk-build
			"Compile thumb : my_jni <= lapi.c
			"Compile thumb : my_jni <= lauxlib.c
			"Compile thumb : my_jni <= lbaselib.c
			"Compile thumb : my_jni <= lcode.c
			"Compile thumb : my_jni <= ldblib.c
			"Compile thumb : my_jni <= ldebug.c
			"Compile thumb : my_jni <= ldo.c
			"Compile thumb : my_jni <= ldump.c
			"Compile thumb : my_jni <= lfunc.c
			"Compile thumb : my_jni <= lgc.c
			"Compile thumb : my_jni <= linit.c
			"Compile thumb : my_jni <= liolib.c
			"Compile thumb : my_jni <= llex.c
			"Compile thumb : my_jni <= lmathlib.c
			"Compile thumb : my_jni <= lmem.c
			"Compile thumb : my_jni <= loadlib.c
			"Compile thumb : my_jni <= lobject.c
			"Compile thumb : my_jni <= lopcodes.c
			"Compile thumb : my_jni <= loslib.c
			"Compile thumb : my_jni <= lparser.c
			"Compile thumb : my_jni <= lstate.c
			"Compile thumb : my_jni <= lstring.c
			"Compile thumb : my_jni <= lstrlib.c
			"Compile thumb : my_jni <= ltable.c
			"Compile thumb : my_jni <= ltablib.c
			"Compile thumb : my_jni <= ltm.c
			"Compile thumb : my_jni <= lundump.c
			"Compile thumb : my_jni <= lvm.c
			"Compile thumb : my_jni <= lzio.c
			"Compile thumb : my_jni <= Platform.c
			SharedLibrary  : libmy_jni.so
			Install        : libmy_jni.so => libs/armeabi/libmy_jni.so //<--目标文件--JniTest/libs/armeabi/libmy_jni.so


