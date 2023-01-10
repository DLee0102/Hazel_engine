#pragma once

#include "Hazel/Core.h"
#include "Hazel/Events/Event.h"
#include "Window.h"


namespace Hazel {
    class HAZEL_API Application
    {
    public:
        Application();
        virtual ~Application();
        void Run();
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };
    // To be defined in CLIENT
    Application* CreateApplication();
}