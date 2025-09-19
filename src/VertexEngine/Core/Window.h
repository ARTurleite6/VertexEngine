#pragma once

#include "VertexEngine/Graphics/RHI/GraphicsContext.h"

namespace VertexEngine
{
	struct WindowDesc final
	{
		std::string Title;
		std::uint32_t Width, Height;
		RenderAPI Api;

		explicit WindowDesc(const std::string& title = "Vertex Engine",
			std::uint32_t width = 1280,
			std::uint32_t height = 720,
			RenderAPI api = RenderAPI::OpenGL)
			: Title{title}
			, Width{width}
			, Height{height}
			, Api{api}
		{
		}
	};

	class Event;

	class Window
	{
	public:
		using EventCallback = std::function<void(Event&)>;
		static std::unique_ptr<Window> Create(const WindowDesc& desc = WindowDesc{});
		virtual ~Window() = default;

		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void ProcessEvents() = 0;
		virtual void SetEventCallback(const EventCallback& callback) = 0;
	};
}
