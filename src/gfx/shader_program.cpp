#include <cstdlib>
#include <glad/gl.h>

#include "gfx/shader_program.h"

#include "gfx/shader.h"
#include "util/logger.h"

void ShaderProgram::Init(const List<ShaderInfo>& ShadersInfo)
{
    m_Id = glCreateProgram();
    
    for (const ShaderInfo& shaderInfo : ShadersInfo)
    {
        if (shaderInfo.shaderType == ShaderType::Vertex)
        {
            m_VertexShader.Compile(shaderInfo.fileName, ShaderType::Vertex);
        }
        else if (shaderInfo.shaderType == ShaderType::Fragment)
        {
            m_FragmentShader.Compile(shaderInfo.fileName, ShaderType::Fragment);
        }
        else 
        {
            Logger::GetInstance()->Log("Unknown shader type.", LogLevel::Error);
            exit(EXIT_FAILURE);
        }
    }
    
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