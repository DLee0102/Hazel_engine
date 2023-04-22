#pragma once

#include "Hazel/Core.h"
#include "Hazel/Events/Event.h"

// Hazel和窗口界面的接口
namespace Hazel {

    struct WindowProps
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;
        // 构造函数初始化
        WindowProps(const std::string& title = "Hazel Engine", 
                    unsigned int width = 1200, 
                    unsigned int height = 720)
            : Title(title), Width(width), Height(height)
        {
        }    
    };

    // Interface representing a desktop system based Window
    class HAZEL_API Window
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() {}

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        // Window attributes
        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;
        // 设置为静态的原因：我们只希望用到一个实例来创建所有窗口
        static Window* Create(const WindowProps& props = WindowProps());
    };
    
}