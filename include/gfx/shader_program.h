#pragma once

#include "gfx/shader.h"

#include "util/types.h"

class ShaderProgram
{
public:
    void Init(const List<ShaderInfo>& ShadersInfo);

    void Use() const;
private:
    uint32 m_Id;

    Shader m_VertexShader;
    Shader m_FragmentShader;
    
    void Link();
};
