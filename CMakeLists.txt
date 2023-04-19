# Hazel_engine's CMakeLists.txt 作者(Author)：丁利(github: DLee0102)
# 四川大学软件学院(Software Engineering College of Sichuan University)

# 关于多编译器混合编译的说明：
# 首先，不同编译器编译的包处于同于项目中可能会报错
# 其次，由于系统默认编译器路径和cmake配置中使用的编译器不同，可能导致最后生成的exe文件在运行时找不到程序入口
# 原因就是exe文件找不到libstdc++-6.dll这个动态库文件（默认通过系统环境变量路径找dll，所以如果默认编译器和build用的
# 编译器不一样，就会运行时报错），像QT这种使用自带编译器的库解决办法是将我们build所用的编译器的libstdc++-6.dll贴到
# 和exe文件同级目录下。若遇到其他编译器冲突的问题，也可以采用这种解决思路

# 由于Windows下不同的编译器会链接不同的运行时库（.dll），如果不清楚到底最终发布程序时应该复制哪些库
# 则应该观察调试时调试控制台的gdb的加载信息。（也可以采用静态编译解决该问题）

cmake_minimum_required(VERSION 3.10)


# 条件判断
if(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
    add_compile_definitions(HZ_DEBUG)
elseif(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Release"))
    add_compile_definitions(HZ_RELEASE)
else(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Dist"))
    add_compile_definitions(HZ_DIST)
endif()

set(CMAKE_CXX_STANDARD 11)
# Linux和Windows平台参数定义不同, 要注意区分
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# project(Hazel_engine CXX C) # 编译Glad库时使用
project(Hazel_engine CXX)

# 设置预编译的宏
# 是否在Windows平台下编译
add_compile_definitions(HZ_PLATFORM_WINDOWS)
# option(HZ_PLATFORM_WINDOWS "if on Windows" ON)    // 旧版用add_definition需要此句

# # 是否构建Hazel动态库文件
# add_compile_definitions(HZ_BUILD_DLL)
# option(HZ_BUILD_DLL "if build dll" ON)

# 是否添加Assertion（断言）功能--发行版本可删除此宏
add_compile_definitions(HZ_ENABEL_ASSERTS)
# option(HZ_ENABEL_ASSERTS "if ENABEL_ASSERTS" ON)

add_subdirectory(Hazel)

add_subdirectory(Sandbox)


