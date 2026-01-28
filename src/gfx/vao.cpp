#include <glad/gl.h>

#include "gfx/vao.h"

void Vao::Init()
{
    glGenVertexArrays(1, &m_Id);

    Bind();
}

void Vao::Bind() const
{
    glBindVertexArray(m_Id);
}
