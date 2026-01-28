#include <GLFW/glfw3.h>

#include "engine/input_manager.h"

#include "gfx/window.h"

void InputManager::Update(Window* Window)
{
    if (glfwGetKey(Window->GetWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        Window->SetShouldCloseWindow(true);
    }
}
