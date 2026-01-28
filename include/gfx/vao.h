#pragma once

#include "util/types.h"

class Vao
{
public:
    void Init();
    
    void Bind() const;
private:
    uint32 m_Id;
};
