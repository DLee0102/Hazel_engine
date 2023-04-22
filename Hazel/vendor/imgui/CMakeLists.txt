# 手动编译源文件

add_library(ImGui STATIC 
        ./imconfig.h
        ./imgui.h
        ./imgui.cpp
        ./imgui_draw.cpp
        ./imgui_internal.h
        ./imgui_tables.cpp
        ./imgui_widgets.cpp
        ./imstb_rectpack.h
        ./imstb_textedit.h
        ./imstb_truetype.h
        ./imgui_demo.cpp
        )

target_include_directories(ImGui PUBLIC
                         ${PROJECT_SOURCE_DIR}/Hazel/vendor/imgui
                           )