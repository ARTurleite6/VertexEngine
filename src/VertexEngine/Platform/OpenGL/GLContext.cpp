#include "GLContext.h"

namespace VertexEngine
{
	void GLContext::Init()
	{
		VE_CORE_INFO("Initialized OpenGL context");
		VE_CORE_INFO("OpenGL Info:");
		VE_CORE_INFO("  Vendor: {0}", reinterpret_cast<const char*>(glGetString(GL_VENDOR)));
		VE_CORE_INFO("  Renderer: {0}", reinterpret_cast<const char*>(glGetString(GL_RENDERER)));
		VE_CORE_INFO("  Version: {0}", reinterpret_cast<const char*>(glGetString(GL_VERSION)));
	}
}
