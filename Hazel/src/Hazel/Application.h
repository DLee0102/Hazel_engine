#pragma once

#include "Hazel/Core.h"
#include "Hazel/Events/Event.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Events/MouseEvent.h"
#include "Hazel/LayerStack.h"
#include "Window.h"


namespace Hazel {
    class HAZEL_API Application
    {
    public:
        Application();
        virtual ~Application();
        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline static Application& Get() { return *s_Instance; }
        inline Window& GetWindow() { return *m_Window; }
    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;   // 独占式的，某一时刻只能有一个unique_ptr指向指定的对象。其他性质和shared_ptr相同
        bool m_Running = true;
        LayerStack m_LayerStack;
    private:
        static Application* s_Instance;
    };
    // To be defined in CLIENT
    Application* CreateApplication();
}