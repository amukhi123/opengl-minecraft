#pragma once

#include "util/types.h"

enum class BufferType : uint32
{
    Vbo = 0,
    Ebo,
};

class BufferObject
{
public:
    void Init(List<float> Data, const BufferType BufferType)
    {
        InitHelper(Data.data(), sizeof(float) * Data.size(), BufferType);
    }
    
    void Init(List<uint32> Data, const BufferType BufferType)
    {
        InitHelper(Data.data(), sizeof(uint32) * Data.size(), BufferType);
    }
private:
    uint32 m_Id;
    
    void InitHelper(void* Data, const SizeT Size, const BufferType BufferType);
};
