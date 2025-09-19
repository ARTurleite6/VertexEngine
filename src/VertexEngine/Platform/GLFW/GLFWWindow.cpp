#include "GLFWWindow.h"

#include "VertexEngine/Events/ApplicationEvent.h"

namespace VertexEngine
{
	static void GLFWErrorCallback(int error, const char* description)
	{
		VE_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	bool GLFWWindow::s_GLFWInitialized{false};
	std::uint32_t GLFWWindow::s_WindowCount{0};

	GLFWWindow::GLFWWindow(const WindowDesc& desc)
		: m_Data{
			  .Title = desc.Title,
			  .Width = desc.Width,
			  .Height = desc.Height,
			  .OnEvent = nullptr,
			  .Api = desc.Api}
	{
	}

	GLFWWindow::~GLFWWindow()
	{
		if(!m_Handle)
			return;
		glfwDestroyWindow(m_Handle);

		s_WindowCount--;
		if(s_WindowCount == 0)
		{
			glfwTerminate();
			s_GLFWInitialized = false;
		}
	}

	void GLFWWindow::Init()
	{
		VE_CORE_INFO("Creating window {0} ({1}, {2})", m_Data.Title, m_Data.Width, m_Data.Height);
		if(!s_GLFWInitialized)
		{
			glfwInit();
			glfwSetErrorCallback(GLFWErrorCallback);

			s_GLFWInitialized = true;
		}

		if(m_Data.Api == RenderAPI::OpenGL)
		{
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		}
		m_Handle = glfwCreateWindow(static_cast<int>(m_Data.Width), static_cast<int>(m_Data.Height), m_Data.Title.c_str(), nullptr, nullptr);

		if(m_Data.Api == RenderAPI::OpenGL)
		{
			glfwMakeContextCurrent(m_Handle);

			if(!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
			{
				VE_CORE_ERROR("Failed to initialise OpenGL context");
			}
		}

		glfwSetWindowUserPointer(m_Handle, &m_Data);
		glfwSetWindowCloseCallback(m_Handle, [](GLFWwindow* window) {
			WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
			if(data.OnEvent)
			{
				WindowCloseEvent event{};
				data.OnEvent(event);
			}
		});

		m_Context = GraphicsContext::Create(m_Data.Api);
		m_Context->Init();
	}

	void
	GLFWWindow::OnUpdate()
	{
		// TODO: verify that we are at OpenGL
		glfwSwapBuffers(m_Handle);
	}

	void GLFWWindow::ProcessEvents()
	{
		glfwPollEvents();
	}

	void GLFWWindow::SetEventCallback(const EventCallback& callback)
	{
		m_Data.OnEvent = callback;
	}
}
