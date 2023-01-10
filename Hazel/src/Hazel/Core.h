#pragma once

// declspec(dllexport)和declspec(dllimport)用于精确构建和调用dll文件

#ifdef HZ_PLATFORM_WINDOWS
    #ifdef HZ_BUILD_DLL
        #define HAZEL_API __declspec(dllexport)
    #else
        #define HAZEL_API __declspec(dllimport)
    #endif
#else
    #error Hazel only support Windows!
#endif

#define BIT(x) (1 << x)
