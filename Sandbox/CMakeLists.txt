
find_library(libvar_own Hazel ${CMAKE_BINARY_DIR}/lib)

if(NOT TARGET spdlog)
  # Stand-alone build
  set(spdlog_DIR ${PROJECT_SOURCE_DIR}/Hazel/vendor/spdlog/build)
  find_package(spdlog REQUIRED)
endif()

set(glfw3_DIR ${PROJECT_SOURCE_DIR}/Hazel/vendor/GLFW/build/lib/cmake/glfw3)
find_package(glfw3 3.3 REQUIRED)

add_executable(Sandbox ./src/SandboxApp.cpp)

target_link_libraries(Sandbox PUBLIC ${libvar_own} spdlog::spdlog glfw)

target_precompile_headers(Sandbox PUBLIC ${PROJECT_SOURCE_DIR}/Hazel/hzpch.h)
         
target_include_directories(Sandbox PUBLIC
                           ${PROJECT_SOURCE_DIR}/Hazel/src
                           ${PROJECT_SOURCE_DIR}/Hazel
                           )

find_package(OpenGL REQUIRED)
