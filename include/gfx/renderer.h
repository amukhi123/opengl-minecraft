#pragma once

#include "engine/engine_system.h"

#include "gfx/window.h"
#include "gfx/vao.h"
#include "gfx/shader_program.h"
#include "gfx/buffer_object.h"

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
    
    BufferObject m_Vbo;
    
    Vao m_Vao;
    
    BufferObject m_Ebo;
    
    ShaderProgram m_ShaderProgram;
};
