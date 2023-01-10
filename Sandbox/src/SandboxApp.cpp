#include "Hazel.h"  

  
// 客户端继承引擎的主要类以构建客户端模型

class Sandbox : public Hazel::Application
{
public:
    Sandbox()
    {

    }

    ~Sandbox()
    {

    }


};

Hazel::Application* Hazel::CreateApplication()
{
    return new Sandbox();
}


// #include <stdio.h>
// int main()
// {
// }