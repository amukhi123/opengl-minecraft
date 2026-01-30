#pragma once

#include "util/types.h"

enum class ShaderType : uint8
{
    Vertex = 0,
    Fragment,
};

struct ShaderInfo
{
    String fileName;
    ShaderType shaderType;
};

class Shader
{
public:
    void Compile(const String& FileName, const ShaderType ShaderType);
    
    uint32 GetId() const
    {
        return m_Id;
    }
private:
    uint32 m_Id;
    
    void Create(const ShaderType ShaderType);
    
    String ReadFile(const String& FileName);
};
