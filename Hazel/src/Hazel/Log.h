#pragma once

#include "Hazel/Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/fmt/ostr.h>    // spd的输出流运算，可以记录自定义类型

// 记录日志功能，详细用法见spdlog的github仓库

namespace Hazel {
    class HAZEL_API Log
    {
    public:
        static void Init();
        
        // 知识点：智能指针、设计模式
        inline static std::shared_ptr<spdlog::logger> GetCoreLogger() {return s_CoreLogger;}
        inline static std::shared_ptr<spdlog::logger> GetClientLogger() {return s_ClientLogger;}

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

//使用宏来简化后续调用函数的代码
// Core log macros
#define HZ_CORE_TRACE(...)   ::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)    //__VA_ARGS__表示可变参数列表
#define HZ_CORE_INFO(...)    ::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)    ::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)   ::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...)   ::Hazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define HZ_TRACE(...)  ::Hazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...)   ::Hazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)   ::Hazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...)  ::Hazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_FATAL(...)  ::Hazel::Log::GetClientLogger()->fatal(__VA_ARGS__)