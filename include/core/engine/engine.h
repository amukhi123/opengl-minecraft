#pragma once

#include "util/types.h"
#include "core/gfx/renderer.h"

class Engine
{
public:
    Engine(const Engine& EngineToCopy) = delete;
    Engine& operator=(const Engine& EngineToCopy) = delete;

    static Engine* GetInstance();

    void Init();
    void Run();
    void Destroy();
private:
    static UniquePtr<Engine> ms_Instance;
    
    Renderer m_Renderer;

    Engine() = default;
};
