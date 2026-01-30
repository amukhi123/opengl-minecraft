#pragma once

#include "util/types.h"

class Vao
{
public:
    void Init();
    
    void Bind() const;
    
    void UnBind() const;
private:
    uint32 m_Id;
};
