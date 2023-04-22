// 替代dllimport
#include "Hazel.h"  

class ExampleLayer : public Hazel::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {
    }

    void OnUpdate() override
    {
        HZ_INFO("ExampleLayer::Update");
    }

    void OnEvent(Hazel::Event& event) override
    {
        HZ_TRACE("{0}", event);
    }
};

  
// 客户端继承引擎的主要类以构建客户端模型
class Sandbox : public Hazel::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
        PushOverlay(new Hazel::ImGuiLayer());
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