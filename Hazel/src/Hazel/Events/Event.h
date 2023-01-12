#pragma once

#include "Hazel/Core.h"


namespace Hazel {
    // Events in Hazel are currently blocking, meaning when an event occurs it 
    // immediately gets dispatched and must be dealt with right then and there.
    // For the future, a better strategy might be to buffer events in an event
    // bus and process them during the "event" part of the update stage.

    enum class EventType
    {
        // 事件类型
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved, 
        AppTick, AppUpdate, AppRender, 
        KeyPressed, KeyReleased, 
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory
    {
        // 最好使用空格隔开
        None = 0,
        EventCategoryApplication   = BIT(0),
        EventCategoryInput         = BIT(1),
        EventCategoryKeyboard      = BIT(2),
        EventCategoryMouse         = BIT(3),
        EventCategoryMouseButton   = BIT(4)
    };

// #可将type转换为字符串
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() {return EventType::type; }\
                                virtual EventType GetEventType() const override { return GetStaticType(); }\
                                virtual const char* GetName() const override { return #type;}

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

    // Event类的基类
    class HAZEL_API Event
    {
        // 友元：允许非成员函数函数访问私有数据
        friend class EventDispatcher;
    public:
        // const修饰成员函数作用：该函数不能修改对象的成员变量
        // = 0 含义：纯虚函数，无函数体
        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const {return GetName(); }

        inline bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;     // 返回 0 则说明不属于category类
        }
    protected:
        bool m_Handled = false;
    };

    class EventDispatcher
    {
        template<typename T>
        using EventFn = std::function<bool(T&)>;    // 包装器：接受一个T&类型的参数，并返回bool类型的参数
    public:
        // 构造函数中给类变量赋值
        EventDispatcher(Event& event)
            : m_Event(event)
        {
        }

        template<typename T>
        bool Dispatch(EventFn<T> func)
        {
            if (m_Event.GetEventType() == T::GetStaticType())
            {
                m_Event.m_Handled = func(*(T*)&m_Event);
                return true;
            }
            return false;
        }
    private:
        Event& m_Event;
    };
    // 重写 << 运算符，使其能被 cout<< 输出，方便打印日志信息
    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }

}

