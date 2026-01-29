#define GLAD_GL_IMPLEMENTATION 1

#include <cstdlib>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "util/logger.h"
#include "gfx/renderer.h"

Renderer::Renderer() : m_Window {800, 800}, m_Vbo {}, m_Vao {}, m_ShaderProgram {}
{
}

void Renderer::Init()
{
    glfwInit();
    
    m_Window.Init();
    
    List<float> verticies 
    {
        0.f, 0.f, 0.0f,
        -0.5f, 0.f, 0.0f,
        -0.25f, 0.5f, 0.0f,
        0.f, 0.f, 0.0f,
        0.25f, 0.5f, 0.0f,
        0.5f, 0.f, 0.0f
    };
    
    if (!gladLoadGL(reinterpret_cast<GLADloadfunc>(glfwGetProcAddress)))
    {
        Logger::GetInstance()->Log("Failed to pass GLAD function to load OpenGL functions.", LogLevel::Error);
        
        exit(EXIT_FAILURE);
    }
    
    m_ShaderProgram.Init();
    
    m_Vao.Init();
    
    m_Vbo.Init(verticies, BufferType::Vbo);
    
    // Magic value :(
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
    glDrawArrays(GL_TRIANGLES, 0, 6);
    
    glfwSwapBuffers(m_Window.GetWindow());
    glfwPollEvents();
}

void Renderer::Destroy()
{
    m_Window.Destroy();
    
    glfwTerminate();
}
