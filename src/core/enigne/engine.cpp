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
    m_Renderer.Render();
}

void Engine::Destroy()
{
    m_Renderer.Destroy();
}
