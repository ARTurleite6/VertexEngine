#include "GraphicsContext.h"

#include "VertexEngine/Platform/OpenGL/GLContext.h"

namespace VertexEngine
{
	std::unique_ptr<GraphicsContext> GraphicsContext::Create(RenderAPI api [[maybe_unused]])
	{
		return std::make_unique<GLContext>();
	}
}
