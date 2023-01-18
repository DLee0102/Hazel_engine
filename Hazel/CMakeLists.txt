# set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
# set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
# set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# 构建Glad库时所需
# add_subdirectory(vendor/Glad)

# MinGW 调试和发布时不需要添加链接Runtime library的任何规则（比如/MDd, /MD等），Runtime Library是MSVC的特色

# 找到spdlog库
if(NOT TARGET spdlog)
  # Stand-alone build
  set(spdlog_DIR ${PROJECT_SOURCE_DIR}/Hazel/vendor/spdlog/build)
  find_package(spdlog REQUIRED)
endif()

# 找到glfw3库
# GLFW的cmake文件有bug，build后还需要cmake --install . 才能生成所需glfw3Targets.cmake文件，同时须修改cmake_install.cmake的安装路径到项目下 
set(glfw3_DIR ${PROJECT_SOURCE_DIR}/Hazel/vendor/GLFW/build/lib/cmake/glfw3)
find_package(glfw3 3.3 REQUIRED)

# 找到系统中的OpenGL库(Windows系统编译OpenGL所必须)
find_package(OpenGL REQUIRED)
# message("Hazel.dll链接到"${spdlog_DIR} " " ${OsPENGL_LIBRARIES} " " ${glfw3_DIR} " " ${GLAD_LIBRARIES})

# 找到Glad库
find_library(GLAD_LIBRARIES Glad ${CMAKE_BINARY_DIR}/lib REQUIRED)

# 构建Hazel动态库文件
add_library(Hazel SHARED ./src/Hazel/Application.cpp ./src/Hazel/Log.cpp ./src/Platform/WindowsWindow.cpp ./src/Hazel/LayerStack.cpp ./src/Hazel/Layer.cpp)

# 添加预编译的宏(是否构建dll文件)：经过验证，此种写法能有效只为Hazel预编译宏定义，与PUBLIC和PRIVATE无关
target_compile_definitions(Hazel PRIVATE -DHZ_BUILD_DLL)

# 预编译固定的头文件
target_precompile_headers(Hazel PUBLIC ./hzpch.h)   # dll和exe文件的cmakelists都要加这句

#链接找到的所需的库文件
# ???由于spdlog和glfw在链接时将头文件直接链接到了库里面，所以这里不用显示调用target_include_directories
target_link_libraries(Hazel PUBLIC spdlog::spdlog glfw ${OPENGL_LIBRARIES} ${GLAD_LIBRARIES})  # spdlog按官方教程这个库若用编译版本则照此写法不需要target_include_directories

#添加所需头文件
target_include_directories(Hazel PUBLIC
                         ${PROJECT_SOURCE_DIR}/Hazel/src
                         ${PROJECT_SOURCE_DIR}/Hazel/vendor/Glad/include
                           )


                           
# 关于 target_precompile_headers
# 支持预编译头文件 (#1260) · 问题 · CMake / CMake ,模块将在 C++20 中出现，但它们需要一段时间才能被工具广泛采用、
# 优化和支持——我们能做些什么正确预编译头文件可以通过创建一些头文件的部分处理版本，然后在 CMake 3.16 增加了对
# 预编译头文件和统一构建的支持有一个名为“Cotire”的第三方 CMake 模块，它自动为基于 CMake 的构建系统使用预编译头文件
# ，并且头文件列表用于生成名为 cmake_pch.h|xx 的头文件，用于生成预编译的头文件（.pch、.gch、.pchi）工件。
# cmake_pch.h|xx 头文件将被强制包含（-include 用于 GCC，/FI 用于 MSVC）到所有源文件，因此源不需要
# 具有#include "pch.h"。
