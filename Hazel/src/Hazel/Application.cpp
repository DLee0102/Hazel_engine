#include "Application.h"

#include "Hazel/Events/MouseEvent.h"
#include "Hazel/Log.h"

namespace Hazel {
    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        MouseMovedEvent e(1, 2);
        if (e.IsInCategory(EventCategoryApplication)) {
            HZ_TRACE(e);
        }
        if (e.IsInCategory(EventCategoryInput)) {
            HZ_TRACE(e);
        }

        std::cout << e.GetCategoryFlags() << std::endl;

        while(true);
        while(true);
    }
}