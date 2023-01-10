#pragma once

#include "Hazel/Core.h"
#include "Hazel/Events/Event.h"
#include <GLFW/glfw3.h>


namespace Hazel {
    class HAZEL_API Application
    {
    public:
        Application();
        virtual ~Application();
        void Run();

    };
    // To be defined in CLIENT
    Application* CreateApplication();
}