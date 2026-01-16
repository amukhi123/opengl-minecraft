#pragma once

#include "core/engine/engine_system.h"

class GLFWwindow;

class Window : public EngineSystem
{
public:
    Window(const int Width, const int Height);

    void Init() override;
    
    void Destroy() override;
    
    GLFWwindow* GetWindow() const
    {
        return m_Window;
    }
    
    int GetHeight() const
    {
        return m_Height;
    }
    
    int GetWidth() const
    {
        return m_Width;
    }
private:
    GLFWwindow* m_Window;
    
    int m_Width;
    int m_Height;
};