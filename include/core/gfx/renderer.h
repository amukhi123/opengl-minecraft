#pragma once

#include "core/engine/engine_system.h"

#include "core/gfx/window.h"

class Renderer : public EngineSystem
{
public:
    Renderer();

    void Init() override;
    
    void Run() override;
    
    void Destroy() override;
    
    Window* GetWindow()
    {
        return &m_Window;
    } 
    
    GLFWwindow* GetWindowPtr() const
    {
        return m_Window.GetWindow();
    }
private:
    Window m_Window;
};
