#include <glad/gl.h>

#include "gfx/shader_program.h"

#include "util/logger.h"

void ShaderProgram::Init()
{
    m_Id = glCreateProgram();
    
    m_VertexShader.Compile("default.vs", ShaderType::Vertex);
    m_FragmentShader.Compile("default.fs", ShaderType::Fragment);
    
    glAttachShader(m_Id, m_VertexShader.GetId());
    glAttachShader(m_Id, m_FragmentShader.GetId());
 
    Link();
    
    Use();
    
    glDeleteShader(m_VertexShader.GetId());
    glDeleteShader(m_FragmentShader.GetId());
}

void ShaderProgram::Use() const
{
    glUseProgram(m_Id);
}

void ShaderProgram::Link()
{
    glLinkProgram(m_Id);
    
    int linkSuccess {0};
    
    glGetProgramiv(m_Id, GL_LINK_STATUS, &linkSuccess);
    
    if (!linkSuccess)
    {
        char log[Logger::kMaxLogSize];
        
        glGetShaderInfoLog(m_Id, Logger::kMaxLogSize, nullptr, log);
        
        Logger::GetInstance()->Log(log, LogLevel::Error);
        
        exit(EXIT_SUCCESS);
    }
}