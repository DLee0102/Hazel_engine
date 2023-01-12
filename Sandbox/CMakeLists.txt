# 找到Hazel动态库文件
find_library(libvar_own Hazel ${CMAKE_BINARY_DIR}/lib)

# 找到spdlog库
if(NOT TARGET spdlog)
  # Stand-alone build
  set(spdlog_DIR ${PROJECT_SOURCE_DIR}/Hazel/vendor/spdlog/build)
  find_package(spdlog REQUIRED)
endif()

# 找到glfw3库
set(glfw3_DIR ${PROJECT_SOURCE_DIR}/Hazel/vendor/GLFW/build/lib/cmake/glfw3)
find_package(glfw3 3.3 REQUIRED)

# 找到系统中的OpenGL库(Windows系统编译OpenGL所必须)
find_package(OpenGL REQUIRED)
# message(${OPENGL_LIBRARIES})

# 找到Glad库
find_library(GLAD_LIBRARIES Glad ${CMAKE_BINARY_DIR}/lib REQUIRED)

# 构建可执行文件
add_executable(Sandbox ./src/SandboxApp.cpp)

#链接找到的所需的库文件
target_link_libraries(Sandbox PUBLIC ${libvar_own} spdlog::spdlog glfw ${OPENGL_LIBRARIES} ${GLAD_LIBRARIES})

# 预编译固定的头文件
target_precompile_headers(Sandbox PUBLIC ${PROJECT_SOURCE_DIR}/Hazel/hzpch.h)

#添加所需头文件
# ???由于spdlog和glfw在链接时将头文件直接链接到了库里面，所以这里不用显示调用target_include_directories
target_include_directories(Sandbox PUBLIC
                           ${PROJECT_SOURCE_DIR}/Hazel/src
                           ${PROJECT_SOURCE_DIR}/Hazel
                           ${PROJECT_SOURCE_DIR}/Hazel/vendor/Glad/include
                           )


                           
# 关于 target_precompile_headers
# 支持预编译头文件 (#1260) · 问题 · CMake / CMake ,模块将在 C++20 中出现，但它们需要一段时间才能被工具广泛采用、
# 优化和支持——我们能做些什么正确预编译头文件可以通过创建一些头文件的部分处理版本，然后在 CMake 3.16 增加了对
# 预编译头文件和统一构建的支持有一个名为“Cotire”的第三方 CMake 模块，它自动为基于 CMake 的构建系统使用预编译头文件
# ，并且头文件列表用于生成名为 cmake_pch.h|xx 的头文件，用于生成预编译的头文件（.pch、.gch、.pchi）工件。
# cmake_pch.h|xx 头文件将被强制包含（-include 用于 GCC，/FI 用于 MSVC）到所有源文件，因此源不需要
# 具有#include "pch.h"。