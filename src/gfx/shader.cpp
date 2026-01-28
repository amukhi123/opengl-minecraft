#include <glad/gl.h>
#include <cstdlib>
#include <fstream>
#include <filesystem>

#include "gfx/shader.h"

#include "util/logger.h"
#include "util/types.h"

void Shader::Compile(const String& FileName, const ShaderType ShaderType)
{
    String shaderSource {ReadFile(FileName)};
    
    const char* shaderSourcePtr {shaderSource.c_str()};
    
    if (shaderSource.empty())
    {
        Logger::GetInstance()->Log("Failed to compile shader. The pointer to the source code was empty!", LogLevel::Error);
        
        exit(EXIT_FAILURE);
    }
    
    Create(ShaderType);
    
    glShaderSource(m_Id, 1, &shaderSourcePtr, nullptr);
    glCompileShader(m_Id);
    
    int compliationSuccess {};
    
    glGetShaderiv(m_Id, GL_COMPILE_STATUS, &compliationSuccess);
    
    if (!compliationSuccess)
    {
        char log[Logger::kMaxLogSize];
        
        glGetShaderInfoLog(m_Id, Logger::kMaxLogSize, nullptr, log);
        
        Logger::GetInstance()->Log(log, LogLevel::Error);
        
        exit(EXIT_SUCCESS);
    }
}

void Shader::Create(const ShaderType ShaderType)
{
    uint32 shaderTypeAsInt {};
    
    switch (ShaderType)
    {
        case ShaderType::Fragment:
            shaderTypeAsInt = GL_FRAGMENT_SHADER;
            break;
        case ShaderType::Vertex:
        default:
            shaderTypeAsInt = GL_VERTEX_SHADER;
            break;
    }
    
    m_Id = glCreateShader(shaderTypeAsInt);
}

String Shader::ReadFile(const String& FileName)
{
    const std::filesystem::path shaderFilePath {std::filesystem::current_path().parent_path().string() + "\\res\\shaders\\" + FileName};
    
    std::ifstream shaderFile {shaderFilePath};
    
    String fileContent {""};
    
    if (shaderFile.is_open())
    {
        String line {""};
        
        while (std::getline(shaderFile, line))
        {
            fileContent.append(line + "\n");
        }
        
        shaderFile.close();
    }
    else
    {
        Logger::GetInstance()->Log("Failed to load " + FileName + ", at path " + shaderFilePath.string() + ".", LogLevel::Error);
    }
    
    return fileContent;
}
