#include <cstdlib>
#include <glad/gl.h>

#include "gfx/buffer_object.h"

#include "util/logger.h"

void BufferObject::InitHelper(void* Data, const SizeT Size, const BufferType BufferType)
{
    glGenBuffers(1, &m_Id);

    int bufferType {0};
    
    switch (BufferType)
    {
    case BufferType::Ebo:
        bufferType = GL_ELEMENT_ARRAY_BUFFER;
        break;
    case BufferType::Vbo:
        bufferType = GL_ARRAY_BUFFER;
        break;
    default:
        Logger::GetInstance()->Log("Unknown buffer type.",  LogLevel::Error);
        exit(EXIT_FAILURE);
    };
    
	glBindBuffer(bufferType, m_Id);
    glBufferData(bufferType, Size, Data, GL_STATIC_DRAW);
}
