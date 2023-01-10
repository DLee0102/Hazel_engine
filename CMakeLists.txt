cmake_minimum_required(VERSION 3.10)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)


project(Hazel_engine)

add_definitions(-DHZ_PLATFORM_WINDOWS)
option(HZ_PLATFORM_WINDOWS "if on Windows" ON)
add_definitions(-DHZ_BUILD_DLL)
option(HZ_BUILD_DLL "if build dll" ON)
add_definitions(-DHZ_ENABEL_ASSERTS)
option(HZ_ENABEL_ASSERTS "if ENABEL_ASSERTS" ON)

add_subdirectory(Hazel)

add_subdirectory(Sandbox)


