# 手动编译Glad的 .c源文件

add_library(Glad STATIC ./src/glad.c)

target_include_directories(Glad PUBLIC
                         ${PROJECT_SOURCE_DIR}/Hazel/vendor/Glad/include
                           )