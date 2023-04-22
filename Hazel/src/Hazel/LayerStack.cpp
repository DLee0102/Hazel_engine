#include "LayerStack.h"

namespace Hazel {

    LayerStack::LayerStack()
    {
        m_LayerInsert = m_Layers.begin();
    }

    LayerStack::~LayerStack()
    {
        // 此处删除layer的内存，而不是在pop时删除，因为我们在poplayer时可能还不希望删除被pop的layer
        // 被pop的layer其lifetime由该layer自身来决定
        for (Layer* layer : m_Layers)
            delete layer;
    }

    // 压入Layer
    void LayerStack::PushLayer(Layer* layer)
    {
        m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
    }

    // overlayer和layer的区别：overlayer的push和pop不需要改变指针
    void LayerStack::PushOverlay(Layer* overlay)
    {
        m_Layers.emplace_back(overlay);
    }

    // 弹出Layer
    void LayerStack::PopLayer(Layer* layer)
    {
        auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
        if (it != m_Layers.end())
        {
            // 由于m_layer存储的是一个指针，而erase只会在m_layer中删除指定的指针，而不会删除指针指向的内存
            // 要删除指定的内存，详见析构函数
            m_Layers.erase(it);
            m_LayerInsert--;
        }
    }

    void LayerStack::PopOverlay(Layer* overlay)
    {
        auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
        if (it != m_Layers.end())
        {
            m_Layers.erase(it);
        }
    }
}