#pragma once

namespace VertexEngine
{
	enum class RenderAPI
	{
		None = 0,
		OpenGL = 1,
		// Vulkan = 2,
		// DirectX11 = 3,
		// DirectX12 = 4
	};

	class GraphicsContext
	{
	public:
		static std::unique_ptr<GraphicsContext> Create(RenderAPI api);
		virtual ~GraphicsContext() = default;
		virtual void Init() = 0;
	};
}
