#include "Application.h"

#include <glad/glad.h>


namespace Hazel {

// 静态成员函数其实可以看做是全局函数，而非静态成员函数则需要传递this指针作为第一个参数，所以std::bind能很容易地绑定成员函数
// 包装器和bind? std::bind()返回std::function的对象
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application* Application::s_Instance = nullptr;

    Application::Application()
    {
        // 确保只有一个application实例
        HZ_CORE_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;

        m_Window = std::unique_ptr<Window>(Window::Create());

        // std::bind onEvent与SetEventCallback的参数EventCallbackFn &callback进行绑定
        // EventCallbackFn是一个function包装器，接受一个Event&类型参数，返回值为空
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
    }

    Application::~Application()
    {
    }


    void Application::PushLayer(Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer* layer)
    {
        m_LayerStack.PushOverlay(layer);
        layer->OnAttach();
    }

    void Application::OnEvent(Event& e)
    {
        // 接收到的事件为e
        EventDispatcher dispatcher(e);
        // 判断接收到的事件是否被调度为窗口关闭事件
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

        HZ_CORE_TRACE("{0}", e);

        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
        {
            (*--it)->OnEvent(e);
            if (e.Handled) {
                break;
            }
        }
    }

    void Application::Run()
    {

        while(m_Running)
        {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            // 轮询处理，WindowsWindow.cpp中定义了GLFW特定事件处理函数的声明后硬件操作会触发相应函数产生待处理时间
            
            for (Layer* layer : m_LayerStack)
            {
                layer->OnUpdate();
            }
            
            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;
        return true;
    }
}