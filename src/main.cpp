#include "core/engine/engine.h"
#include "util/logger.h"

int main()
{
    Engine* engine {Engine::GetInstance()};
    
    if (engine)
    {
        engine->Init();
        
        engine->Run();
        
        engine->Destroy();
    }
    else 
    {
        Logger::GetInstance()->Log("Failed to create Engine! Exiting...", LogLevel::Error);
    }
}
