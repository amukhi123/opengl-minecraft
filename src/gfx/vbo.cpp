#include "glad/gl.h"

#include "gfx/vbo.h"

void Vbo::Init()
{
    glGenBuffers(1, &m_Id);
    
    glBindBuffer(GL_ARRAY_BUFFER, m_Id);
}

void Vbo::CopyDataToBuffer(const List<float>& Data)
{
    glBufferData(GL_ARRAY_BUFFER, Data.size() * sizeof(float), Data.data(), GL_STATIC_DRAW);
}
