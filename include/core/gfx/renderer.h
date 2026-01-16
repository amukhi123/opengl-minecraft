#pragma once

#include "core/engine/engine_system.h"

#include "core/gfx/window.h"

class Renderer : public EngineSystem
{
public:
    Renderer();

void Init() override;
    
    void Render();
    
    void Destroy() override;
private:
    Window m_Window;
};