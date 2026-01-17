#include <GLFW/glfw3.h>

#include "core/engine/engine.h"

UniquePtr<Engine> Engine::ms_Instance {nullptr};

Engine* Engine::GetInstance()
{
    if (!ms_Instance)
    {
        ms_Instance = UniquePtr<Engine>(new Engine());
    }
    
    return ms_Instance.get();
}

void Engine::Init()
{
    m_Renderer.Init();
}

void Engine::Run()
{
    while (!glfwWindowShouldClose(m_Renderer.GetWindowPtr()))
    {
        m_InputManager.Update(m_Renderer.GetWindow());
        m_Renderer.Run();
    }
}

void Engine::Destroy()
{
    m_Renderer.Destroy();
}
