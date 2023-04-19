#pragma once

#include "Hazel/Core.h"
#include "Hazel/Events/Event.h"

namespace Hazel {

    class HAZEL_API Layer
    {
    public:
        // 调试版的Layer才有名称，发行版要取消名称
        Layer(const std::string& name = "Layer");
        virtual ~Layer();

        // 打开
        virtual void OnAttach() {}
        // 关闭
        virtual void OnDetach() {}
        // 调用时每帧更新
        virtual void OnUpdate() {}
        // 接收事件
        virtual void OnEvent(Event& event) {}

        inline const std::string& GetName() const { return m_DebugName; }
    protected:
        std::string m_DebugName;
    };
}