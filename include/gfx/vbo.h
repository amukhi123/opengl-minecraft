#pragma once

#include "util/types.h"

class Vbo
{
public:
    void Init();
    
    void CopyDataToBuffer(const List<float>& Data);
private:
    uint32 m_Id;
};
