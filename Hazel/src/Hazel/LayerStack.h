#pragma once

#include "Hazel/Core.h"
#include "Layer.h"

#include <vector>

namespace Hazel {

    class HAZEL_API LayerStack
    {
    public:
        LayerStack();
        ~LayerStack();

        void PushLayer(Layer*layer);
        void PushOverlay(Layer* overlay);
        void PopLayer(Layer* layer);
        void PopOverlay(Layer* overlay);

        std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
        std::vector<Layer*>::iterator end() { return m_Layers.end(); }
    private:
        std::vector<Layer*> m_Layers;
        // 用于区分layer和overlayer：overlayer用指针插入，而指针初始化为头部，因此
        // layer永远都插入到vector的前半段，而overlayer永远都只是插入到后半段
        // 这样做是因为overlayer永远都只被最后处理
        std::vector<Layer*>::iterator m_LayerInsert;
    };
}