#include "Window.h"

#include "VertexEngine/Platform/GLFW/GLFWWindow.h"

namespace VertexEngine
{
	std::unique_ptr<Window> Window::Create(const WindowDesc& desc)
	{
		return std::make_unique<GLFWWindow>(desc);
	}
}
