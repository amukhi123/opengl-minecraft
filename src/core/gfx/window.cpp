#include "core/gfx/window.h"

#include <cstdlib>
#include <GLFW/glfw3.h>

#include "util/logger.h"

Window::Window(const int Width, const int Height) : m_Width {Width}, m_Height {Height}
{
}

void Window::Init()
{
    constexpr int OPEN_GL_MAJOR_VERSION {3};
    constexpr int OPEN_GL_MINOR_VERSION {3};
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPEN_GL_MAJOR_VERSION);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPEN_GL_MINOR_VERSION);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    m_Window = glfwCreateWindow(m_Height, m_Width, "OpenGL Minecraft", nullptr, nullptr);
    
    if (!m_Window)
    {
        Logger::GetInstance()->Log("Failed to create GLFW window", LogLevel::Error);
        
        glfwTerminate();
        
        exit(EXIT_FAILURE);
    }
    
    glfwMakeContextCurrent(m_Window);
}

void Window::Destroy()
{
    
}
