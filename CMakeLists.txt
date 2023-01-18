# Hazel_engine's CMakeLists.txt 作者(Author)：丁利(github: DLee0102)
# 四川大学软件学院(Software Engineering College of Sichuan University)

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


