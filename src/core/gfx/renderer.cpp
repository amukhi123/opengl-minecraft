#include "core/gfx/renderer.h"

#include "util/logger.h"

#include <cstdlib>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

Renderer::Renderer() : m_Window {800, 800}
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
    
    glViewport(0, 0, m_Window.GetWidth(), m_Window.GetHeight());
}

void Renderer::Run()
{
    glClearColor(0.3f, 0.4f, 0.5f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glfwSwapBuffers(m_Window.GetWindow());
    glfwPollEvents();
}

void Renderer::Destroy()
{
    m_Window.Destroy();
    
    glfwTerminate();
}
