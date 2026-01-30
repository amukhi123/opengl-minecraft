#include "gfx/shader.h"
#include "gfx/shader_program.h"
#define GLAD_GL_IMPLEMENTATION 1

#include <cstdlib>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "util/logger.h"
#include "gfx/renderer.h"

Renderer::Renderer() : m_Window {800, 800}, m_Vbo {}, m_Ebo {}, m_Vao {}, m_ShaderProgram {}
{
}

void Renderer::Init()
{
    glfwInit();
    
    m_Window.Init();
    
    if (!gladLoadGL(reinterpret_cast<GLADloadfunc>(glfwGetProcAddress)))
    {
        Logger::GetInstance()->Log("Failed to pass GLAD function to load OpenGL functions.", LogLevel::Error);
        
        exit(EXIT_FAILURE);
    }
    
    List<ShaderInfo> shadersInfo 
    {
        {"default.vs", ShaderType::Vertex},
        {"default.fs", ShaderType::Fragment}
    };
    
    m_ShaderProgram.Init(shadersInfo);
    
    m_Vao.Init();
    
    List<float> vertexData
    {
        -0.5f, -0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.5f, 0.5f, 0.0f
    };
    
    m_Vbo.Init(vertexData, BufferType::Vbo);
    
    List<uint32> indicies 
    {
        0, 1, 2,
        1, 2, 3
    };
    
    m_Ebo.Init(indicies, BufferType::Ebo);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);
    
    glViewport(0, 0, m_Window.GetWidth(), m_Window.GetHeight());
}

void Renderer::Run()
{
    // Magic value :(
    glClearColor(0.3f, 0.4f, 0.5f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    m_ShaderProgram.Use();
    
    m_Vao.Bind();
    
    // Magic value :(
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    
    glfwSwapBuffers(m_Window.GetWindow());
    glfwPollEvents();
}

void Renderer::Destroy()
{
    m_Window.Destroy();
    
    glfwTerminate();
}
