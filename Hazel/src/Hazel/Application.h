#pragma once

#include "Hazel/Core.h"
#include "Hazel/Events/Event.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Window.h"


namespace Hazel {
    class HAZEL_API Application
    {
    public:
        Application();
        virtual ~Application();
        void Run();

        void OnEvent(Event& e);
    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;   // 独占式的，某一时刻只能有一个unique_ptr指向指定的对象
        bool m_Running = true;
    };
    // To be defined in CLIENT
    Application* CreateApplication();
}