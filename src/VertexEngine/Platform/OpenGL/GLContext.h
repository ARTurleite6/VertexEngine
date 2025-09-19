#pragma once

#include <glad/glad.h>

#include "VertexEngine/Graphics/RHI/GraphicsContext.h"

namespace VertexEngine
{
	class GLContext final : public GraphicsContext
	{
		void Init() override;
	};
}
