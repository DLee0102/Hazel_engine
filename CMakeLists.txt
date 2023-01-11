# Hazel_engine's CMakeLists.txt 作者(Author)：丁利(Lee)
# 四川大学软件学院(Software Engineering College of Sichuan University)

cmake_minimum_required(VERSION 3.10)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# project(Hazel_engine CXX C) # 编译Glad库时使用
project(Hazel_engine CXX)

# 设置预编译的宏
# 是否在Windows平台下编译
add_definitions(-DHZ_PLATFORM_WINDOWS)
option(HZ_PLATFORM_WINDOWS "if on Windows" ON)
# 是否构建Hazel动态库文件
add_definitions(-DHZ_BUILD_DLL)
option(HZ_BUILD_DLL "if build dll" ON)
# 是否添加Assertion（断言）功能--发行版本可删除此宏
add_definitions(-DHZ_ENABEL_ASSERTS)
option(HZ_ENABEL_ASSERTS "if ENABEL_ASSERTS" ON)

add_subdirectory(Hazel)

add_subdirectory(Sandbox)


