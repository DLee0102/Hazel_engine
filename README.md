# Hazel_engine

油管博主TheCHerno的游戏引擎开发系列--我的学习记录





### 知识点

- Cmake工具链构建项目
  - Cmake 一般先find_package / find_library 再链接
  - 部分官方库文件链接后无需target_include_directories
  - 预编译头文件target_precompile_headers
  - GLFW的cmake文件有bug，build后还需要cmake --install . 才能生成所需glfw3Targets.cmake文件，同时须修改cmake_install.cmake的安装路径到项目下
  - Vscode上的Cmake插件可选择编译对象（add_subdirectories情况下）
  - .c 和 .cpp文件混合编译会造成混乱无法通过build
  - 类重写ToString()和<<的作用（类似java）
- 可以将客户端的主函数写入到服务端，使代码更加模块化
- 设计模式的思想
- 宏的巧妙用法可以使代码更简洁，运行速度更快
- shared_ptr / unique_ptr
- functional包装
- 构造函数的简便写法
- 结构体亦可用构造函数初始化
- 预编译头文件可以减少编译时间
- nullptr等价于NULL，但nullptr更先进, Destroys the specified window and its context.

