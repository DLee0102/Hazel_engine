#pragma once

// 将客户端的主函数写入到服务端，使代码更加模块化

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{   
    Hazel::Log::Init();
    HZ_CORE_WARN("Initialized Log!");

    auto app = Hazel::CreateApplication();
    app->Run();
    delete app;
}
#endif