#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "VertexEngine/Core/Window.h"
#include "VertexEngine/Graphics/RHI/GraphicsContext.h"

namespace VertexEngine
{
	class GLFWWindow final : public Window
	{
	public:
		explicit GLFWWindow(const WindowDesc& desc);
		~GLFWWindow() override;

		void Init() override;
		void OnUpdate() override;
		void ProcessEvents() override;
		void SetEventCallback(const EventCallback& callback) override;

	private:
		struct WindowData final
		{
			std::string Title;
			std::uint32_t Width, Height;
			EventCallback OnEvent;
			RenderAPI Api;
		};

		static bool s_GLFWInitialized;
		static std::uint32_t s_WindowCount;

		GLFWwindow* m_Handle;
		WindowData m_Data;
		std::unique_ptr<GraphicsContext> m_Context;
	};
}
