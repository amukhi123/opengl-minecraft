#define GLAD_GL_IMPLEMENTATION 1

#include <cstdlib>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "util/logger.h"
#include "gfx/renderer.h"

Renderer::Renderer() : m_Window {800, 800}, m_VboOne {}, m_VboTwo {}, m_VaoOne {}, m_VaoTwo {}, m_ShaderProgram {}
{
}

void Renderer::Init()
{
    glfwInit();
    
    m_Window.Init();
    
    List<float> vertexDataOne
    {
        0.f, 0.f, 0.0f,
        -0.5f, 0.f, 0.0f,
        -0.25f, 0.5f, 0.0f
    };
    
    List<float> vertexDataTwo
    {
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
    
    m_VaoOne.Init();
    
    m_VboOne.Init(vertexDataOne, BufferType::Vbo);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);
    
    m_VaoTwo.Init();
    
    m_VboTwo.Init(vertexDataTwo, BufferType::Vbo);
    
    // Magic value :(
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);
    
    m_VaoTwo.UnBind();
    
    glViewport(0, 0, m_Window.GetWidth(), m_Window.GetHeight());
}

void Renderer::Run()
{
    // Magic value :(
    glClearColor(0.3f, 0.4f, 0.5f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    m_ShaderProgram.Use();
    
    m_VaoOne.Bind();
    
    // Magic value :(
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    m_VaoTwo.Bind();
    
    // Magic value :(
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    glfwSwapBuffers(m_Window.GetWindow());
    glfwPollEvents();
}

void Renderer::Destroy()
{
    m_Window.Destroy();
    
    glfwTerminate();
}
