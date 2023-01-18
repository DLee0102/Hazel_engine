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
- Lamda函数
- 函数指针
  - 允许将函数指针作为参数列表的函数调用传入的函数指针的函数，即允许部分内容由调用者自定义
  - 可以传入Lamda函数
  - 注意：(*函数名)和函数名表达的意思相同
- C++ public private protected 说明：
  1. 这些关键字只是在编译之后起作用，即是说，无论是否被关键字修饰，所有成员都会被编译，这解释了get...()函数可以在子类中正常运作的原理（父类中相应的成员是私有的）。
  2. 各关键字具体解释：
     - public: 无特别
     - private: 被修饰的成员只能被当前类的实例访问（包括父类子类都不可访问）
     - protected: 被修饰的成员只能被子类的实例访问

